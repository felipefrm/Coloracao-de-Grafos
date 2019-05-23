#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// int calculaQtdArestas(FILE* arq){
//   int qtdArestas = -1; // a primeira linha não é uma aresta, por isso -> (-1)
//   while (!feof(arq))
//     if (fgetc(arq) == '\n' || feof(arq))                     // calcula a quantidade de veiculos
//       qtdArestas++;                                          // por meio da quantidade de '\n'
//   rewind(arq);
//   return qtdArestas;
// }
//
// int leNumVertices(FILE *arq){
//   int qtdAlgarismo = 0;
//   while (fgetc(arq) != '\n')  // quantidade de algarismos na primeira linha do arquivo
//     qtdAlgarismo++;           // onde está o número de vertices, para alocar
//   rewind(arq);                // a quantidade certa de memoria para receber o valor
//
//   char num_char[qtdAlgarismo+1];
//   fgets(num_char, sizeof(num_char), arq); // lê do arq a primeira linha e guarda em num_char
//
//   int num_int = 0;
//   for (int i = qtdAlgarismo, j = 0; i>0; i--, j++){ // transforma char em int
//     num_int += (num_char[j]-48) * pow(10, i-1);     // num * 10^i
//   }
//
//   return num_int;
// }
//
// int** alocaMatriz(int qtdArestas){
//
//   int **matriz = (int**)malloc(qtdArestas*sizeof(int*));
//   for (int i=0; i<qtdArestas; i++)
//     matriz[i] = (int*)malloc(qtdArestas*sizeof(int));
//
//   return matriz;
// }
//
// int leArestas(FILE *arq, int qtdArestas){
//   int **mat = alocaMatriz(qtdArestas);
//   char c;
//   for (int i=0; i < qtdArestas; i++){
//     for (int j=0; (c = fgetc(arq)) != '\n' && !feof(arq); j++){
//         if (j == 0){
//
//           mat[i][0] = c - 48;
//           printf("%d ", mat[i][0]);
//         }
//         if (j == 2){
//
//           mat[i][1] = c - 48;
//           printf("%d\n", mat[i][1]);
//         }
//
//     }
//     fscanf(arq, "\n");
//   }
//   return (int**)mat;
// }
//

    int** alocaMatriz(int linha, int coluna){

      int **matriz = (int**)malloc(linha*sizeof(int*));
      for (int i=0; i<linha; i++)
        matriz[i] = (int*)malloc(coluna*sizeof(int));

      return matriz;
    }



void main(){

  int **mat = alocaMatriz(5, 2);
  for (int i=0; i<5; i++){
    for (int j=0; j<2; j++){
      printf("%d ", mat[j][j]);
    }
    printf("\n");
  }
}
