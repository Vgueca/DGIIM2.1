BIN = bin
OBJ = obj
SRC = src
INC = inc

$(BIN)/main: $(OBJ)/main.o $(OBJ)/funciones.o $(OBJ)/imagenES.o $(OBJ)/imagen.o
	echo Creando el ejecutable.
	g++ $^ -o $@

$(OBJ)/main.o: $(SRC)/main.cpp
	echo Creando el main.o.
	g++ -g -c -I./$(INC) $< -o $@

$(OBJ)/funciones.o: $(SRC)/funciones.cpp $(INC)/funciones.h
	echo Creando el funciones.o.
	g++ -g -c -I./$(INC) $< -o $@

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	echo Creando el imagenES.o.
	g++ -g -c -I./$(INC) $< -o $@

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h
	echo Creando el imagen.o.
	g++ -g -c -I./$(INC) $< -o $@

clean: 
	echo Limpiando.
	rm -f $(OBJ)/* $(BIN)/*

rebuild: clean $(BIN)/main

documentacion:
	echo Creando la documentacion.
	doxygen Doxyfile
