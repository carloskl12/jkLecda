//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%% Funcion para generar código a partir de %%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% una mag ya definida %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//***Errores aún no identificados claramente:
// 1- Funcion generaCodigo: El problema de liberar memoria al usar realloc con 
//    el puntero codigo, aparentemente se cruzan las asignaciones de memoria
//    , se solucionó dejando la asignación de memoria para codigo* de última
#include <stdio.h> 
#include <string.h> 
#include "genera.h"

#define CONCATENA dimCTmp = strlen(cadenaTmp);\
      dimCod+=dimCTmp;\
      if(dimCod >= dimMR)\
      {\
        dimMR+= BLOQUE_MEM_RUTINA;\
        codigo= realloc(codigo,dimMR);\
      }\
      strcat(codigo,cadenaTmp)
#define CONCATENA_RUTINA  dimCTmp= strlen(rutina);\
          dimCod+=dimCTmp;\
          if(dimCod >= dimMR){\
            dimMR+= BLOQUE_MEM_RUTINA* (((dimCod-dimMR)/ BLOQUE_MEM_RUTINA) + 1);\
            codigo= realloc(codigo,dimMR);\
          }\
          strcat(codigo,rutina)

//Tabuladores hechos con espacios en blanco
extern JKE espaciosTab; // Por defecto son 2

//Funcion que analiza una mag en cuanto a que:
//  * Las entradas respecto a las salidas corresponden 
//    a una relacion de función.
JKES analizaMag(JK_ID *variable, JKB tpAnalisis)
{
  VL_MAG *mag = variable->valor.mag;
  VL_CODIAC *codiac;
  JKB *matriz = mag->elementos;
  JKB valorE;//valor de un elemento
  JKB valorMxE; //Valor máximo del elemento
  //Vector donde se almacena una secuencia de entrada temporalmente
  JKB *secIn = malloc(mag->nIn * sizeof(JKB));
  //Vector donde se almacena las secuencias verificadas
  JKB *vecIn = malloc(mag->dim * sizeof(JKB));
  
  JKES i,j,k,n;
  //printf("\n*Inicia análisis sobre la mag %s\n", variable->id);
  
  //printf("Dimension de la mag: %i\n", mag->dim);
  //printf("\tEntradas: %i\n\tSalidas: %i\n", mag->nIn,mag->nOut);
  
  //Analiza que los punteros no sean cero
  for(i=0;i<mag->nIn;i++)
    if(*(mag->codiI+i)==0)
    {
      printf("No se ha definido el codi %i\n",i+1);
      return -1;
    }
  for(i=0;i<mag->nOut;i++)
    if(*(mag->codiacI+i)==0)
    {
      printf("No se ha definido el codiac %i\n",i+1);
      return -1;
    }
  
  //Analiza si los elementos de la secuencia de entrada
  //hacen referencia a indices validos
  
  for(i=0;i< mag->dim ; i++)
    for(j=0; j < (mag->nIn + mag->nOut) ; j++)
    {
      valorE = *( matriz+ j+ i*(mag->nIn + mag->nOut) );
      //printf("Valor elemento: %i\n", valorE);
      
      if(j< mag->nIn)
      {
        valorMxE = ( (VL_CODI*)( (*(mag->codiI+j) )->valor.codi ) )-> valorMax;
      } else
      {
        valorMxE = ( (VL_CODIAC*)((*(mag->codiacI+j- mag->nIn))->valor.codiac ) )
                  -> dim;        
      }
      
      if(valorE >= valorMxE)
      {
        printf("El número %i excede el valor máximo %i, en la columna %i.",valorE, (valorMxE-1),j);
        return (-1);
      }
    }
  
  
  //Analiza si las entradas y salidas corresponden a una funcion
  for(i=0;i< mag->dim - 1; i++)
  {
    //Asigna la secuencia a comparar
    for(j=0;j<mag->nIn;j++)
      *(secIn+j)= *(matriz+j+i*mag->nIn);
    for(j=i+1;j < mag->dim ;j++)
    {
      n=0;
      for(k=0;k<mag->nIn;k++)
        if( *(secIn+k)== *(matriz+k+j*mag->nIn) )
          n++;
      if(n == mag->nIn)
      {
        //Se hallo una coincidencia de entradas, por ello no puede ser una
        // función, a menos que las filas sean totalmente equivalentes
        printf("La secuencia de entrada %i es igual a la %i.",i,j);
        return (-1);
      }
    }
  }
  //printf("Análisis correcto\n");
  return 0;
}

