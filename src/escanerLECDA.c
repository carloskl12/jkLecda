//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%% Explorador o escaner utilizado sobre codigo fuente con %%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#ifndef __JKEXPLORADOR__
#define __JKEXPLORADOR__
#include <stdio.h> 
#include <string.h> 
#include "jkTiposEstandar.h"
#include "erroresEscaner.h"
#include "alfabeto.h"
#include "listaTokens.h"
#include "escanerLECDA.h"
#include "variables.h"

// La máxima cantidad de dígitos de un número es 10 porque se usan solo 32 bits
// para representarlos, y el máximo numero entero con signo que se puede
// representar es 4294967295
#define MAX_L_NUMERO 10 //Maxima cantidad de dígitos de un número entero
#define BLOQUE_RUTINA 500 // Bloques de memoria para una rutina

// Macro para definir la accion a seguir luego de hallar una nueva linea
#define ACCION_NUEVA_LINEA lineaLectura++

// variable para contar las lineas
extern JKES lineaLectura;

//Número del error.
extern JKE jkError;

//Tabla de simbolos (identificadores asignados)
extern JK_ID *tabla_Ids; 

//El flujo sobre el cual se han de leer los tokens
extern FILE *yyin;

// Se define la variable en la cual el analizador léxico busca los valores
// corresponde a las interpretaciones posibles de una variable
VALOR_ID yylval; 

JK_ID *yyjkvar; //La ultima variable que se ha asociado con un token leido

//FILE *yyout; Flujo de salida

