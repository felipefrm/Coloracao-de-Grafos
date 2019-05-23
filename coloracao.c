#include <stdio.h>
#include <stdlib.h>
#include "coloracao.h"
#include "grafo.h"

/* Função utilitaria que verifica se a cor atribuida é possível para o vertice.
   Isto é, checa se a aresta existe ou não (MatAdj[v][i] == 1), se existe, então é
   verificado se a cor a ser atribuida ao vertice atual já foi usado por um outro
   vertice adjacente ou não (veticeAtual == cor[i]) */
int verificaCor(int **MatAdj, int *cor, int corAtual, int v, int numVertices){

  for(int i=0; i<numVertices; i++) // Checando se algum vertice adjacente tem a mesma cor
    if(MatAdj[v][i] && corAtual == cor[i])
      return 0;
  return 1;
}

// Função recursiva que retorna no fim o valor minimo k de cor para dado grafo
int coloracaoVertice(int **MatAdj, int *cor, int k, int vertice, int numVertices) {

  if(vertice == numVertices)  // Caso base: se todos os vertices já estão coloridos
      return 1;

  else {
    // verifica diferente cores para o vertice
    for(int c = 1; c <= k; c++){
      //verifica se a cor atual pode ser atribuida ao vertice
      if(verificaCor(MatAdj, cor, c, vertice, numVertices)) {
        cor[vertice] = c;
        // recursividade para colorir o restante dos vertices
        if(coloracaoVertice(MatAdj, cor, k, vertice+1, numVertices)){
          return 1;
        }

        /*se c não for hábil para colorir o vertice, é testado uma nova cor
          removendo a atribuição feita anteriormente (cor[vertice] = c)*/
        cor[vertice] = 0;
      }
    }
    /* se todas as cores forem verificas e não foi possível colorir todo o gráfico
       então conclui-se que não é possível colorir o grafico com k cores */
    return 0;
  }
}


/* Esta função resolve o problema de coloração de grafo usando a estratégia
   Backtracking. É usado recursivimente ColouringUtil() para resolver o problema
   A função retorna falso caso não seja possivel colorir com k cores e true
   se for possível. */
int Backtracking(int **MatAdj, int k, int numVertices){

  // seta a cor de todos os vertices como 0
  int *cor = calloc(numVertices, sizeof(int));
  // chama coloracaoVertice() a partir do vertice de origem
  return coloracaoVertice(MatAdj, cor, k, 0, numVertices);
}

int AlgoritmoExato(Grafo * gr){
  int k = 1;
  while (1){                                            // Algoritmo de força bruta que
  if (Backtracking(gr->MatAdj, k, gr->numVertices))     // traz sempre a solução ótima
    break;
  k++;
  }
  return k;
}

void insertionSort(Vertice* V, int numVertices){
    int i, j;
    Vertice key;
    for (i = 1; i < numVertices; i++){
        key = V[i];
        j = i - 1;
        while (j >= 0 && V[j].grau < key.grau){
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = key;
    }
}

Vertice* inicializaVetorVertice(Grafo* gr){
  Vertice* V = malloc(gr->numVertices* sizeof(Vertice));
    for(int i = 0; i < gr->numVertices; i++){
      V[i].id = i;
      V[i].corDefinitiva = FALSE;
      V[i].cor = 0;
      V[i].grau = calculaGrau(gr, i);
    }
    insertionSort(V, gr->numVertices);
    return V;
}

int heuristica1(Grafo* gr){
  /* Primeiro, criamos um vetor de struct Vertice que guarda o número dos vértices
  e o seu respectivo grau. Depois, na função inicializaVetor, salvamos os valores no vetor
  e ordenamos ele com a função insertionSort*/
  Vertice* V = inicializaVetorVertice(gr);
  int k = 1;
  for(int i=0; i < gr->numVertices; i++){
    V[i].corDefinitiva = TRUE;
    V[i].cor = 1;
    int controle = 0;
    while(V[i].cor > controle){
      for(int j = 0; j < gr->numVertices; j++){
        if(gr->MatAdj[V[i].id][V[j].id] && V[i].cor == V[j].cor){
          V[i].cor++;
          break;
        }
      }
      controle++;
    }

    for(int j = 0; j < gr->numVertices; j++){
      if(gr->MatAdj[V[i].id][V[i].id] && !V[j].corDefinitiva){
        V[j].cor = V[i].cor ;
      }
    }
    if(V[i].cor > k)
      k = V[i].cor;
      // for(int i=0;i<gr->numVertices;i++)
      //   printf("%d cor: %d\n",V[i].id,V[i].cor);
      //   printf("\n");
  }
  for(int i=0;i<gr->numVertices;i++)
    printf("%d cor: %d\n",V[i].id,V[i].cor);
  free(V);
  return k;
}
