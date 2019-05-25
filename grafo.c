#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "entradaSaida.h"

Grafo* inicializaGrafo(FILE* arq) {

	Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
	gr->qtdVertices = leQtdVertices(arq);
	gr->MatAdj = alocaMatriz(gr->qtdVertices, gr->qtdVertices);
	return gr;
}

void liberaGrafo(Grafo* gr) {
	for (int i = 0; i < gr->qtdVertices; i++)
		free(gr->MatAdj[i]);
	free(gr->MatAdj);
	free(gr);
}

int insereAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i < gr->qtdVertices && j >= 0 && j < gr->qtdVertices) {
		gr->MatAdj[i][j] = TRUE;
		gr->MatAdj[j][i] = TRUE;   // grafo não direcionado
    return 1;
	}
  return 0;
}

int ConstroiGrafo(Grafo* gr, FILE* entrada, FILE* saida){

	int origem, destino;
	while (!feof(entrada)){
		fscanf(entrada, "%d %d\n", &origem, &destino);
		printf("%d e %d\n", origem, destino);
		if (!insereAresta(gr, origem, destino)) {
			fprintf(saida, "Falha na inserção das arestas. Cheque o arquivo de entrada.\n");
			return 0;
		}
	}
	return 1;
}


void imprimeGrafo(Grafo* gr, FILE* arq){
  for (int i=0; i< gr->qtdVertices; i++){
    for (int j=0; j< gr->qtdVertices; j++){
      printf("%d ", gr->MatAdj[i][j]);
		}
    printf("\n");
  }
}


int calculaGrau(Grafo* gr, int i){
	int j, grau=0;
	for(j = 0; j < gr->qtdVertices; j++){
		if(gr->MatAdj[i][j])
			grau++;
	}
	return grau;
}
