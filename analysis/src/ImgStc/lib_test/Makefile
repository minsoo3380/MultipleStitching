SRC = ../../../src/ImgStc/lib_test
OBJ = ../../../obj/ImgStc/lib_test
BIN = ../../../bin/ImgStc/lib_test

HEADER = $(SRC)/cvstc.hpp

FUNC_OBJ = $(OBJ)/stitching.o $(OBJ)/stc_main.o

all : stitching

stitching : $(FUNC_OBJ)
	sudo g++ -o stitching $(FUNC_OBJ) `pkg-config opencv --cflags --libs`
	sudo mv -f $(@) $(BIN)/.

$(OBJ)/stc_main.o : $(HEADER) $(SRC)/stc_main.cpp
	sudo g++ -c $(SRC)/stc_main.cpp; sudo mv stc_main.o $(OBJ)

$(OBJ)/stitching.o : $(HEADER) $(SRC)/stitching.cpp
	sudo g++ -c $(SRC)/stitching.cpp;sudo mv stitching.o $(OBJ)

clean :
	sudo rm -rf $(OBJ)/*
	sudo rm -rf $(BIN)/*
