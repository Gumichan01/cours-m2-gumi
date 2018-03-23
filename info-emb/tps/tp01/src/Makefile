
# Makefile collimaçon

CC=gcc
EXEC=collimacon
OBJ=tp1.o
SRC=tp1.c
FLAG=-m32 -Wall -Wextra -g

all: $(EXEC)

$(EXEC): $(OBJ)
	  $(CC) -o $@ $^ $(FLAG)

$(OBJ): $(SRC)
	  $(CC) -c -o $@ $^ $(FLAG)


clean:
	  rm -f $(OBJ)

clear: clean
		rm -f $(EXEC)
