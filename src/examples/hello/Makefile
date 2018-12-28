SRC = ../../../src/examples/hello
OBJ = ../../../obj/examples/hello
BIN = ../../../bin/examples/hello

HEADER = $(SRC)/hello.h

FUNC_OBJ = $(OBJ)/hello_project.o $(OBJ)/hello_main.o

all : hello

hello : $(FUNC_OBJ)
	sudo gcc -o hello $(FUNC_OBJ) -lstdc++
	sudo mv -f $(@) $(BIN)/.

$(OBJ)/hello_main.o : $(HEADER) $(SRC)/hello_main.cpp
	sudo gcc -c $(SRC)/hello_main.cpp -lstdc++;sudo mv hello_main.o $(OBJ)

$(OBJ)/hello_project.o : $(HEADER) $(SRC)/hello_project.cpp
	sudo gcc -c $(SRC)/hello_project.cpp -lstdc++;sudo mv hello_project.o $(OBJ)

clean :
	sudo rm -rf $(OBJ)/*
	sudo rm -rf $(BIN)/*
