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


int ConstroiGrafo(Grafo* gr, FILE* entrada){

	int origem, destino;
	while (!feof(entrada)){
		fscanf(entrada, "%d %d\n", &origem, &destino);	// lê uma linha do arq e guarda em origem e destino
		if (!insereAresta(gr, origem, destino)) {				// insere na MatAdj na posição [origem][destino] a aresta
			fprintf(stderr, "Falha na inserção das arestas. Cheque o arquivo de entrada.\n");
			return 0;
		}
	}
	return 1;
}


int calculaGrau(Grafo* gr, int i){
	int j, grau = 0;
	for(j = 0; j < gr->qtdVertices; j++){		// calcula a quantidade de arestas
		if(gr->MatAdj[i][j])									// que o vértice contem
			grau++;
	}
	return grau;
}
