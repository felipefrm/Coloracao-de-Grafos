#ifndef GRAFO
#define GRAFO

struct arquivos {
  FILE* entrada;
  FILE* saida;
  int flag;   // flag para poder retornar 0 em caso de erro
}; typedef struct arquivos Arquivos;

struct grafo {
    int nro_vertices;
    int grau_max;
    int** arestas;
    int* grau;
    int cor;
}; typedef struct grafo Grafo;

Grafo* cria_Grafo(int nro_vertices, int grau_max);
void libera_Grafo(Grafo* gr);
int insereAresta(Grafo* gr, int orig, int dest);
int removeAresta(Grafo* gr, int orig, int dest);
void imprime_Grafo(Grafo *gr, FILE* arq);

int** alocaMatriz(int qtdArestas);
Arquivos* argumentosEntrada(int argc, char* argv[]);
int verificaArqVazio(FILE* arq);
int calculaQtdArestas(FILE* arq);
int leArestas(FILE *arq, int qtdArestas);
int leNumVertices(FILE *arq);

#endif
