//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%% Explorador o escaner utilizado sobre codigo fuente con %%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifndef __LISTA_TIPO_TOKEN__
#define __LISTA_TIPO_TOKEN__

//Cuando se va a retornar el tipo de token se regresa un carácter para que en
//la siguiente llamada no se ignore el caracter que hizo terminar la lectura
//del token.
#define RETORNA_TK( tipo )  if ( c != EOF) ungetc(c, yyin); return (tipo)


#define NUMERO_ENTERO   256     //Identificador para token numérico
#define FIN_DE_FICHERO  257 
#define TOKEN_INVALIDO  258
#define IDENTIFICADOR   259
#define COMENTARIO      260
#define CODIGO_RUTINA   261



//******************************************************************************
//  Los números que identifican los tokens de palabras reservadas se toman
// a partir del número 500, por tanto al retornar el identificador de tipo
// de token hay que hacerle la suma de 500 al identificador,
// para ello se usa la macro de retorno de tipo de token palabra reservada
#define RETORNA_TK_PR( tipo )  if ( c != EOF) ungetc(c, yyin); return ( tipo + 500)

//******************************************************************************
//  Los números que identifican los tokens de cadenas respectivas a variables 
// se toman a partir del número 1000, por tanto al retornar el identificador de tipo
// de variable declarada hay que hacerle la suma de 1000,
// para ello se usa la macro de retorno de tipo de token variable declarada.
#define RETORNA_TK_VD( tipo ) if ( c != EOF) ungetc(c, yyin); return ( tipo + 1000)
//Los tokens de palabra reservada tienen prefijo PR
enum jke_id_palabrasReservadas {
 	#define JK_ACCION(am_nombre,  am_cadena)           am_nombre
	#include "listaTokens.def"
};

//Debe ser estatico para que no se defina dos veces
static const JKB *jkc_palabrasReservadas[]= { 
 	#define JK_ACCION(am_nombre,  am_cadena)          am_cadena
	#include "listaTokens.def"
};

#endif

// ¡Importante!: Al utilizar las macros de retorno de tipos de token, si están
// dentro de un if tener cuidado que la macro esté en el ambiente de if , 
// o sea entre llaves, pues no es una sentencia simple, si no que son dos 
// sentencias.
