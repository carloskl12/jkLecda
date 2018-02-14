Compilador _lecda_
==================
Versión  1.0 (LECDA REDUCIDO)
  - [¿Qué es lecda?](#qué-es-lecda)
  - [Crear el proyecto](#crear-el-proyecto)
  - [Características del compilador](#características-del-compilador)
  - [Organización del proyecto](#organización-del-proyecto)
  - [Ejemplos](#ejemplos)
 
## ¿Qué es lecda? ##
__lecda__ es el acrónimo a lógica en conjuntos dispersos asociados, la idea consiste en algo similar a una tabla de verdad, que tiene unas proposiciones con sus valores de verdad, que en _lecda_ son los conjuntos dispersos \(codi\) que pueden tener mas de dos valores, y ademas pueden variar la cantidad de valores posibles en una misma _tabla_ para diferentes _codis_.

Debido a que la lógica booleana se hace compleja cuando se trata de modelar situaciones con variables de entrada que toman más de dos valores posibles, surge la motivación para realizar _lecda_, la motivación fué construir una herramienta para desarrollar de forma rápida proyectos en lenguaje c, claro está que estos proyectos tienen ciertas características, estas deben permitir abordar la situación de forma tal que se tienen variables de entrada que fijan casos en los cuales hay acciones bien definidas que se deben realizar. 

Un conjunto _disperso (CODI)_ corresponde a un grupo de elementos representados por números naturales consecutivos iniciados en cero, asi que en forma abstracta el  conjunto disperso es un subconjunto de los números naturales. La operación valor absoluto \(_operador elementos_\) denota la cantidad de elementos que contiene el conjunto.

A== \{ 0, 1, 2, 3, 4, 5 \}, => |A| == 6;

B== \{ 0, 1, 2, 3 \}

En adelante el operador == indica equivalencia,  y el = indica asignación.

### Variables de entrada ###
El conjunto de variables de entrada puede tener una o mas variables, cada una está representada por un _Codi_, para agrupar las entradas se recurre a una matriz de  valores, denominada matriz de asociación dispersa de entrada (_Made_). Cada columna de la MADE representa cada _Codi_ que la conforma, y cada fila \(secuencia\) representa un caso en concreto de valores.

### Acciones (salidas) ###
Para definir salidas se crea otro tipo de _Codi_, este tiene asociado código, por ello se denominan _Codiac_ (Conjunto disperso con asociación de código). El conjunto de acciones de salida puede tener uno o más grupos de acciones, cada grupo de acciones está representado por un _Codiac_, para agrupar las acciones (salidas) se utiliza una matriz de valores, denominada matriz de asociación dispersa de salida (_Mads_).

### Matriz de asociación global ###
La asociación entre _Made_ y _Mads_ se denomina matriz de asociación global(_Mag_). Las secuencias de la _Mag_ corresponden al número de filas de la matriz de asociación general, y esto finalmente representa la solución a lo que se busca llegar.

Entonces lo que se hace con lecda es crear las diferentes matrices, las acciones, y luego se compila para generar el código que reflejara lo descrito por las matrices.

### Observaciones ###
La forma presentada para modelar situaciones es una propuesta en desarrollo, actualmente se requieren desarrollos teóricos en este campo, que se espera a futuro concretarlos y desarrollarlos. 

## Crear el proyecto ##
El proyecto está desarrollado sobre un sistema operativo Linux \(Ubuntu 14.04 \), para compilarlo se utilizó:

* bison (GNU bison) 3.0.2
* GNU Make 3.81
* gcc (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4

Teniendo lo necesario, para compilar el proyecto solo se requiere hacer un make en el directorio del mismo:

		make

## Características del compilador ##

gclec es un sencillo compilador para el lenguaje LECDA, es importante recordar que lecda aún está en desarrollo y por lo mismo su compilador trabaja con aspectos básicos, a continuación se documenta el lenguaje con el que trabaja el compilador.

### Palabras reservadas ###
Todas las palabras reservadas empiezan con letra mayúscula:
  * Codi: declara un codi, asociado a variables numéricas.
  * Codiac: declara un codiac, asociado a acciones o fragmentos de código.
  * Rutina: declara un contenedor de codigo.
  * Escribe: escribe codigo sobre el archivo de salida, ya sea generado o escrito directamente como literal de codigo.
  * Genera: genera el codigo a partir de una MAG.
  * Concatena: concatena las rutinas que estan asociadas a un codiac.
  * Made: declara una matriz de asociación dispersa de entrada.
  * Mads: declara una matriz de asociación dispersa de salida.
  * Mag: declara una matriz de asociación general.
  * Switch: forma de generar codigo
  * If: forma de generar codigo

### Operadores ###
Se utilizan las comillas para definir la secuencia exacta en formato de cadenas le lenguaje c:
  * "\\n$": inicio para literal de código o rutina. En realidad corresponde a un inicio de linea con el caracter $, el resto de la linea se ignora, y a partir de la siguiente línea se toma como un literal de código hasta encontrar una nueva línea que inicie $.
  * "\\n$": fin para literal de codigo o rutina. Igual que para el inicio, se toma $ en un inicio de línea para indicar la finalización del código de programación, todo lo que sigue en esta línea se ignora.
  * "\(\)": referencia a la cantidad de elementos o secuencias de un codi, made mads, o mag; o igualmente referencia a un elemento o secuencia en particular.
  * ":": indicador de modo en como se ejecutan ciertas funciones, y ademas sirve como separador en las secuencias de _Mag_ entre elementos de _Made_ y _Mads_.
  * ";": indica el fin de una sentencia.
  * "\.": indica la concatenación de CODIs.
  * "=": asignación de valor a los diferentes tipos de variables.
  * "\{\}": especificación de los elementos de una matriz.
  * ",": separador de los elementos de una matriz.
  * "//": comentarios de linea
  

### Tipos de variables ###
Los tipos de variables existentes son: Codi, Codiac, Made, Mads, Mag, Rutina.

### Tipos de sentencias ###
#### Declaraciones puras ####
Son sentencias que solo indican la creación de una variable, terminan con punto y coma y salto de linea.
  * Declaración de codi.
  
		Codi entrada(4);

  * Declaración de codiac.

		Codiac acciones(5);

  * Declaración de rutina.

		Rutina miRutina;

  * Declaración de Made.

		Made miMade(2);

  * Declaración de Mads.

		Mads miMads(2);

  * Declaración de mag:

		Mag switchM(4)(miMade:miMads);

#### Asignaciones puras ####
  * Asignación a rutina de un codigo literal. 

		miRutina =
		$@%%%%%%%%%%%lo que sea
		void rutina (a);
		$@%%%%%%%%%%%% fin de la rutina

  * Asignación de codigo generado a una rutina

		miRutina = Genera(switchM:Switch);
		miRutina = Concatena(acciones);

  * Asignación de una rutina a otra;

		miRutina = miRutina2;

  * Asigna acciones.

		acciones(0)= miRutina;

  * Asigna codi a  Made ;

		miMade(0) = entrada;

  * Asigna codiac a Mads ;

		miMads(0) = acciones;

  * Asignación de mag.

		switchM= {0: 0, 2
					1: 1, 2
					2: 3, 2
					3: 1, 3 
					};

#### Procedimientos ####
* Función escribe.

		Escribe(miRutina);



## Organización del proyecto ##
El directorio principal de trabajo contiene los directorios:

* bin: Se halla el binario del compilador.

* def \(definiciones\): Archivos que contienen listas de información (\*.def)

* ejemplos: Código de ejemplo en lenguaje lecda.

* inc \(include\): Las cabeceras que se utilizan en el proyecto.

* obj: Código objeto generado para posteriormente enlazarse
  
* src \(source\): Código fuente en c, y el archivo para el analizador lexico-semántico desarrollado en bison (\*.y) 

### Acerca del formato de los archivos ###
Los archivos fuente están dados en formato _ISO-8859-15 (Latin 9)_, es un aspecto a tener en cuenta, dado que el escaner trabaja en base a grupos de carácteres que incluyen acentos, los cuales se representan por un solo byte. También influye en que se trabajen adecuadamente los mensajes de error.

## Ejemplos ##
En el directorio ejemplos existen algunos archivos \*.lec que se pueden compilar. Para realizar una prueba, estando en el directorio del proyecto, se puede usar directamente en terminal el comando: 

		make probar
Esto creará dos archivos, uno \*.h, y otro \*.c que corresponden a la implementación del escaner de este mismo compilador.


