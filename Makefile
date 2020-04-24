CFLAGS= -W -Wall -ansi -pedantic

all: plusminus

plusminus: main.c
	gcc -o plusminus main.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf plusminus

.PHONY: all clean mrproper
