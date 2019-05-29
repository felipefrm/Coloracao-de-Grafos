#ifndef COLORACAO
#define COLORACAO
#include "grafo.h"

typedef struct vertice {
	int id;
  int cor;
  int corDefinitiva;
	int grauAresta;
	int grauSaturacao;
} Vertice;

// Força bruta
int verificaCor(int **MatAdj, int *cor, int corAtual, int vertice, int qtdVertices);
int coloracaoVertice(int **MatAdj, int *cor, int k, int vertice, int qtdVertices);
int Backtracking(Grafo* gr, int k);
int AlgoritmoExato(Grafo* gr);

// Heuristicas
Vertice* inicializaVetorVertice(Grafo* gr, int caso);
void atribuiCor(Grafo* gr, Vertice* V, int node, int heuristica);
void insertionSort(Vertice* V, int qtdVertices);
int heuristica1(Grafo* gr);
int heuristica2(Grafo* gr);
void atualizaSaturacao(Grafo* gr, Vertice* V, int maisSaturado);
int novoMaisSaturado(Grafo* gr, Vertice* V);

#endif
