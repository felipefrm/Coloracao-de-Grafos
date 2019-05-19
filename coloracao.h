#ifndef COLORACAO
#define COLORACAO

int verificaCor(int **MatAdj, int *cor, int corAtual, int v, int numVertices);
int coloracaoVertice(int **MatAdj, int *cor, int k, int v, int numVertices);
int Backtracking(int **MatAdj, int k, int src, int numVertices);

#endif
