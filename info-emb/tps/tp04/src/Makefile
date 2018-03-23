
# Makefile TP n°4

CC=gcc
EXEC_CP=context_switch_proc
EXEC_CT=context_switch_th
EXEC_P=bench_proc
EXEC_T=bench_thread
FLAG=-Wall -Wextra -O0 -lrt -lm
PTHREAD_FLAG=-pthread

all: $(EXEC_P) $(EXEC_T) $(EXEC_CP) $(EXEC_CT)

$(EXEC_CT): bench_context_thread.o
	$(CC) -o $@ $^ $(FLAG) $(PTHREAD_FLAG)

$(EXEC_CP): bench_context_proc.o
	$(CC) -o $@ $^ $(FLAG) $(PTHREAD_FLAG)

$(EXEC_P): bench_proc.o
	$(CC) -o $@ $^ $(FLAG)

$(EXEC_T): bench_thread.o
	$(CC) -o $@ $^ $(FLAG) $(PTHREAD_FLAG)

%.o: %.c
	$(CC) -c -o $@ $^ $(FLAG)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC_P) $(EXEC_T) $(EXEC_CP) $(EXEC_CT)
