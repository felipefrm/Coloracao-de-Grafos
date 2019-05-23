/*
Undirected Grafo
Adjacency Matrix
Felipe Scrochio Custódio
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>


#define TRUE 1
#define FALSE 0

typedef struct grafo {
	int vertice;
	int aresta;
	int** MatAdj;        // Matriz de adjacencia
} Grafo;

typedef struct arquivos {
  FILE* entrada;
  FILE* saida;
  int flag;   // flag para poder retornar 0 em caso de erro
} Arquivos;

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


Grafo* inicializaGrafo(int numVertices) {

	Grafo* gr = (Grafo*)malloc(sizeof(Grafo));
	gr->vertice = numVertices;
  gr->aresta = 0;
	gr->MatAdj = (int**)malloc(sizeof(int*) * numVertices);
	for (int i = 0; i < numVertices; i++) {
		gr->MatAdj[i] = (int*)malloc(sizeof(int) * numVertices);
		for (int j = 0; j < numVertices; j++) {
			gr->MatAdj[i][j] = FALSE;
		}
	}
	return gr;
}

int insereAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i <  gr->vertice && j > 0 && j < gr->vertice) {
		gr->MatAdj[i][j] = TRUE;
		gr->MatAdj[j][i] = TRUE;   // grafo não direcionado
	}
  else {
		printf("Argumentos inválidos\n");
	}
}

void removeAresta(Grafo *gr, int i, int j) {
	if (i >= 0 && i <  gr->vertice && j > 0 && j < gr->vertice) {
		gr->MatAdj[i][j] = FALSE;
		gr->MatAdj[j][i] = FALSE;  // grafo não direcionado
	}
  else {
    printf("Argumentos inválidos\n");
	}
}

int verificaAresta(Grafo* gr, int i, int j) {

  if (i >= 0 && i < gr->vertice && j > 0 && j < gr->vertice)
		return gr->MatAdj[i][j];
  else
		return FALSE;

}

void imprimeGrafo(Grafo* gr, int numVertices){
  for (int i=0; i<numVertices; i++){
    for (int j=0; j<numVertices; j++)
      printf("%d ", gr->MatAdj[i][j]);
    printf("\n");
  }
}

void liberaGrafo(Grafo* gr) {
	int i;
	for (i = 0; i < gr->vertice; i++) {
		free(gr->MatAdj[i]);
	}
	free(gr->MatAdj);
	free(gr);
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
          // printf("%d ", mat[i][0]);
        }
        if (j == 2){

          mat[i][1] = c - 48;
          // printf("%d\n", mat[i][1]);
        }

    }
    fscanf(arq, "\n");
  }
  return mat;
}


int main(int argc, char *argv[]) {
  Arquivos* arq = argumentosEntrada(argc, argv);
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

      insereAresta(gr, mat[i][0], mat[i][1]);

    }

    imprimeGrafo(gr, numVertices);
  liberaGrafo(gr);
	return 0;
}
