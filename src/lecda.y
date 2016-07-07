%{
#include "lecda.h"


%}
/* Declaraciones de BISON */

%union {
  JKES entero;  //Valor entero de la variable (Codi unico o simple)
  JKES (*funcionRE)();  //Funcion que retorna numero entero
	JKB *cadena; //Puntero a cadena (Rutina)
  PVACIO codi;
  PVACIO codiac;
  PVACIO made;
  PVACIO mads;
  PVACIO mag;
  PVACIO rutina;
}

%token<entero> NUMERO_ENTERO    256
%token<entero> FIN_DE_FICHERO   257 
%token<entero> TOKEN_INVALIDO   258
%token<cadena> IDENTIFICADOR    259
%token<entero> COMENTARIO       260
%token<cadena> CODIGO_RUTINA    261
/*Palabras reservadas*/
%token<cadena> PR_CODI          500 
%token<cadena> PR_CODIAC        501
%token<cadena> PR_RUTINA        502
%token<cadena> PR_ESCRIBE       503
%token<cadena> PR_GENERA        504
%token<cadena> PR_MADE          505
%token<cadena> PR_MADS          506
%token<cadena> PR_MAG           507
%token<cadena> PR_SWITCH        508
%token<cadena> PR_IF            509
%token<cadena> PR_CONCATENA     510
/*Tipos de variables declaradas*/
%token<entero> VD_ENTERO        1000
%token<funcionRE> VD_FUNCION_RE 1001
%token<cadena> VD_CADENA        1002
%token<codi> VD_CODI            1003
%token<codiac> VD_CODIAC        1004
%token<made> VD_MADE            1005
%token<mads> VD_MADS            1006
%token<mag> VD_MAG              1007
%token<rutina> VD_RUTINA        1008

/*Valor de no terminales*/
%type <entero> sentencia
%type <entero> declaracionPura
%type <entero> tipoDeVar
%type <entero> idAsignado 
%type <entero> numeroEntero
%type <entero> asignacionPura
%type <entero> procedimientoSimple
%type <entero> modoGen
%type <mag> asignaMag
%type <entero> filasMag
%type <codi> valoresM
%type <entero> errorLexico
%type <cadena>tipoArchivo

%% 
/* A continuación las reglas gramaticales y las acciones */
/* Entradas recursivas por izquierda*/
input: /* vacío */
| input line
;

line:  '\n'
    | sentencia  {  }
    | FIN_DE_FICHERO    {printf("Fin del análisis.\n"); YYACCEPT;} 
    | errorLexico   
   
;

sentencia:  declaracionPura   ';' '\n' { $$ = DECLARACION_PURA;        }
            | asignacionPura      { $$ = ASIGNACION_PURA;         }
            | procedimientoSimple { $$ = PROCEDIMIENTO_SIMPLE;    }
            | errorLexico               
;

