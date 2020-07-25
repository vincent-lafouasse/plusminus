CC = gcc
CFLAGS= -std=c89
CFLAGS += -W
CFLAGS += -Wall
CFLAGS += -pedantic
EXEC = plusminus

all: $(EXEC)

plusminus: main.c
	$(CC) -o $(EXEC) $^ $(CFLAGS)

# $^ represents all dependancies, here it's main.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

.PHONY: all clean mrproper
