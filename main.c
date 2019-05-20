#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "coloracao.h"
#include "entradaSaida.h"

int main(int argc, char *argv[]){

  Arquivos* arq = argumentosEntrada(argc, argv);
  if (arq->flag && verificaArqVazio(arq->entrada)){
    int qtdArestas = calculaQtdArestas(arq->entrada);
    int numVertices = leNumVertices(arq->entrada);
    int **mat = leArestas(arq->entrada, qtdArestas);
    fclose(arq->entrada);
    Grafo* gr = inicializaGrafo(numVertices);

    for (int i=1; i<qtdArestas; i++)
      if (!insereAresta(gr, mat[i][0], mat[i][1])) {
        fprintf(stderr, "Falha na inserção da aresta. Cheque o arquivo de entrada.\n");
        return 0;
      }

    calculaGrau(gr);

    double utime_ant, utime_pos, stime_ant, stime_pos;
    int k = 1; // numero de cores
    contaTempoProcessador(&utime_ant, &stime_ant);
    while (1){
    if (Backtracking(gr->MatAdj, k, 0, numVertices))
      break;
    k++;
    }
    contaTempoProcessador(&utime_pos, &stime_pos);
    imprimeTempo(utime_pos-utime_ant, stime_pos-stime_ant, arq->saida);
    fprintf(arq->saida  , "%d\n", k);
    imprimeGrafo(gr, arq->saida);
    fclose(arq->saida);

    heuristica1(gr);
    liberaGrafo(gr);
  }
}
