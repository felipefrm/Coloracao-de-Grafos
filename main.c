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

    if (ConstroiGrafo(gr, qtdArestas, mat)){

      int k;
      double utime_ant, utime_pos, stime_ant, stime_pos;

      contaTempoProcessador(&utime_ant, &stime_ant);
      k = AlgoritmoExato(gr->MatAdj, numVertices);
      contaTempoProcessador(&utime_pos, &stime_pos);
      imprimeTempo(utime_pos-utime_ant, stime_pos-stime_ant, arq->saida);
      fprintf(arq->saida  , "%d\n", k);


      contaTempoProcessador(&utime_ant, &stime_ant);
      k = heuristica1(gr);
      contaTempoProcessador(&utime_pos, &stime_pos);
      imprimeTempo(utime_pos-utime_ant, stime_pos-stime_ant, arq->saida);
      fprintf(arq->saida  , "%d\n", k);

      fclose(arq->saida);
    }
    liberaGrafo(gr);
    liberaArquivos(arq);
  }
}