declaracionPura: PR_CODI IDENTIFICADOR '(' numeroEntero ')' 
                  { 
                    VL_CODI *vrTmp = malloc(sizeof (VL_CODI));
                    vrTmp->valorMax = $4 ;
                    agregaId( $2,  TPID_CODI, VALOR_SIN_INICIALIZAR);
                    //Inicializa el valor
                    tabla_Ids->valor.codi = vrTmp;      
                    //printf("Se ha declarado un Codi: %s\n", $2 );
                  }
               | PR_CODIAC IDENTIFICADOR '(' numeroEntero ')' 
                  {
                    VL_CODIAC *vrTmp = malloc(sizeof (VL_CODIAC));
                    vrTmp->dim= $4;
                    vrTmp->rutinaI = calloc( $4 , sizeof (JK_ID*) );
                    agregaId( $2,  TPID_CODIAC, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.codiac = vrTmp; 
                    printf("Se ha declarado un Codiac: %s\n", $2 );          
                  }
               | PR_RUTINA IDENTIFICADOR 
                  {
                    agregaId( $2,  TPID_RUTINA, VALOR_SIN_INICIALIZAR);
                    //printf("Se ha declarado una Rutina: %s\n", $2 );
                  }
               | PR_MADE IDENTIFICADOR '(' numeroEntero ')'  
                  { 
                    VL_MADE *vrTmp = malloc(sizeof (VL_MADE));
                    vrTmp->dim= $4;
                    vrTmp->codiI = calloc( $4 , sizeof (JK_ID*) );
                    agregaId( $2,  TPID_MADE, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.made = vrTmp; 
                    //printf("Se ha declarado una made: %s\n", $2 );
                  }
               | PR_MADS IDENTIFICADOR '(' numeroEntero ')'  
                  { 
                    VL_MADS *vrTmp = malloc(sizeof (VL_MADS));
                    vrTmp->dim= $4;
                    vrTmp->codiacI = calloc( $4 , sizeof (JK_ID*) );
                    agregaId( $2,  TPID_MADS, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.mads = vrTmp; 
                    //printf("Se ha declarado una mads: %s\n", $2 );
                  }
               | PR_MAG IDENTIFICADOR '(' numeroEntero ')' 
                  '(' VD_MADE ':' VD_MADS ')'  
                  {
                    JKES i;
                    VL_MAG *vrTmp = malloc(sizeof (VL_MAG));
                    VL_MADE *madeTmp = ((JK_ID *) $7)->valor.made;
                    VL_MADS *madsTmp = ((JK_ID *) $9)->valor.mads;
                    vrTmp->dim= $4;
                    vrTmp->nIn= madeTmp->dim;
                    vrTmp->nOut= madsTmp->dim;
                    vrTmp->codiI = calloc( vrTmp->nIn , sizeof (JK_ID*) );
                    for(i=0;i < vrTmp->nIn; i++)
                    {
                      *(vrTmp->codiI + i) = *(madeTmp->codiI + i);
                    }
                    
                    vrTmp->codiacI = calloc( vrTmp->nOut , sizeof (JK_ID*) );
                    for(i=0;i < vrTmp->nOut; i++)
                    {
                      *(vrTmp->codiacI + i) = *(madsTmp->codiacI + i);
                    }
                    vrTmp->elementos = calloc((vrTmp->nIn + vrTmp->nOut)* $4 , sizeof(JKB));
                    agregaId( $2,  TPID_MAG, VALOR_SIN_INICIALIZAR);
                    //Inicializa parcialmente el valor
                    tabla_Ids->valor.made = vrTmp; 
                    //printf("Se ha declarado una mag: %s\n", $2 );
                  }

                | tipoDeVar idAsignado  
                  {
                    //Error-001
                    varDeAsig = $2;
                    AVISO_LINEA_ERROR;
                    printf("\tEl nombre \"%s\" para la nueva variable ya se ha asignado."
                    , varDeAsig->id);
                    YYABORT;
                  }
;

/*Identificador asignado*/
idAsignado: VD_ENTERO       {$$ =  $1;  }
            |VD_FUNCION_RE  {$$ =  $1;  }
            |VD_CADENA      {$$ =  $1;  }
            |VD_CODI        {$$ =  $1;  }
            |VD_CODIAC      {$$ =  $1;  }
            |VD_MADE        {$$ =  $1;  }
            |VD_MADS        {$$ =  $1;  }
            |VD_MAG         {$$ =  $1;  }
            |VD_RUTINA      {$$ =  $1;  }
;
/*Tipo de variable */
tipoDeVar: PR_CODI    {$$ = TPDV_CODI;}
          |PR_CODIAC  {$$ = TPDV_CODIAC;}
          |PR_RUTINA  {$$ = TPDV_RUTINA;}
          |PR_MADE    {$$ = TPDV_MADE;}
          |PR_MADS    {$$ = TPDV_MADS;}
          |PR_MAG     {$$ = TPDV_MAG;}
          |errorLexico
;
numeroEntero: NUMERO_ENTERO
              | errorLexico
;
asignacionPura: VD_RUTINA '=' CODIGO_RUTINA '\n' 
                {
                  //printf("Rutina original(%i):\n%s\n", (JKE) $3,$3 );
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = $1;
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  } else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = modificaTabs((JKB*)$3,0);
                  free($3);
                  
                  //printf("Rutina asignada(%i):\n%s\n", (JKE) varDeAsig->valor.rutina, varDeAsig->valor.rutina);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);  
                }
              
              /*Asignacion de una variable de rutina a otra*/
              | VD_RUTINA '=' VD_RUTINA ';' '\n'
                {
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = $1;
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = ((JK_ID *) $3)->valor.rutina;
                  //printf("Rutina asignada:\n%s\n",varDeAsig->valor);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil); 
                }
               | VD_RUTINA '=' VD_RUTINA '@' numeroEntero ';' '\n'
                {
                  JKB* rutinaVolatil= 0;//Se usa para borrar la rutina remanente
                  varDeAsig = $1;
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  if($5  < 0)
                  {
                    AVISO_LINEA_ERROR;
                    printf("\n\tSe debe dar un número positivo de tabulaciones\n");
                    YYABORT;
                  }
                  varDeAsig->valor.rutina = modificaTabs( ((JK_ID *) $3)->valor.rutina, $5);
                  //printf("Rutina asignada:\n%s\n",varDeAsig->valor);
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil); 
                }
               
              /*Asignacion de un codigo generado a una variable de rutina*/
              | VD_RUTINA '='  PR_GENERA '(' VD_MAG ':' modoGen ')' ';' '\n' 
                { 
                  varDeAsig = $1;
                  JKB* rutinaVolatil= 0;
                  
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  if(analizaMag($5,ANALISIS_GENERAL) != 0)
                  {
                    //Error-007
                    AVISO_LINEA_ERROR;
                    printf("\n\tError en la definicion de la mag;\n");
                    YYABORT;
                  }
                  //espaciosTab=3;

                  varDeAsig->valor.rutina = generaCodigo($5, $7);
                  if( varDeAsig->valor.rutina == 0)
                  {
                    //Error-007
                    AVISO_LINEA_ERROR;
                    printf("\nError en generacion de codigo;\n");
                    YYABORT;
                  }
                  //printf("Se genero la rutina %s:\n",varDeAsig->id);
                  //Se libera al final por si hay autoreferencia
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);
                }
              | VD_RUTINA '=' PR_CONCATENA '(' VD_CODIAC ')' ';' {$$=1;
                  varDeAsig = $1;
                  JKB* rutinaVolatil= 0;
                  if( varDeAsig->tipo & 0x80 != 0)
                  {
                    rutinaVolatil = varDeAsig->valor.rutina;
                  }else
                  {
                    FLAG_VARIABLE_INICIALIZADA ;
                  }
                  varDeAsig->valor.rutina = concatenaCadenas( (((JK_ID*)$5)->valor.codiac )  );
                  if(rutinaVolatil!=0 && rutinaVolatil != varDeAsig->valor.rutina )
                    free(rutinaVolatil);
                }
              | VD_CODIAC '(' NUMERO_ENTERO ')' '='  VD_RUTINA ';' '\n' 
                {
                  VL_CODIAC *vrTmp;
                  varDeAsig = $1;
                  vrTmp=varDeAsig->valor.codiac;
                  if($3 < vrTmp->dim)
                  *(vrTmp->rutinaI + $3) = (JK_ID*) $6;
                  else
                  {
                    //Error-002
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , $3, varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  }
                  //printf("Se asigno una accion a un codiac\n");
                }
              
              /*Asignacion de codigo a una made*/
              | VD_MADE '(' NUMERO_ENTERO ')' '=' VD_CODI ';' '\n' 
                {
                  VL_MADE *vrTmp;
                  varDeAsig = $1;
                  vrTmp=varDeAsig->valor.made;
                  if($3 < vrTmp->dim)
                   *(vrTmp->codiI + $3) = (JK_ID*) $6;
                  else
                  {
                    //Error-003
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , $3, varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  }
                  //printf("Made correcta\n");
                }
              | VD_MADS '(' NUMERO_ENTERO ')' '=' VD_CODIAC ';' '\n'
                {
                  VL_MADS *vrTmp;
                  varDeAsig = $1;
                  vrTmp=varDeAsig->valor.mads;
                  if($3 < vrTmp->dim)
                   *(vrTmp->codiacI + $3) = (JK_ID*) $6;
                  else
                  {
                    //Error-004
                    AVISO_LINEA_ERROR;
                    printf("\tEl valor de índice %i excede la dimensión de \"%s\" que es %i"
                    , $3, varDeAsig->id,vrTmp->dim);
                    YYABORT;
                  } 
                  //printf("Mads correcta\n");
                }
              | asignaMag  filasMag '}' ';' '\n'
                {
                  JKES numero = 0;
                  VL_MAG *vrTmp = varDeAsig->valor.mag;
                  JKB *matriz = vrTmp->elementos;
                  printf("Mag correcta con %i filas.\n\n", $2 );
                  //for(numero= 0; numero < 12;numero++)
                  //printf("Elemento %i de la mag %s es : %i \n",numero,
                  // varDeAsig->id,  *(matriz+numero) );
                }
