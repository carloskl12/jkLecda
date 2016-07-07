#ifndef __JK_GENERA__
#define __JK_GENERA__

#include "jkTiposEstandar.h"
#include "variables.h"
#include "cadenas.h"

//Bloque de memoria para una rutina
#define BLOQUE_MEM_RUTINA 500

//Modos de generacion de codigo
#define MODO_GEN_SWITCH 0
#define MODO_GEN_IF     1 

//Tipos de analisis
#define ANALISIS_GENERAL  0


JKB* generaCodigo(JK_ID *variable, JKB modoGen);
JKES analizaMag(JK_ID *variable, JKB tpAnalisis);

#endif 
