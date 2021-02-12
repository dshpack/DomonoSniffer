CC=gcc

CFLAGS=

SOURCES=src/initialize.c src/main.c

OBJ=$(SOURCES:.c=.o)

all: sniffy

sniffy: $(OBJ)
		$(CC) -o sniffy $(OBJ) && ./sniffy stop ----fhsdofh 32423423hh hehhe ehohwef ewfhweo

main.o: src/main.c
		$(CC) -c $(SOURCES)

clean:
		rm -rf src/*.o sniffy