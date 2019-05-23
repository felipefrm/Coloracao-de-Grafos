#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* inicializaGrafo(int numVertices) {

	Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
	gr->numVertices = numVertices;
	gr->MatAdj = (int**)malloc(sizeof(int*) * numVertices);
	for (int i = 0; i < numVertices; i++) {
		gr->MatAdj[i] = (int*)malloc(sizeof(int) * numVertices);
		for (int j = 0; j < numVertices; j++) {
			gr->MatAdj[i][j] = FALSE;
		}
	}
	calculaGrau(gr);
	return gr;
}

void liberaGrafo(Grafo* gr) {
	int i;
	for (i = 0; i < gr->numVertices; i++) {
		free(gr->MatAdj[i]);
	}
	free(gr->MatAdj);
	free(gr->grau);
	free(gr);
}

int insereAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i <  gr->numVertices && j >= 0 && j < gr->numVertices) {
		gr->MatAdj[i][j] = TRUE;
		gr->MatAdj[j][i] = TRUE;   // grafo não direcionado
		printf("a ");
    return 1;
	}
  else {
		printf("Argumentos inválidos\n");
    return 0;
	}
}

int ConstroiGrafo(Grafo* gr, int qtdArestas, int **mat){

	for (int i=1; i<qtdArestas; i++)
		if (!insereAresta(gr, mat[i][0], mat[i][1])) {
			fprintf(stderr, "Falha na inserção da aresta. Cheque o arquivo de entrada.\n");
			return 0;
		}
	return 1;
}

//
// int verificaAresta(Grafo* gr, int i, int j) {
//
//   if (i >= 0 && i < gr->numVertices && j > 0 && j < gr->numVertices)
// 		return gr->MatAdj[i][j];
//   else
// 		return FALSE;
//
// }


void imprimeGrafo(Grafo* gr, FILE* arq){
  for (int i=0; i< gr->numVertices; i++){
    for (int j=0; j< gr->numVertices; j++){
      printf("%d ", gr->MatAdj[i][j]);
		}
    printf("\n");
  }
}



void calculaGrau(Grafo* gr){
	int i,j;
	gr->grau = calloc(sizeof(int),gr->numVertices);
	for(i = 0; i < gr->numVertices; i++){
		for(j = 0; j < gr->numVertices; j++){
			if(gr->MatAdj[i][j])
				gr->grau[i]++;
		}
	}
}
