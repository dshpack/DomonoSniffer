CC=gcc

CFLAGS=

SOURCES=src/main.c

OBJECTS=$(SOURCES:.c=.o)

all: sniffy

sniffy: main.o
		$(CC) -o sniffy main.o && ./sniffy

main.o: src/main.c
		$(CC) -c $(SOURCES)

clean:
		rm -f *.o sniffy