#ifndef COLORACAO
#define COLORACAO
#include "grafo.h"

typedef struct vertice {
	int id;
	int grau;
  int cor;
  int corDefinitiva
} Vertice;

int verificaCor(int **MatAdj, int *cor, int corAtual, int v, int numVertices);
int coloracaoVertice(int **MatAdj, int *cor, int k, int v, int numVertices);
int Backtracking(int **MatAdj, int k, int src, int numVertices);
void insertionSort(Vertice* V, int numVertices);
Vertice* inicializaVetorIndice(Grafo* gr);
int heuristica1(Grafo* gr);

#endif
