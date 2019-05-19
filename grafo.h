#ifndef GRAFO
#define GRAFO

// struct grafo {
//     int numVertices;
//     int grau_max;
//     int** arestas;
//     int* grau;
//     int cor;
// }; typedef struct grafo Grafo;

#define TRUE 1
#define FALSE 0

typedef struct grafo {
	int vertice;
	int aresta;
	int** MatAdj;        // Matriz de adjacencia
} Grafo;


Grafo* inicializaGrafo(int numVertices);
void liberaGrafo(Grafo* gr);
int insereAresta(Grafo* gr, int i, int j);
int removeAresta(Grafo* gr, int i, int j);
void imprimeGrafo(Grafo* gr, int numVertices, FILE* arq);



#endif