JKES yylex(){
  JKES c;
  JKES i;
  JKB tpC; //tipo de caracter
  yylval.entero=0;
  //printf("caracter: %c", (JKB) c);
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Ignora los espacios en blanco 
  while ((c = getc (yyin)) == ' ' || c == '\t')
  ;
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // devuelve fin de fichero 
  if (c == EOF)
  {
    RETORNA_TK( FIN_DE_FICHERO );
  }
  
  //*****************************************************************
  //Basado en el tipo del primer caracter del token se decide que hacer
  //Todas las ramificaciones de posibles acciones empiezan por esta
  //verificación.
  //*****************************************************************
  tpC= jk_tipoCaracter(c);
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Procesa números enteros 
  if ( tpC == CHAR_NUMERO)
  {
    i=0;
    do{
      yylval.entero= 10*yylval.entero + c - 48;
      i++;
    }
    while( (c=getc (yyin)) != EOF &&
     jk_tipoCaracter(c)== CHAR_NUMERO  && i < MAX_L_NUMERO);
    if(i >= MAX_L_NUMERO )
    {
      REPORTA_ERROR( IDE_ENTERO_INVALIDO ) ;
      RETORNA_TK( TOKEN_INVALIDO );
    }
    RETORNA_TK( NUMERO_ENTERO );
  }
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // devuelve caracteres sencillos respectivos a operadores
  if ( tpC == CHAR_OPUNC)
  {
    return ( c );
  }
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Identificador valido
  if ( tpC == CHAR_LETRA )
  {
    i=0;
    //Reserva memoria para la cadena del token, la cadenta termina con un cero
    //por ello se le asigna un caracter extra.
    yylval.cadena= malloc( (MAX_L_TOKEN +1) * sizeof(JKB) );
    JKB *cadena = yylval.cadena; // usado para hacer mas facil asignar valores
    
    do{
      *cadena = (JKB) c ;
      cadena++;
      i++;
      c=getc (yyin);
      tpC = jk_tipoCaracter(c);
    }
    while( c != EOF && 
     (tpC == CHAR_NUMERO  || tpC == CHAR_LETRA ) &&
      i < MAX_L_TOKEN );
      *cadena= (JKB) 0; //Agrega el terminador de cadena.
    if(i >= MAX_L_TOKEN )
    {
      REPORTA_ERROR( IDE_IDENTIFICADOR_INVALIDO ) ;
      RETORNA_TK( TOKEN_INVALIDO );
    }
    //************** Verifica si es una palabra reservada **********************
    for(i=0;i <= ULTIMA_PALABRA_RESERVADA ; i++) 
        if(! strcmp( yylval.cadena , jkc_palabrasReservadas[i]) ) 
        {
          RETORNA_TK_PR( i );
        }
    //*************** verifica si es una variable declarada ********************
    yyjkvar = buscaId( yylval.cadena);
    if(yyjkvar != 0)
    {
      //¡Importante! el valor para el analizador lexico es la estructura
      // de la variable, no el valor de la variable en si
      // por ello puede exitir ambiguedad sobre los tipos de valores manejados
      // en el analizador lexico, respecto a la estructura de VALOR_ID y su
      // uso natural.
      JKB tipoEnmascarado = (yyjkvar->tipo) & 0x7F;
      yylval.codi = yyjkvar; 
      RETORNA_TK_VD( tipoEnmascarado );
    }
    // No es una palabra reservada, ni una variable declarada
    // si llega a este punto, por ello es un
    // identificador válido
    RETORNA_TK( IDENTIFICADOR );
  }
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // caso de comentarios
  if( c == '/')
  {
    c=getc (yyin);
    if( c == '/') 
    {
      //Se pasa el resto de la linea completa
      while( (c=getc (yyin)) != EOF && c != '\n')
      ;
      if( c== '\n')
      {
        ACCION_NUEVA_LINEA;
      }
      return ( (JKES) '\n' ); //Retorno limpio
    } else
    {
      // El caracter / no tiene ningun uso por si solo, por ello el error
      REPORTA_ERROR( IDE_COMENTARIO_INVALIDO ) ;
      RETORNA_TK( TOKEN_INVALIDO );
    }
  }
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // Posible caso de codigo fuente (rutina)
  if( c== '\n')
  {
    ACCION_NUEVA_LINEA;
    c=getc (yyin);
    if(c == '$')
    //Se hallo especificador de  codigo fuente
    {
      //Se pasa el resto de la linea completa
      while( (c=getc (yyin)) != EOF && c != '\n')
      ;
      if( c== '\n')
      {
        //ACCION_NUEVA_LINEA;//Se lee nueva linea por el do en el otro
      } else 
      {
        REPORTA_ERROR( IDE_RUTINA_SIN_ESPECIFICAR ) ;
        RETORNA_TK( TOKEN_INVALIDO );
      }
      //Los codigos que siguen corresponden al codigo fuente
      //Se toman tal cual hasta hallar el terminador de codigo
      JKES memReserva = BLOQUE_RUTINA +1; // memoria reservada
      yylval.cadena= malloc( memReserva * sizeof(JKB) );
      JKB *cadena = yylval.cadena; // usado para hacer mas facil asignar valores
      JKES cAnt; //Caracter anterior
      i=0;//Longitud de la cadena
      do
      {
        //verifica que exista suficiente memoria reservada
        //En caso contrario reserva mas memoria
        if( memReserva-1 == i)
        {
          
          memReserva += BLOQUE_RUTINA;
          cadena = realloc(yylval.cadena,memReserva);
          if(cadena == NULL)
          {
            REPORTA_ERROR( IDE_MEMORIA_INSUFICIENTE ) ;
            RETORNA_TK( TOKEN_INVALIDO );
          } else
          {
            yylval.cadena = cadena;
            cadena+=i-1; //Actualiza el puntero a donde debe sesguir escribiendo.
          }
        }
        if( c== '\n')
        {
          ACCION_NUEVA_LINEA;
        } 
        if(i>0)//Evita introducir el caracter de nueva linea
        {
          *cadena = (JKB) c ;
          cadena++;
        }
        i++;        
        cAnt=c;
        c=getc (yyin);
        tpC = jk_tipoCaracter(c);
      }      
      while( c != EOF && 
       (cAnt != '\n'  || c != '$')  );
      *cadena = (JKB) 0 ;//Termina la cadena
      if(c == EOF)
      {
        REPORTA_ERROR( IDE_RUTINA_SIN_TERMINAR ) ;
        RETORNA_TK( TOKEN_INVALIDO );
      }
      
      //Se ignora el resto de linea
      while( (c=getc (yyin)) != EOF && c != '\n')
      ;

      //Una rutina puede terminar en el ultimo renglón del archivo, el cual debe
      //corresponder al terminal de rutina $.
      RETORNA_TK( CODIGO_RUTINA );
      
    }
   //Si es una nueva linea normal, retorna la nueva linea
   //Retorno limpio, no requiere reanalizar el caracter de finalizacion de token
   RETORNA_TK( (JKES) '\n' ); 
  }
  
  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  REPORTA_ERROR( IDE_CARACTER_INVALIDO ) ;
  yylval.entero = c;
  return TOKEN_INVALIDO ;
}

#endif

// Importante:
// Los operadores de un solo caracter no requieren terminador de caracter para 
// identificarse como tokens, por ello se retorna de forma limpia, sin retroceder
// la lectura del flujo de entrada.
