########## Makefile ############

all: main.o grafo.o
	gcc grafo.o main.o -o tp3 -lm

main.o: main.c grafo.h
	gcc -g -c main.c
grafo.o: grafo.h grafo.c
	gcc -g -c grafo.c
