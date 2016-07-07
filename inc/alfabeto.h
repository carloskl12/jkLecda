//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%% Explorador o escaner utilizado sobre codigo fuente con %%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

/*
  Se utiliza el formato ISO-8859-15 para que los archivos permitan
  identificadores en español, y otros lenguajes compatibles con el estandar
  ISO-8859-15
*/

#ifndef __JK_ALFABETO__
#define __JK_ALFABETO__
#include "jkTiposEstandar.h"

//%%%%%%%%% Primero se define el alfabeto del lenguaje %%%%%%%%%%%%%%%%%%%%%%%%

// El lenguaje consta básicamente de 3 tipos de palabras, operadores,
// identificadores y palabras reservadas. Aunque vale la pena tener en cuenta
// los operadores que solo se usan para separar palabras (espacio en blanco).

//Es bastante útil separar el alfabeto en categorías que identifiquen
//carácteres que por si solos ya son palabras de otros que no.

//Los operadores de un solo caracter que no tienen interpretaciones 
//redundantes con otros caracteres.
//Con el solo hecho de indentificarlos ya se los puede entender como un
//token o palabra válida del lenguaje.
const JKB jkc_operador1Simbolo[]= 
{
	':',    //Separador de secuencias 
	'.',    //Concatenación de matrices
	',',    //Separador de elementos de una matriz
	'{',    //Apertura de matriz
	'}',    //Cierre de matriz
	'(',    //Apertura a referencias
	')',    //Cierre a referencias
	'=',    //Asignación
	';',    //Fin de sentencia
	'@'     //Agrega tabuladores
};

//Los operadores que se entienden al componerse con dos caracteres.
const JKB jkc_operador2Simbolos[]=
{
  '/',    // Doble slash indica comentario
  '\n',   // Salto de linea seguido de $ indica operador de codigo literal.
  '$'     // Salto de linea seguido de $ indica operador de codigo literal.
};

//Carácters que extienden el alfabeto ASCII para usar palabras del español
// como identificadores.
const JKB jkc_charEspeciales[]=
{'á','é','í','ó','ú','ü','ñ', 'Ñ', 'Á', 'É', 'Í', 'Ó', 'Ú', 'Ü'};

//*****Las letras del alfabeto en castellano restantes forman parte del
//alfabeto de este lenguaje, como están juntas en la codificación ISO
//se evalua en un intervalo para identificarlas.

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//* Se define la función que identificara los tipos de carácteres

//Tipos de caracteres:
#define CHAR_INVALIDO   0		//Caracter fuera del alfabeto
#define CHAR_SEPARADOR  1		//Separador de tokens
#define CHAR_OPUNC      2		//Operador de un solo caracter
#define CHAR_OPDOSC	    3		//Operador de dos caracteres
#define CHAR_NUMERO     4		//Caracter numérico
#define CHAR_LETRA      5		//Caracter de tipo letra

JKB jk_tipoCaracter( JKB c)
{
	
	JKES i=0;
	for(i=0;i<sizeof(jkc_operador1Simbolo);i++)
	if(c==jkc_operador1Simbolo[i])
	return CHAR_OPUNC; //Tipo operador de un solo caracter
	
	if(c>47 && c<58)
	return CHAR_NUMERO; //Tipo numero
	
	if((c>64 && c<91)||(c>96 && c<123))
	return CHAR_LETRA; //tipo letra
	
	for(i=0;i<sizeof(jkc_charEspeciales);i++)
	if(c==jkc_charEspeciales[i])
	return CHAR_LETRA; //letra

	for(i=0;i<sizeof(jkc_operador2Simbolos);i++)
	if(c==jkc_operador2Simbolos[i])
	return CHAR_OPDOSC; //Tipo operador de dos carácteres

	if(c==32 || c== '\t')
	return CHAR_SEPARADOR; //caracter que se usa como separador de palabras
	
	return 0; //Caracter fuera del alfabeto.
}

#endif

//Importante: este archivo debe estár guardado en formato ISO-8859-15, en caso
//contrario se pueden presentar errores por la codificación de los carácteres
//especiales.


