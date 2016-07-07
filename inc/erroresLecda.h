//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%% Manejo de errores con %%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//Definiciones generales
#ifndef __JK_ERRORES__
#define __JK_ERRORES__

//Asigna al puntero de error la cadena respectiva al error.
//Error es un identificador usado en la enumeracion de errores con su
//prefijo IDE. El prefijo IDE es usado para agrupar la forma de referirse a 
//errores
#define REPORTA_ERROR( error )  msjError = jkc_mensajesError[ error ] 




//Los errores poseen prefijo IDE_
enum jke_id_errores {
 	#define JK_ACCION(am_nombre,  am_cadena)          am_nombre
	#include "erroresLecda.def"
};

//Debe ser estatico para que no se defina dos veces
static const JKB *jkc_mensajesError[]= { 
 	#define JK_ACCION(am_nombre,  am_cadena)          am_cadena
	#include "erroresLecda.def"
};

#endif
