#----------------Nombres de los directorios utilizados.

DIR_DEFINE=./def/#directorio para guardar archivos *.def
DIR_INCLUDE=./inc/#directorio para guardar archivos *.h
DIR_SOURCE=./src/#directorio para guardar archivos *.c
DIR_BIN=./bin/#directorio para guardar los ejecutables
DIR_OBJ=./obj/#directorio para guardar los archivos objeto *.o

#---------------- directorios donde buscar los archivos de cabecera
INCLUDE= -I$(DIR_INCLUDE) -I$(DIR_DEFINE)  

#------------------directorios donde busca los archivos segun un patron
vpath %.def $(DIR_DEFINE)
vpath %.h   $(DIR_INCLUDE) 
vpath %.c  $(DIR_SOURCE)
vpath %.y  $(DIR_SOURCE)
vpath %.o  $(DIR_OBJ)

#codigos objeto sin dirección
CODIGO_OBJETO:= $(patsubst $(DIR_SOURCE)%.c,%.o,$(wildcard $(DIR_SOURCE)*.c))
#antepone la ruta donde hallar los archivos
CODIGO_OBJETO_DIR:= $(patsubst %.o,$(DIR_OBJ)%.o,$(CODIGO_OBJETO))

#Dependencias de los diferentes codigos objeto
DEP_ESCANER= escanerLECDA.c escanerLECDA.h erroresEscaner.h erroresEscaner.def\
           alfabeto.h listaTokens.h listaTokens.def jkTiposEstandar.h\
           variables.h

DEP_VARIABLES= variables.c jkTiposEstandar.h variables.h

DEP_GENERA= genera.c genera.h jkTiposEstandar.h variables.h

DEP_CADENAS = cadenas.c cadenas.h genera.h jkTiposEstandar.h variables.h

DEP_BISON= lecda.y escanerLECDA.h variables.h jkTiposEstandar.h lecda.h


gclec : $(CODIGO_OBJETO)
	@echo "\nEnlazando codigos objeto..."
	gcc $(CODIGO_OBJETO_DIR) -o $(DIR_BIN)$(@F) -w
	@echo "Programa generado correctamente" 
	@echo "--Copyright 2015 Carlos Jacanamejoy--"
	@echo "---GNU General Public License 3.0 ---\n"

lecda.c : $(DEP_BISON)
	@echo "\nGenerando el codigo c del analizador léxico"
	bison $< -o $(DIR_SOURCE)lecda.c
	
lecda.o : lecda.c
	@echo "\nCompilando el analizador léxico-semántico..."
	gcc -c $< $(INCLUDE) -o $(DIR_OBJ)$(@F)  -w

variables.o: $(DEP_VARIABLES)
	@echo "\nCompilando funciones para manejo de variables..."
	gcc -c $< $(INCLUDE) -o $(DIR_OBJ)$(@F)  -w

escanerLECDA.o: $(DEP_ESCANER)
	@echo "\nCompilando el escaner..."
	gcc -c $< $(INCLUDE) -o $(DIR_OBJ)$(@F)  -w
	
genera.o: $(DEP_GENERA)
	@echo "\nCompilando generador de codigo..."
	gcc -c $< $(INCLUDE) -o $(DIR_OBJ)$(@F)  -w

cadenas.o: $(DEP_CADENAS)
	@echo "\nCompilando funciones de cadenas..."
	gcc -c $< $(INCLUDE) -o $(DIR_OBJ)$(@F)  -w
	
refrescar:
	touch $(DIR_INCLUDE)jkTiposEstandar.h
	
probar:
	./bin/gclec ./ejemplos/escanerLecda02.lec





