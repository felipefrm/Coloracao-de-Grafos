#ifndef COLORACAO
#define COLORACAO
#include "grafo.h"

typedef struct indicevetor {
  int vertice;
  int grau;
} indiceVetor;

int verificaCor(int **MatAdj, int *cor, int corAtual, int v, int numVertices);
int coloracaoVertice(int **MatAdj, int *cor, int k, int v, int numVertices);
int Backtracking(int **MatAdj, int k, int src, int numVertices);
void insertionSort(indiceVetor* ivetor, int numVertices);
void inicializaVetorIndice(indiceVetor* ivetor, Grafo* gr);
int heuristica1(Grafo* gr);
#endif
