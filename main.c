#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "entradaSaida.h"

int main(int argc, char *argv[]){

  Arquivos* arq = argumentosEntrada(argc, argv);
  if (arq->flag && verificaArqVazio(arq->entrada)){
    int qtdArestas = calculaQtdArestas(arq->entrada);
    int numVertices = leNumVertices(arq->entrada);
    int **mat = leArestas(arq->entrada, qtdArestas);
    fclose(arq->entrada);
    Grafo* gr = inicializaGrafo(numVertices);
    printf("qtd: %d\n", qtdArestas);
    // for (int i=0; i<qtdArestas; i++)
    //   for (int j=0; j<2; j++)
    //     printf("%d ", mat[i][j]);
    //   printf("\n");

    for (int i=1; i<qtdArestas; i++){

        if (!insereAresta(gr, mat[i][0], mat[i][1])) {
          fprintf(stderr, "Falha na inserção da aresta. Cheque o arquivo de entrada.\n");
          return 0;
        }
      }

    imprimeGrafo(gr, numVertices, arq->saida);
    fclose(arq->saida);

    liberaGrafo(gr);
  }
}
