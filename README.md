//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%% Analizador léxico %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%% formato ISO-8859-15 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% (Latin 9)%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%% Versión  1.0 (LECDA REDUCIDO) %%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%% Carlos Antonio Jacanamejoy Jamioy %%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

gclec es un sencillo compilador para el lenguaje LECDA (Lógica En conjuntos
dispersos asociados).

El directorio principal de trabajo contiene los directorios:

//bin:
  Se halla el binario del compilador.

//bison:
  Archivo en lenguaje para bison y el codigo generado del analizador.

def://definiciones:
  Archivos que contienen listas de información (*.def)

//ejemplos:
  Codigo de ejemplo en lenguaje lecda.

inc://include:
  Las cabeceras que se utilizan en el proyecto.

obj:
  Codigo objeto generado para posteriormente enlazarse
  
src:
  Codigo fuente en c, y el archivo para el analizador lexico-semántico 
  desarrollado en bison (*.y)


