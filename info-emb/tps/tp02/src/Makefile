
# Makefile collimaçon

CC=gcc
EXEC=collimacon
TEST=test-collimacon
STATIC_LIB=collimacon.a
DYNAMIC_LIB=collimacon.so
OBJCOLI=collimacon.o
SRCCOLI=collimacon.c
SRCMAIN=tp2.c
OBJMAIN=tp2.o
SRCTEST=collimacon-test.c
OBJTEST=collimacon-test.o
OBJS=$(OBJMAIN) $(OBJTEST) $(OBJCOLI)
CFLAGS=-m32 -fPIC -Wall -g

all: $(STATIC_LIB) $(DYNAMIC_LIB) $(EXEC) $(TEST)

$(EXEC): $(OBJMAIN) $(STATIC_LIB)
	  $(CC) -o $@ $^ $(CFLAGS)

$(TEST): $(OBJTEST) $(STATIC_LIB)
	  $(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
		$(CC) -c -o $@ $< $(CFLAGS)

$(STATIC_LIB): $(OBJCOLI)
		ar -cvq $@ $<

$(DYNAMIC_LIB): $(OBJCOLI)
		$(CC) $(CFLAGS) -shared -o $@ $<

clean:
	  rm -f $(OBJS)

clear: clean
		rm -f $(EXEC) $(TEST) $(STATIC_LIB) $(DYNAMIC_LIB)
