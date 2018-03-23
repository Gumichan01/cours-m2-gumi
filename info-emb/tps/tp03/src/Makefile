
# Makefile tp03

CC=gcc
ARMCC=arm-linux-gnueabi-gcc
EXEC=hello
EXEC_ARM=hello_arm
OBJ=hello.o
SRC=hello.c
FLAG=-m32 -Wall -Wextra -static
ARM_FLAG=-Wall -Wextra -static
DYM=yes

ifeq ($(DYM),yes)
		FLAG= -m32 -Wall -Wextra
		ARM_FLAG=-Wall -Wextra
endif

all: $(EXEC) $(EXEC_ARM)

$(EXEC): $(OBJ)
	  $(CC) -o $@ $^ $(FLAG)

$(EXEC_ARM): $(SRC)
	  $(ARMCC) -o $@ $^ $(ARM_FLAG)

$(OBJ): $(SRC)
	  $(CC) -c -o $@ $^ $(FLAG)


clean:
	  rm -f $(OBJ)

mrproper: clean
		rm -f $(EXEC) $(EXEC_ARM)
