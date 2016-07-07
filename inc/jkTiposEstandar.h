#include <stdio.h>
#include <stdlib.h>


#ifndef __JK_STD_TIPOS__
#define __JK_STD_TIPOS__

#define UNIX

/*
#ifdef WINDOWS					// código específico de Windows 
    #warning "Sistema windows"
#elif defined(UNIX)				// código específico de Unix 
    #warning Sistema UNIX 
#else
    #error "¿ Cuál es tu Sistema Operativo ?"
#endif
*/
typedef __UINT8_TYPE__ JKB;     //Jk byte
typedef __UINT16_TYPE__ JKEC;   //Jk entero corto 2 BYTES
typedef __UINT32_TYPE__ JKE;    //Jk entero de 4 bytes
typedef __UINT64_TYPE__ JKL;    //Jk entero de 8 bytes

// Versiones con signo
typedef __INT8_TYPE__ JKBS;     
typedef __INT16_TYPE__ JKECS;   
typedef __INT32_TYPE__ JKES;    
typedef __INT64_TYPE__ JKLS;   

// Valores de tipo flotante
#if __SIZEOF_FLOAT__ == 4
typedef float JKF; //Jk float de 4 bytes
#else
    #warning No se ha definido el tipo float correctamente
#endif

#if __SIZEOF_DOUBLE__ == 8
typedef double JKD; //Jk double de 8 bytes
#else
    #warning No se ha definido el tipo double correctamente
#endif

#if __SIZEOF_LONG_DOUBLE__ == 16
typedef long double JKLD; //Jk long double de 16 bytes
#else
    #warning No se ha definido el tipo long double correctamente
#endif

//Punteros
typedef JKB *PJKB;      //Puntero a JKB
typedef void *PVACIO;   //Puntero vacio o sin formato
typedef PVACIO ELEMENTO;//Puntero vacio a elemento

//Estructura para manejo de datos dinámicos
typedef struct{
	JKE iL;     //Indice de lectura
	JKE dim;    //cantidad de bytes del sector de memoria
	JKB *datos; //Puntero al sector de memoria
	JKB tipo;   //Tipo de datos dinámicos
}JK_DATOS_DINAMICOS;

typedef struct{
	JKEC reserva;//Memoria reservada
	JKEC longitud;//Longitud de la cadena  cuenta el caracter nulo
	JKB *valor;//Puntero a la cadena
}JK_CADENA;

#endif


