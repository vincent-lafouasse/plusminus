CC = gcc
CFLAGS= -std=c89
CFLAGS += -W
CFLAGS += -Wall
CFLAGS += -pedantic
EXEC = plusminus

all: $(EXEC)

plusminus: main.o
	$(CC) -o $(EXEC) $^ $(CFLAGS)

main.o: main.c
	$(CC) -o main.o -c $^ $(CFLAGS)

# $^ represents all dependancies, here it's main.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

.PHONY: all clean mrproper
