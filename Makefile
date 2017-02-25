CC=gcc
CFLAGS=-W -Wall -pedantic
LDFLAGS=
EXEC=stack

all: $(EXEC)

stack: main.o stack.o ui.o exercises.o
	$(CC) -o bin/stack obj/main.o obj/stack.o obj/exercises.o obj/ui.o

main.o: src/main.c
	$(CC) -o obj/main.o -c src/main.c $(CFLAGS)

stack.o: src/stack.c
	$(CC) -o obj/stack.o -c src/stack.c $(CFLAGS)

ui.o: src/ui.c
	$(CC) -o obj/ui.o -c src/ui.c $(CFLAGS)

exercises.o: src/exercises.c
	$(CC) -o obj/exercises.o -c src/exercises.c $(CFLAGS)

clean:
	rm -rf obj/*.o
