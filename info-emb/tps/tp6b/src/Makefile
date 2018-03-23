
CC=gcc
CFLAGS=-Wall -g -Wextra -m32 -std=gnu99
OBJ_LIST=list.o tp6_list.o
OBJ_HASH=list.o hash.o tp6_hash.o
EXEC_LIST=test-list
EXEC_HASH=test-hash

all: $(EXEC_LIST) $(EXEC_HASH)

$(EXEC_LIST): $(OBJ_LIST)
	$(CC) $(CFLAGS) $^ -o $@

$(EXEC_HASH): $(OBJ_HASH)
	$(CC) $(CFLAGS) $^ -o $@

tp6_list.o: tp6_list.c
	$(CC) -c $(CFLAGS) $< -o $@

tp6_hash.o: tp6_hash.c
	$(CC) -c $(CFLAGS) $< -o $@

list.o: list.c list.h
	$(CC) -c $(CFLAGS) $< -o $@

hash.o: hash.c hash.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC_LIST) $(EXEC_HASH)
