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
int removeAresta(Grafo* gr, int i, int j);
void imprimeGrafo(Grafo* gr, FILE* arq);
void calculaGrau(Grafo *gr);


#endif
