#ifndef GRAFO
#define GRAFO

#define TRUE 1
#define FALSE 0

typedef struct grafo {
	int numVertices;
	int** MatAdj;        // Matriz de adjacencia
	int* grau;
} Grafo;

Grafo* inicializaGrafo(int numVertices);
void liberaGrafo(Grafo* gr);
int insereAresta(Grafo* gr, int i, int j);
int ConstroiGrafo(Grafo* gr, int qtdArestas, int **mat);
void calculaGrau(Grafo* gr);
void imprimeGrafo(Grafo* gr, FILE* arq);

#endif
