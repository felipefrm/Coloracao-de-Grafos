#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "coloracao.h"
#include "entradaSaida.h"


void main(int argc, char *argv[]){

  Arquivos* arq = argumentosEntrada(argc, argv);
  if (arq->flag && verificaArqVazio(arq->entrada)){

    Grafo* gr = inicializaGrafo(arq->entrada);
    if (ConstroiGrafo(gr, arq->entrada)){

      int k, opcao;
      double utime_ant, utime_pos, stime_ant, stime_pos;

      printf("Escolha um algoritmo para imprimir o menor número de cores necessárias para colorir o grafo:\n\n");
      printf("[0] Todos os algoritmos\n[1] Força Bruta (backtracking)\n[2] Heuristica 1\n[3] Heuristica 2\n\n>>> ");
      scanf("%d", &opcao);

      switch (opcao){

        case 0:
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = AlgoritmoExato(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 1, arq->saida);
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = heuristica1(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 2, arq->saida);
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = heuristica2(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 3, arq->saida);
          break;

        case 1:
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = AlgoritmoExato(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 0, arq->saida);
          break;

        case 2:
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = heuristica1(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 0, arq->saida);
          break;

        case 3:
          contaTempoProcessador(&utime_ant, &stime_ant);
          k = heuristica2(gr);
          contaTempoProcessador(&utime_pos, &stime_pos);
          imprimeSaida(utime_pos-utime_ant, stime_pos-stime_ant, k, 0, arq->saida);
          break;

        default:
          printf("Não existe esta opção.\n");
      }
    }
    liberaGrafo(gr);
    liberaArquivos(arq);
  }
}
