#ifndef GRAFO
#define GRAFO

#define TRUE 1
#define FALSE 0

typedef struct grafo {
	int qtdVertices;
	int** MatAdj;        // Matriz de adjacencia
} Grafo;

Grafo* inicializaGrafo(FILE *arq);
void liberaGrafo(Grafo* gr);
int insereAresta(Grafo* gr, int i, int j);
int ConstroiGrafo(Grafo* gr, FILE* entrada, FILE* saida);
int calculaGrau(Grafo* gr, int i);

#endif
