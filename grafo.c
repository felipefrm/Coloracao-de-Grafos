#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

// Grafo* criaGrafo(int numVertices, int grau_max){
//     Grafo *gr;
//     gr = (Grafo*) malloc(sizeof(struct grafo));
//     if(gr != NULL){
//         int i;
//         gr->numVertices = numVertices;
//         gr->grau_max = grau_max;
//         gr->grau = (int*) calloc(numVertices,sizeof(int));
//
//         gr->arestas = (int**) malloc(numVertices * sizeof(int*));
//         for(i=0; i<numVertices; i++)
//             gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));
//
//     }
//     return gr;
// }

Grafo* inicializaGrafo(int numVertices) {

	Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
	gr->vertice = numVertices;
  gr->aresta = 0;
	gr->MatAdj = (int**)malloc(sizeof(int*) * numVertices);
	for (int i = 0; i < numVertices; i++) {
		gr->MatAdj[i] = (int*)malloc(sizeof(int) * numVertices);
		for (int j = 0; j < numVertices; j++) {
			gr->MatAdj[i][j] = FALSE;
		}
	}
	return gr;
}

// void liberaGrafo(Grafo* gr){
//     if(gr != NULL){
//         int i;
//         for(i=0; i<gr->numVertices; i++)
//             free(gr->arestas[i]);
//         free(gr->arestas);
//
//         }
//         free(gr->grau);
//         free(gr);
//     }

void liberaGrafo(Grafo* gr) {
	int i;
	for (i = 0; i < gr->vertice; i++) {
		free(gr->MatAdj[i]);
	}
	free(gr->MatAdj);
	free(gr);
}

// int insereAresta(Grafo* gr, int orig, int dest){
//     if(gr == NULL){
//       printf("a1");
//       return 0;
//     }
//     if (orig == dest){
//       printf("a2");
//
//       return 0;
//     }
//     if(orig < 0 || orig >= gr->numVertices){
//       printf("a3");
//
//       return 0;                             // verifica se o vertice existe
//     }
//     if(dest < 0 || dest >= gr->numVertices){
//       printf("a4");
//
//       return 0;
//     }
//     if (gr->grau[orig] == gr->grau_max || gr->grau[dest] == gr->grau_max){
//       printf("a5");
//
//       return 0;
//     }     // limite de arestas para o vertice
//     gr->arestas[orig][gr->grau[orig]] = dest; // cria uma aresta entre v1 e v2
//     gr->arestas[dest][gr->grau[dest]] = orig; // cria uma aresta entre v2 e v1
//                                               // conceito de grafo não direcionado
//     gr->grau[orig]++;
//     gr->grau[dest]++;
//
//     // printf("opa\n");
//     return 1;
// }

int insereAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i <  gr->vertice && j > 0 && j < gr->vertice) {
		gr->MatAdj[i][j] = TRUE;
		gr->MatAdj[j][i] = TRUE;   // grafo não direcionado
    return 1;
	}
  else {
		printf("Argumentos inválidos\n");
    return 0;
	}
}

// int removeAresta(Grafo* gr, int orig, int dest){
//     if(gr == NULL)
//         return 0;
//     if(orig < 0 || orig >= gr->numVertices)
//         return 0;
//     if(dest < 0 || dest >= gr->numVertices)
//         return 0;
//
//     int i = 0;
//     while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
//         i++;
//     if(i == gr->grau[orig])//elemento nao encontrado
//         return 0;
//     gr->grau[orig]--;
//     gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
//      return 1;
// }

int removeAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i <  gr->vertice && j > 0 && j < gr->vertice) {
		gr->MatAdj[i][j] = FALSE;
		gr->MatAdj[j][i] = FALSE;  // grafo não direcionado
	}
  else {
    printf("Argumentos inválidos\n");
	}
}

int verificaAresta(Grafo* gr, int i, int j) {

  if (i >= 0 && i < gr->vertice && j > 0 && j < gr->vertice)
		return gr->MatAdj[i][j];
  else
		return FALSE;

}

// void imprimeGrafo(Grafo *gr, FILE* arq){
//     if(gr == NULL)
//         return;
//
//     int i, j;
//     for(i=0; i < gr->numVertices; i++){
//         fprintf(arq, "%d: ", i);
//         for(j=0; j < gr->grau[i]; j++){
//                  fprintf(arq, "%d, ", gr->arestas[i][j]);
//         }
//         fprintf(arq, "\n");
//     }
// }

void imprimeGrafo(Grafo* gr, int numVertices, FILE* arq){
  for (int i=0; i<numVertices; i++){
    for (int j=0; j<numVertices; j++)
      printf("%d ", gr->MatAdj[i][j]);
    printf("\n");
  }
}
