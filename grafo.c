#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <math.h>
#include "grafo.h"

Arquivos* argumentosEntrada(int argc, char* argv[]){

  Arquivos* arq = malloc(sizeof(Arquivos));   // armazena os ponteiros dos arquivos
  int opcao;
  arq->flag = 1;                                  // passados por linha de comando em uma struct
  if (argc < 5){
    fprintf(stderr, "Use: ./tp3 -i [ARQUIVO DE ENTRADA DE DADOS] -o [ARQUIVO DE SAIDA]\n");
    arq->flag = 0;
    return arq;
  }
  while((opcao = getopt(argc, argv, "i:o:"))!= -1) { // recebe-se os argumentos por meio
                                                     // da funcao getopt()
    switch(opcao) {
      case 'i':
        if(!(arq->entrada = fopen(optarg, "r"))) {
          fprintf(stderr, "Erro na abertura do arquivo.\n");
          arq->flag = 0;
          return arq;
        }
        break;
      case 'o':
        if(!(arq->saida = fopen(optarg, "w"))) {
          fprintf(stderr, "Erro na abertura do arquivo.\n");
          arq->flag = 0;
          return arq;
        }
    }
  }
  return arq;
}

int verificaArqVazio(FILE* arq){
  int tamanho_arq;
  fseek (arq, 0, SEEK_END);               // aponta para o fim do arquivo com fseek()
  if((tamanho_arq = ftell (arq)) == 0){   // retorna o valor da posição do ponteiro com ftell()
    fprintf(stderr, "O arquivo de entrada está vazio!\n");
    return 0;
  }
  rewind(arq);   // retorna o ponteiro para o inicio do arquivo, para os proximos
  return 1;      // procedimentos
}


int calculaQtdArestas(FILE* arq){
  int qtdArestas = -1; // a primeira linha não é uma aresta, por isso -> (-1)
  while (!feof(arq))
    if (fgetc(arq) == '\n' || feof(arq))                     // calcula a quantidade de veiculos
      qtdArestas++;                                          // por meio da quantidade de '\n'
  rewind(arq);
  return qtdArestas;
}

int leNumVertices(FILE *arq){
  int qtdAlgarismo = 0;
  while (fgetc(arq) != '\n')  // quantidade de algarismos na primeira linha do arquivo
    qtdAlgarismo++;           // onde está o número de vertices, para alocar
  rewind(arq);                // a quantidade certa de memoria para receber o valor

  char num_char[qtdAlgarismo+1];
  fgets(num_char, sizeof(num_char), arq); // lê do arq a primeira linha e guarda em num_char
  int num_int = 0;
  for (int i = qtdAlgarismo, j = 0; i>0; i--, j++){ // transforma char em int
    num_int += (num_char[j]-48) * pow(10, i-1);     // num * 10^i
  }

  return num_int;
}

int** alocaMatriz(int linha, int coluna){

  int **matriz = (int**)malloc(linha*sizeof(int*));
  for (int i=0; i<linha; i++)
    matriz[i] = (int*)malloc(coluna*sizeof(int));

  return matriz;
}

int** leArestas(FILE *arq, int qtdArestas){
  int **mat = alocaMatriz(qtdArestas, 2);
  char c;
  for (int i=0; i < qtdArestas; i++){
    for (int j=0; (c = fgetc(arq)) != '\n' && !feof(arq); j++){
        if (j == 0){

          mat[i][0] = c - 48;
          printf("%d ", mat[i][0]);
        }
        if (j == 2){

          mat[i][1] = c - 48;
          printf("%d\n", mat[i][1]);
        }

    }
    fscanf(arq, "\n");
  }
  return mat;
}


Grafo* criaGrafo(int numVertices, int grau_max){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->numVertices = numVertices;
        gr->grau_max = grau_max;
        gr->grau = (int*) calloc(numVertices,sizeof(int));

        gr->arestas = (int**) malloc(numVertices * sizeof(int*));
        for(i=0; i<numVertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

    }
    return gr;
}

void liberaGrafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->numVertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        }
        free(gr->grau);
        free(gr);
    }


int insereAresta(Grafo* gr, int orig, int dest){
    if(gr == NULL){
      printf("a1");
      return 0;
    }
    if (orig == dest){
      printf("a2");

      return 0;
    }
    if(orig < 0 || orig >= gr->numVertices){
      printf("a3");

      return 0;                             // verifica se o vertice existe
    }
    if(dest < 0 || dest >= gr->numVertices){
      printf("a4");

      return 0;
    }
    if (gr->grau[orig] == gr->grau_max || gr->grau[dest] == gr->grau_max){
      printf("a5");

      return 0;
    }     // limite de arestas para o vertice
    gr->arestas[orig][gr->grau[orig]] = dest; // cria uma aresta entre v1 e v2
    gr->arestas[dest][gr->grau[dest]] = orig; // cria uma aresta entre v2 e v1
                                              // conceito de grafo não direcionado
    gr->grau[orig]++;
    gr->grau[dest]++;

    // printf("opa\n");
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->numVertices)
        return 0;
    if(dest < 0 || dest >= gr->numVertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
     return 1;
}

void imprimeGrafo(Grafo *gr, FILE* arq){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->numVertices; i++){
        fprintf(arq, "%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
                 fprintf(arq, "%d, ", gr->arestas[i][j]);
        }
        fprintf(arq, "\n");
    }
}