JKB* generaCodigo(JK_ID *variable, JKB modoGen)
{
  VL_MAG *mag = variable->valor.mag;
  VL_CODIAC *codiac;
  VL_CODI *codi;
  JKB *matriz = mag->elementos;
  JKB *cadenaTmp = malloc(BLOQUE_MEM_RUTINA * sizeof(JKB));
  JKB *cadenaTmp2 = malloc(BLOQUE_MEM_RUTINA * sizeof(JKB));
  JKB *tabulador = malloc((espaciosTab+1) * sizeof(JKB));//cadena de espacios
  JKB *codigo = malloc(BLOQUE_MEM_RUTINA * sizeof(JKB));//El que se redimensionará se deja de último

  
  JKB *rutina;
  
  JKB valorE;//valor de un elemento
  JKES dimCod = 0; //Dimension de la cadena de codigo
  JKES dimMR = BLOQUE_MEM_RUTINA; //dimension de la memoria reservada
  JKES dimCTmp=0;
  
  JKES i,j;
  
  for(i=0;i<espaciosTab;i++)
    *(tabulador+i)=' ';
  *(tabulador+espaciosTab)= (JKB) 0;
  //printf("*****************************el tabulador: %s\n", tabulador);
  //printf("Modo de generacion %s.\n", modoGen);
  if(modoGen == MODO_GEN_SWITCH)
  {
    //printf("Entra al modo switch\n");
    if(mag->nIn==1)
    {
      //Como solo es una variable de entrada, las ramificaciones solo
      //dependen de una variable, cuyo nombre sera el nombre del codi
      sprintf(cadenaTmp,"\nswitch(%s)\n{\n", (*(mag->codiI))->id );
      CONCATENA;
      
      for(i=0;i< mag->dim; i++)
      {
        sprintf(cadenaTmp,"%scase %i:\n",tabulador,*( i*(mag->nIn+mag->nOut) +matriz )  );
        CONCATENA;

        for(j=0;j< mag->nOut;j++)
        {
          valorE = *( matriz+j+mag->nIn+ i*(mag->nIn+mag->nOut) );
          codiac = (*(mag->codiacI+j))->valor.codiac;
          if(valorE >= codiac->dim)
          {
            printf("El índice %i no es válido para %s.", valorE , 
            ( *(mag->codiacI+j) )->id);
            return (0);
          }

          rutina = modificaTabs((*(codiac->rutinaI+valorE) )->valor.rutina, 2);//
          
          //pruebas********************error en realloc un puntero
          //diferente tambien apunta a la porcion de memoria original
          CONCATENA_RUTINA;
          free(rutina);
        }
        sprintf(cadenaTmp,"%s%sbreak;\n\n",tabulador,tabulador );
        CONCATENA;
      }
      sprintf(cadenaTmp,"%sdefault:\n%s%sprintf(\"Accion por defecto\");\n}\n",
      tabulador, tabulador, tabulador );
      CONCATENA;
      return codigo;
    }
    //En caso de la cantidad de variables de entrada es mas de una.
    //Se debe crear una variable auxiliar,
    //(prefijo vla_ seguido del nombre de la mag)
    sprintf(cadenaTmp,"\nint vla_%s= %s ", variable->id, (*(mag->codiI))->id );
    CONCATENA;
    codi = (*(mag->codiI))->valor.codi;
    
    //Contenedor de factores
    JKE *fConversion = malloc((mag->nIn) * sizeof(JKE));
    JKE inCmp ; //Entrada comprimida
    
    //Variable que acumulara el factor en cada cifra
    sprintf(cadenaTmp2,"%i", (JKE) codi->valorMax );
    fConversion[0]=1;
    for(i=1;i < mag->nIn; i ++ )
    {
      fConversion[i]=((JKE) codi->valorMax)*fConversion[i-1];
      codi = (*(mag->codiI+i))->valor.codi;
      
      sprintf(cadenaTmp,"+ %s * %s ", (*(mag->codiI+i))->id ,cadenaTmp2);
      CONCATENA;
      sprintf(cadenaTmp2,"%s * %i",cadenaTmp2, (JKE) codi->valorMax );
    }
    sprintf(cadenaTmp,";\n");
    CONCATENA;
    
    //Ya se tienen las entradas como una sola variable
    sprintf(cadenaTmp,"\nswitch(vla_%s)\n{\n",  variable->id );
    CONCATENA;
    
    
    for(i=0;i< mag->dim; i++)
    {
      inCmp=0;
      for(j=0;j<mag->nIn;j++)
      {
        valorE = *( matriz+j+ i*(mag->nIn+mag->nOut) );
        inCmp += valorE*fConversion[j];
        
      }
      sprintf(cadenaTmp,"%scase %i:\n",tabulador,inCmp  );
      CONCATENA;
      
      for(j=0;j< mag->nOut;j++)
      {
        valorE = *( matriz+j+mag->nIn+ i*(mag->nIn+mag->nOut) );
        codiac = (*(mag->codiacI+j))->valor.codiac;
        if(valorE >= codiac->dim)
        {
          printf("El índice %i no es válido para %s.", valorE , 
          ( *(mag->codiacI+j) )->id);
          return (0);
        }
        
        rutina = modificaTabs( (*(codiac->rutinaI+valorE) )->valor.rutina,2);
        CONCATENA_RUTINA;
        if(rutina != 0)
          free(rutina);
      }
      sprintf(cadenaTmp,"%sbreak;\n\n", tabulador );
      CONCATENA;
    }
    
    sprintf(cadenaTmp,"%sdefault:\n%s%sprintf(\"Accion por defecto\");\n}\n" ,
      tabulador, tabulador, tabulador );
    CONCATENA;
    return codigo;
  }
  return 0;
}
