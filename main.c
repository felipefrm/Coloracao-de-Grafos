#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, char *argv[]){

  Arquivos* arq = argumentosEntrada(argc, argv);
  if (arq->flag && verificaArqVazio(arq->entrada)){
    int qtdArestas = calculaQtdArestas(arq->entrada);
    int numVertices = leNumVertices(arq->entrada);
    int **mat = leArestas(arq->entrada, qtdArestas);
    fclose(arq->entrada);
    printf("opa");
    Grafo* gr = cria_Grafo(numVertices, 10);

    for (int i=0; i<qtdArestas; i++)
        insereAresta(gr, mat[i][0], mat[i][1]);

    imprime_Grafo(gr, arq->saida);
    fclose(arq->saida);

    libera_Grafo(gr);
  }
}
