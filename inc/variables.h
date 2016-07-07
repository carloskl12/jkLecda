#ifndef __JK_VARIABLES__
#define __JK_VARIABLES__

#include "jkTiposEstandar.h"

//**** Máximo número de identificadores
#define MAX_NUM_IDS       100
//Maxima cantidad de numeros por fila de una matriz numerica.
#define MAX_SEC_NUMS      16
//****Tipos de identificadores, son la misma de los tipos como se interpreta
//    el valor del identificador.
//    Es importante tener en cuenta que para el tipo se usa un byte, donde
//    se deja el bit de mayor peso para indicar que la variable se ha
//    inicializado (1), o no inicializado (0).
#define TPID_ENTERO       0
#define TPID_FUNCION_RE   1
#define TPID_CADENA       2
#define TPID_CODI         3
#define TPID_CODIAC       4
#define TPID_MADE         5
#define TPID_MADS         6  
#define TPID_MAG          7
#define TPID_RUTINA       8

//Macro para dar un valor constante de una variable sin inicializar.
#define VALOR_SIN_INICIALIZAR (VALOR_ID) 0

#define DECLARA_CODI( n_secuencias) valorTmp.entero = n_secuencias
//Al declar el valor del codiac, se asigna memorai al vector de punteros
// y se pone el valor del primer puntero en cero para indicar variable sin
// inicializar
#define DECLARA_CODIAC( n_secuencias) \
        valorTmp.codiac = malloc( n_secuencias *(sizeof (JK_ID *))  );\
        valorTmp.codiac[0]= 0
#define DECLARA_MAG( n_secuencias , n_in, n_out)\
        valorTmp.mag = malloc( sizeof (VL_MAG)  );\
        valorTmp.
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//*** Union para indicar el valor de un identificador
typedef union
{ 
  JKES entero;  //Valor entero de la variable (Codi unico o simple)
  JKES (*funcionRE)();  //Funcion que retorna numero entero
	JKB *cadena; //Puntero a cadena (Rutina)
  PVACIO codi;
  PVACIO codiac;
  PVACIO made;
  PVACIO mads;
  PVACIO mag;
  PVACIO rutina;
} VALOR_ID;

//*** Estructura para definir la pila de los identificadores
struct JK_ID 
{
  VALOR_ID valor;       // valor del identificador
	JKB *id;              // Identificador (nombre) de variable o funcion 
	JKB tipo;             // Tipo de identificador
  struct JK_ID *next;   // Enlase con la siguiente estructura
};

typedef struct JK_ID JK_ID;

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%% Definicion de las estructuras de valor para fijar la forma
//%%%%% en que se lee el valor de los diferentes tipos de identificadores
//%%%%% que por defecto solo tienen asociado un puntero vacio.
//  Las estructuras que encapsulan tipos de variables se nombran con prefijo
//  VL (Variable lecda).

// un codi se interpreta como un valor entero de un byte
typedef struct
{
  JKB valorMax;
} VL_CODI;

// un codiac se interpreta como un conjunto de rutinas
typedef struct
{
  JKB dim;
  JK_ID **rutinaI; //rutina I-ésima
} VL_CODIAC;

// una made se interpreta como un conjunto de codis
typedef struct
{
  JKB dim;
  JK_ID **codiI; //codi I-ésimo
} VL_MADE;

// una mads se interpreta como un conjunto de codiacs 
typedef struct
{
  JKB dim;
  JK_ID **codiacI; //codiac I-ésimo
} VL_MADS;

//*** Estructura para la mag
typedef struct
{
  JKB dim;  //Dimensión o cantidad de filas
  JKB nIn;  //Número de variables de entrada
  JKB nOut; //Número de variables de salida
  JK_ID **codiI; //Vector de punteros a los codis 
  JK_ID **codiacI; //Vector de punteros a los codiac (JK_ID)
  JKB *elementos; //Puntero a la matriz de asociación.(JK_ID)
} VL_MAG;

//***** VV_ es el prefijo para variables virtuales, que no se usan en el
//***** lenguaje de forma directa, si no solamente se usa de manera interna
//***** por el compilador

//**** Estructura para almacenar una secuencia de números 
//     de dimencion indefinida
typedef struct
{
  JKB nums[MAX_SEC_NUMS]; // puntero a los numeros
  JKES dim; //Cantidad de números
} VV_SEC_NUM;

// Prototipos de las funciones para manejar la tabla de simbolos
// o identifcadores de diferentes tipos.
JKES agregaId( JKB *idCadena,  JKB tipo, VALOR_ID valor);
JKES borraId( JKB *idCadena);
JK_ID *buscaId( JKB *idCadena);



#endif 