;
/*Modos de generar la rutina a partir de la Mag*/
modoGen: PR_SWITCH  {$$= MODO_GEN_SWITCH;}
        | PR_IF     {$$= MODO_GEN_IF;}
;


/*Asigna mag, requiere preparar la variable de asignacion*/
asignaMag: VD_MAG '=' '{'
          {
            varDeAsig = $1;
            //filaNumerica = malloc(sizeof(VV_SEC_NUM));
            
          }
;
/*Filas de la Mag */
filasMag: valoresM ':' valoresM '\n'          
          {
            VV_SEC_NUM *numIn = $1;
            VV_SEC_NUM *numOut = $3;
            VL_MAG *vrTmp = varDeAsig->valor.mag;
            JKB *matriz = vrTmp->elementos;
            JKES i ;
            //printf("\n Entradas: %i \tSalidas: %i \n\n", numIn->dim, numOut->dim);
            //Verifica magnitudes
            if(numIn->dim == vrTmp->nIn && numOut->dim == vrTmp->nOut)
            {
              for(i=0;i<numIn->dim;i++)
              {
                *(matriz+ i ) = numIn->nums[i];
                 //printf(" %i,",numIn->nums[i]);
              }
              for(i=0;i< numOut->dim ;i++)
              {
                *(matriz+ i + numIn->dim ) = numOut->nums[i];
                //printf(" %i,",numOut->nums[i]);
              }
              $$=1;
            } else 
            {
              //Error en la separacion de filas de entrada, o cantidad de
              // elementos, se puede identificar bien los errores.
              
              //Error-005
              AVISO_LINEA_ERROR;
              printf("\tNo se puede asignar la matriz a la Mag.\n");
              printf("\tError en la especificación de la secuencia.\n");
              printf("\tVerifique los separadores o la cantidad de elementos.\n");
              YYABORT;
              
            }
          }
        | filasMag valoresM ':' valoresM '\n'
        {
          VV_SEC_NUM *numIn = $2;
          VV_SEC_NUM *numOut = $4;
          VL_MAG *vrTmp = varDeAsig->valor.mag;
          JKB *matriz = vrTmp->elementos;
          JKES i ;
          //printf("\n Entradas: %i \tSalidas: %i \n\n", numIn->dim, numOut->dim);
          if(numIn->dim == vrTmp->nIn && numOut->dim == vrTmp->nOut
              && $1< vrTmp->dim)
          {
            //printf("\t");
            for(i=0;i<numIn->dim;i++)
            {
              *(matriz+ i + $1 *(vrTmp->nIn+vrTmp->nOut)) = numIn->nums[i];
              //printf(" %i,",numIn->nums[i]);
            }
            //printf("\t : ");
            for(i=0;i< numOut->dim ;i++)
            {
              *(matriz+ i + numIn->dim + $1 *(vrTmp->nIn+vrTmp->nOut)) 
              = numOut->nums[i];
              //printf(" %i,",numOut->nums[i]);
            }
            //printf("\n");
            $$+=1;
            //Libera la memoria
            free(numIn);
            free(numOut);
          } else 
          {
            //Error en la separacion de filas de entrada, o cantidad de
            // elementos, se puede identificar bien los errores.
            //Error-005
            AVISO_LINEA_ERROR;
            printf("\tNo se puede asignar la matriz a la Mag.\n");
            printf("\tError en la especificación de la secuencia.\n");
            printf("\tVerifique los separadores o la cantidad de elementos.\n");
            YYABORT;
          }
        }
