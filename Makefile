########## Makefile ############

all: main.o grafo.o coloracao.o entradaSaida.o
	gcc grafo.o coloracao.o entradaSaida.o main.o -o tp3 -lm

main.o: main.c grafo.h coloracao.h entradaSaida.h
	gcc -g -c main.c
grafo.o: grafo.h grafo.c
	gcc -g -c grafo.c
coloracao.o: coloracao.h coloracao.c
	gcc -g -c coloracao.c
entradaSaida.o: entradaSaida.h entradaSaida.c
	gcc -g -c entradaSaida.c
