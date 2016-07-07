//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%% Funcion para generar código a partir de %%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% una mag ya definida %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <stdio.h> 
#include <string.h> 
#include "cadenas.h"
#include "genera.h"

#define CONCATENA dimCTmp = strlen(cadenaTmp);\
      dimCod+=dimCTmp;\
      if(dimCod >= dimMR)\
      {\
        dimMR+= BLOQUE_MEM_RUTINA;\
        codigo= realloc(codigo,dimMR);\
      }\
      strcat(codigo,cadenaTmp)
#define CONCATENA_Tab  dimCTmp= strlen(rutina);\
          dimCod+=dimCTmp;\
          if(dimCod >= dimMR){\
            dimMR+= BLOQUE_MEM_RUTINA* (((dimCod-dimMR)/ BLOQUE_MEM_RUTINA) + 1);\
            codigo= realloc(codigo,dimMR);\
          }\
          strcat(codigo,rutina)
#define GET_JKB  c= *(cadena+iCd);\
          iCd++
#define PUT_JKB  *(cadRes+iCdR)= c;\
          iCdR++;\
          *(cadRes+iCdR)= 0;
//Tabuladores hechos con espacios en blanco
extern JKE espaciosTab; // Por defecto son 2

JKES cuentaTabs(const JKB* cadena){
  JKES numTab=0; //Número de tabuladores
  JKES numEsp=0; //Número de espacios
  JKES numTabMin= 100;
  JKE iCd=0;//Indice sobre la cadena
  JKB c;
  GET_JKB;
  JKE debug= 0;
  while(c!= 0  )
  {
    if(c == ' ')
    {
      numEsp ++;
      
      if(numEsp == espaciosTab)
      {
        numEsp=0;
        numTab++;
        
      }
    } else if ( c == '\t')
    {
      numEsp=0;
      numTab++;
    } else {
      numEsp=0;
      if( c != '\n')
      {
        numTabMin = numTab < numTabMin ? numTab: numTabMin;
        numTab=0;
        GET_JKB;        
        while( c!= 0 && c != '\n'  )
        {
          GET_JKB;          
        }
        
        ;
      } else {//Para no contar tabuladores en renglones vacios
        numTab=0;
      }
    }
    if(c==0)
    break;
    GET_JKB;
    
  }
  if(numTabMin == 100)
  return -1;
  return numTabMin;
}

//Modifica un número de tabulaciones dado por tabsEl.
//Si es positivo agrega tabulaciones,
//Si es cero elimina las tabulaciones mínimas
JKB* modificaTabs(const JKB* cadena, JKES tabsEl)
{
  JKB* cadRes= 0;
  JKES numTab=0; //Número de tabuladores
  JKES numEsp=0; //Número de espacios
  JKES dimCadena= strlen(cadena)+1;
  JKE iCd=0;//Indice sobre la cadena
  JKE iCdR=0; //Indice sobre la cadena resultante.
  JKB c;
  //Elimina las tabulaciones mínimas
  if(tabsEl==0 )
  {
    JKES numeroTabs = cuentaTabs(cadena);
    //printf("Numero tabs: %i\n",numeroTabs);   
    cadRes = malloc((dimCadena) * sizeof(JKB));
    if(numeroTabs <= 0)
      strcpy(cadRes,cadena);
    else 
    {
      GET_JKB;
      while(c != 0)
      {
        if(numEsp == espaciosTab)
        {
          numEsp=0;
          numTab++;
        }
        if(c == ' ')
        {
          numEsp ++;
          
        } else if ( c == '\t')
        {
          numEsp=0;
          numTab++;
        } else if (c == '\n')
        {
          numEsp=0;
          numTab=0;
        } else
        {
          numEsp=0;
          numTab=0;
          PUT_JKB; 
          GET_JKB;
          while( c!= 0 && c != '\n'  )
          {
            PUT_JKB; 
            GET_JKB;          
          };
        }
        if(numTab>=numeroTabs || c== '\n' )
        {
          PUT_JKB;
        }
        if(c==0)
          break;
        GET_JKB;
      }
      PUT_JKB;
    }
    //printf("cadena nueva (%i):\n%s\n",iCd, cadRes);
    return cadRes;
  }
  //Agrega tabulaciones
  if(tabsEl > 0)
  {
    JKES numLin;
    JKES i;
    JKES espaciosAgregados = espaciosTab*tabsEl;
    JKB* cadenaTabs = malloc((espaciosAgregados+1) * sizeof(JKB));
    //Inicializa la cadena que corresponde a las tabulaciones a agregar
    //en cada linea
    
    for(i=0;i<espaciosAgregados;i++)
    {
      *(cadenaTabs+i)= ' ';
    }
    *(cadenaTabs+espaciosAgregados)=0;
    for(i=0;i<dimCadena;i++)
    {
      GET_JKB;
      if(c== '\n')
        numLin++;      
    }
    iCd=0;
    cadRes = malloc((dimCadena+numLin*espaciosAgregados) * sizeof(JKB));
   
    *cadRes=0;
    strcat(cadRes,cadenaTabs);
    
    iCdR+=espaciosAgregados;
    for(i=0;i<dimCadena;i++)
    {
      GET_JKB;
      PUT_JKB;
      if(c== '\n' && i< dimCadena-2 )//menos 2 para evitar poner sangria luego del último salto de linea
      {
        strcat(cadRes,cadenaTabs);
        iCdR+=espaciosAgregados;
      }             
    }
    //printf("cadena original (%i):\n%s\n",iCd, cadena);
    //printf("cadena nueva (%i):\n%s\n",iCdR, cadRes);
    return cadRes;
  }
  return cadRes;
}

JKB* concatenaCadenas (const VL_CODIAC* cadenas)
{
  JKB* cadRes=0;
  JKB* rutina=0;
  JKES dimencion= 0;
  JKES i;
  for(i=0; i< cadenas->dim;i++)
  {
    rutina = (*(cadenas->rutinaI + i))->valor.cadena;//
    dimencion+= strlen(rutina);
  } 
  dimencion++; //Para el terminador cero.
  cadRes = malloc(dimencion * sizeof(JKB));
  *cadRes = (JKB) 0;
  //Concatena
  for(i=0; i< cadenas->dim;i++)
  {
    rutina = (*(cadenas->rutinaI + i))->valor.cadena;//
    strcat(cadRes,rutina);
  } 
  return cadRes;
}
