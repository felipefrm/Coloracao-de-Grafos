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

int verificaCor(int **MatAdj, int *cor, int corAtual, int v, int qtdVertices);
int coloracaoVertice(int **MatAdj, int *cor, int k, int vertice, int qtdVertices);
int Backtracking(Grafo* gr, int k);
int AlgoritmoExato(Grafo* gr);

void insertionSort(Vertice* V, int qtdVertices);
Vertice* inicializaVetorVertice(Grafo* gr, int caso);
int heuristica1(Grafo* gr);

int heuristica2(Grafo* gr);
void atualizaSaturacao(Grafo* gr,Vertice* V,int maisSaturado);
int novoMaisSaturado(Grafo* gr,Vertice* V);
void atribuiCor(Grafo* gr,Vertice* V,int maisSaturado);

#endif
