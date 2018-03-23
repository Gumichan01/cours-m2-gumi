
# Makefile tp n°5

CC=gcc
EXEC=thprio
OBJ=tp5.o
SRC=tp5.c
FLAG=-m32 -O0 -static -Wall -Wextra -g -pthread

all: $(EXEC)

$(EXEC): $(OBJ)
	  $(CC) -o $@ $^ $(FLAG)

$(OBJ): $(SRC)
	  $(CC) -c -o $@ $^ $(FLAG)

clean:
	  rm -f $(OBJ)

mrproper: clean
		rm -f $(EXEC)
