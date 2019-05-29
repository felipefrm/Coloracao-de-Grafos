#ifndef ENTRADASAIDA
#define ENTRADASAIDA

typedef struct arquivos {
  FILE* entrada;
  FILE* saida;
  int flag;   // flag para poder retornar 0 em caso de erro
} Arquivos;

Arquivos* argumentosEntrada(int argc, char* argv[]);
int** alocaMatriz(int linha, int coluna);
int verificaArqVazio(FILE* arq);
int calculaQtdArestas(FILE* arq);
int leQtdVertices(FILE *arq);
void contaTempoProcessador(double *utime, double *stime);
void imprimeSaida(double user_time, double system_time, int k, int alg, FILE* arq);
void liberaArquivos(Arquivos *arq);

#endif
