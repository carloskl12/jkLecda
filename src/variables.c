//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%% Funciones para el manejo de variables  %%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <stdio.h> 
#include <string.h> 
#include "jkTiposEstandar.h"
#include "variables.h"

//variable que contiene el espacio para el valor de una variable
VALOR_ID  valorTmp;

//Puntero a vector de punteso que apuntan a elementos de la tabla de simbolos
//Usados para almacenar temporalmente
JK_ID **vecCodis; //Cuando no se sabe que tipo de simbolos se concatena
JK_ID **vecMade; //Cuando no se sabe que tipo de simbolos se concatena
JK_ID **vecMads; //Cuando no se sabe que tipo de simbolos se concatena
//Acerca del tipo de simbolos que se estan leyendo y acumulando.
JKB tipoTmp;

//Tabla de símbolos
JK_ID *tabla_Ids; 

//Agrega símbolo a la tabla de identificadores
JKES agregaId( JKB *idCadena,  JKB tipo, VALOR_ID valor)
{
  JK_ID *nuevo =  (JK_ID *) malloc(sizeof (JK_ID) );
  nuevo->id = idCadena;
  nuevo->tipo= tipo;
  nuevo->valor= valor;
  nuevo->next = tabla_Ids;
  tabla_Ids = nuevo;
  return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
JKES borraId( JKB *idCadena)
{
  JK_ID *resultado=tabla_Ids;
  JK_ID *anterior= (JK_ID *) 0;
  JKES i=0;
  while (resultado != (JK_ID *) 0 && i < MAX_NUM_IDS)
  {
    if (strcmp (resultado->id,idCadena) == 0)
    {
      if(anterior ==  (JK_ID *) 0)
      {
        tabla_Ids = resultado->next; //Cambia el ultimo elemento de la pila
      } else {
        anterior->next = resultado->next;
      }
      // Libera la memoria asignada al nombre de la variable en el 
      // analizador léxico.
      free (resultado->id);
      
      //Libera la memoria asignada a la estructura
      free (resultado);
      return 1; //Se borro un elemento
    }
      
    i++;
    anterior = resultado;
    resultado = resultado->next;
  }
  return 0;//No borró ningun elemento porque no hallo el identificador
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
JK_ID *buscaId( JKB *idCadena)
{
  JK_ID *resultado=tabla_Ids;
  JKES i=0;
  while (resultado != (JK_ID *) 0 && i < MAX_NUM_IDS)
  {
    if (strcmp (resultado->id,idCadena) == 0)
      return resultado;
    i++;
    resultado = resultado->next;
  }

  return (JK_ID *) 0; //No hallo el identificador con ese nombre;  
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  Asignaciones





