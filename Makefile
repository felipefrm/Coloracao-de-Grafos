########## Makefile ############

all: main.o grafo.o entradaSaida.o
	gcc grafo.o entradaSaida.o main.o -o tp3 -lm

main.o: main.c grafo.h entradaSaida.h
	gcc -g -c main.c
grafo.o: grafo.h grafo.c
	gcc -g -c grafo.c
entradaSaida.o: entradaSaida.h entradaSaida.c
	gcc -g -c entradaSaida.c