;
valoresM : NUMERO_ENTERO 
          {
            filaNumerica = malloc(sizeof(VV_SEC_NUM));
            filaNumerica->nums[0] = (JKB) $1;
            filaNumerica->dim = 1;
            $$=filaNumerica;
            //printf(" inicia #%i \t",$1);
          }
         | valoresM ',' NUMERO_ENTERO 
         {
            if(filaNumerica->dim < MAX_SEC_NUMS )
            {
              filaNumerica->nums[filaNumerica->dim] = $3;
              filaNumerica->dim += 1;
              //$$=filaNumerica;
            }
            //printf("#%i \t",$3);
         } 
        | valoresM  NUMERO_ENTERO
        {
          //Error-006
          //No se porque no se actualiza a la linea de error la variable que 
          //cuenta las lineas, por eso incremento en 1 para que el mensaje
          //sea correcto.
          lineaLectura++; 
          AVISO_LINEA_ERROR;
          printf("\tNo se puede asignar la matriz a la Mag.\n");
          printf("\tEs posible que haga falta especificar una coma.\n");
          printf("\tCorrija la secuencia (fila) de la Mag.\n");
          YYABORT;
        }
;

procedimientoSimple: PR_ESCRIBE '(' VD_RUTINA ')' ';' {$$ = 1;
          FILE *fichero;
          JKB nombre [MAX_L_TOKEN+20];//deja 19 caracteres por si la extension es larga
          
          varDeAsig = $3;
          printf("Nombre de archivo: %s\n", varDeAsig->id);
          
          sprintf(nombre, "%s.c",varDeAsig->id);
          fichero = fopen (nombre, "w");//Escribe el nombre del archivo
          fprintf(fichero,"%s\n", varDeAsig->valor.cadena);
          fclose(fichero);
        }
        | PR_ESCRIBE '(' VD_RUTINA ',' tipoArchivo ')' ';' {$$ = 1;
          FILE *fichero;
          JKB nombre [MAX_L_TOKEN+MAX_L_TOKEN];//deja 19 caracteres por si la extension es larga
          
          varDeAsig = $3;
          printf("Nombre de archivo: %s\n", varDeAsig->id);
          
          sprintf(nombre, "%s.%s",varDeAsig->id,$5);
          fichero = fopen (nombre, "w");//Escribe el nombre del archivo
          fprintf(fichero,"%s\n", varDeAsig->valor.cadena);
          fclose(fichero);
        }              
