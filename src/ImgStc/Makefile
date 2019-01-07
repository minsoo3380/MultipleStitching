SRC = ../../../src/ImgStc/single_stitching
OBJ = ../../../obj/ImgStc/single_stitching
BIN = ../../../bin/ImgStc/single_stitching

HEADER = $(SRC)/H_single_stc.hpp

FUNC_OBJ = $(OBJ)/single_stitching.o $(OBJ)/main.o

all : stitching

stitching : $(FUNC_OBJ)
	sudo g++ -o stitching $(FUNC_OBJ) `pkg-config opencv --cflags --libs`
	sudo mv -f $(@) $(BIN)/.

$(OBJ)/stc_main.o : $(HEADER) $(SRC)/stc_main.cpp
	sudo g++ -c $(SRC)/main.cpp; sudo mv main.o $(OBJ)

$(OBJ)/stitching.o : $(HEADER) $(SRC)/stitching.cpp
	sudo g++ -c $(SRC)/single_stitching.cpp;sudo mv single_stitching.o $(OBJ)

clean :
	sudo rm -rf $(OBJ)/*
	sudo rm -rf $(BIN)/*
