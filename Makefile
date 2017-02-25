CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=
EXEC=stack

all: $(EXEC)

stack: stack.o
	$(CC) -o stack stack.o $(LDFLAGS)

stack.o: stack.c
	$(CC) -o stack.o -c stack.c $(CFLAGS)

clean:
	rm -rf *.o