;
tipoArchivo: idAsignado {
          varDeAsig = $1;
          $$ = varDeAsig->id;
        }
        | IDENTIFICADOR {
          $$ = $1;
        }
        ;
errorLexico: TOKEN_INVALIDO    
            { printf("Token no valido en la linea %i\n:", lineaLectura+1);
              printf("\t%s\n", msjError); YYABORT;}

;
%%



/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*%%%%%%%%%%%%%%%%%%%%%%%      Código adicional   %%%%%%%%%%%%%%%%%%%%%%%%*/


/* Función para el informe de errores*/
/* Llamada por yyparse ante un error */
int yyerror (char *s)  {
  printf ("%s\n", s);
}

/* Uso del parser*/
int main( int argc,char **argv)
{
  ++argv, --argc; /* se salta el nombre del programa */
  if(argc > 0 ){
    printf("Se utiliza un archivo\n");
    yyin= fopen(argv[0],"r");
    //yyout= fopen ("./resultado.txt", "w"); //Guarda el resultado en un archivo
  }
  else {
    printf("Versión terminal \n");
    yyin= stdin;
  }
  jkError = yyparse ();
  if(jkError!=0)
  {
    printf("\n **** Fin del procesamiento debido a algun error: %i.\n%s\n",jkError,msjError);
  }
  printf( "\nLineas procesadas : %d\n\n",
  lineaLectura );
  return 0;
}








