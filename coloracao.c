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
int coloracaoVertice(int **MatAdj, int *cor, int k, int v, int numVertices) {

  if(v == numVertices)  // Caso base: se todos os vertices já estão coloridos
      return 1;

  else {
    // verifica diferente cores para o vertice v
    for(int c = 1; c <= k; c++){
      //verifica se a cor atual pode ser atribuida ao vertice
      if(verificaCor(MatAdj, cor, c, v, numVertices)) {
        cor[v] = c;
        // recursividade para colorir o restante dos vertices
        if(coloracaoVertice(MatAdj, cor, k, v+1, numVertices)){
          return 1;
        }

        /*se c não for hábil para colorir o vertice, é testado uma nova cor
          removendo a atribuição feita anteriormente (cor[v] = c)*/
        cor[v] = 0;
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
int Backtracking(int **MatAdj, int k, int src, int numVertices){

  int cor[numVertices];

  for(int i=0; i<numVertices; i++)
    cor[i]= 0;  // seta a cor de todos os vertices como 0

  // chama coloracaoVertice() a partir do vertice de origem
  return coloracaoVertice(MatAdj, cor, k, src, numVertices);
}

void insertionSort(indiceVetor* ivetor, int numVertices){
    int i, j;
    indiceVetor key;
    for (i = 1; i < numVertices; i++){
        key = ivetor[i];
        j = i - 1;
        while (j >= 0 && ivetor[j].grau < key.grau){
            ivetor[j + 1] = ivetor[j];
            j = j - 1;
        }
        ivetor[j + 1] = key;
    }
}

void inicializaVetorIndice(indiceVetor* ivetor, Grafo* gr){
    int i;
    for(i = 0; i < gr->numVertices; i++){
      ivetor[i].vertice = i;
      ivetor[i].grau = gr->grau[i];
    }
    insertionSort(ivetor,gr->numVertices);
}

int heuristica1(Grafo* gr){
  /* Primeiro, criamos um vetor de struct indiceVetor que guarda o número dos vértices
  e o seu respectivo grau. Depois, na função inicializaVetorIndice, salvamos os valores no vetor
  e ordenamos ele com a função insertionSort*/
  indiceVetor* ivetor = malloc(gr->numVertices* sizeof(indiceVetor));
  inicializaVetorIndice(ivetor,gr);
  printf("\n vetor: ");
  for(int i=0;i<gr->numVertices;i++)
    printf("%d ",ivetor[i].vertice);
}
