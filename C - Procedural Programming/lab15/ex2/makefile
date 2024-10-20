CC = gcc
CFLAGS = -Wall -std=c99
OBJS = lista.o lista_main.o

all: lista

lista: $(OBJS)
	$(CC) $(CFLAGS) -o lista $(OBJS)

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

lista_main.o: lista_main.c lista.h
	$(CC) $(CFLAGS) -c lista_main.c

clean:
	rm -f *.o lista
