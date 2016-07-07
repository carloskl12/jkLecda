//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%% Analizador léxico %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include "jkTiposEstandar.h"
#include "escanerLECDA.h"
#include "variables.h"
#include "genera.h"
#include "cadenas.h"
//Definiciones para los tipos de sentencias y otros no terminales
#define DECLARACION_PURA        1
#define ASIGNACION_PURA         2
#define PROCEDIMIENTO_SIMPLE    3
#define MODO_SWITCH             4
#define MODO_IF                 5

//Declaraciones preliminares
#define TPDV_CODI   0
#define TPDV_CODIAC 1
#define TPDV_RUTINA 2
#define TPDV_MADE   3
#define TPDV_MADS   4
#define TPDV_MAG    5

#define AVISO_LINEA_ERROR printf("\nError en la linea: %i\n", lineaLectura)

//Usado para indicar que la variable ha sido inicializada
#define FLAG_VARIABLE_INICIALIZADA  varDeAsig->tipo = (varDeAsig->tipo) | 0x80

//Declaracion de las variables globlales
FILE *yyin; //Flujo de entrada
JKB *msjError; //Puntero al ultimo mensaje de error.
JKES lineaLectura;
//Número del error.
JKE jkError;
JKE espaciosTab=2;

JKES cConcat=0; //Contador de concatenaciones;

extern JKES yylex();
extern JK_ID *tabla_Ids = (JK_ID *) 0; //Tabla de identificadores o simbolos.

JK_ID *varDeAsig; // Variable a la cual se le asignara un valor
VV_SEC_NUM *filaNumerica ; // variable temporal para almacenar una fila numerica






