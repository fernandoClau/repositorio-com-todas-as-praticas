#include <stdio.h>
#include <stdlib.h>

/* aqui eu fiz uma funçao para imprimir a matriz*/
void imprima(char **matriz, int m, int n) {
  int i, j;
  for (i = 0; i < m; i++) {
    printf("\n");
    for (j = 0; j < n; j++)
      printf("%c ", matriz[i][j]);
  }
  printf("\n");
}
/* aqui fiz uma funcao para receber um caracter e vai compara se a variavel x é 1 ou é 0*/
int Terra(char x){ 
  return (x == '\0' || x == '.') 
    ? 1 : 0; 
} 
/* aqui fiz uma funçao para compara a matriz e pecorre por cada vetor analisando onde se encontra a costa*/
int retornaCosta(char **matriz, int m, int n) {
  int costas = 0, i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (Terra(matriz[i][j]) == 1) 
        continue;
      if (i == 0 || i == m - 1) { 
        costas++; 
        continue;
      }
      if (Terra(matriz[i][j + 1]) == 1 || Terra(matriz[i][j - 1]) == 1 || Terra(matriz[i + 1][j]) == 1 || Terra(matriz[i - 1][j]) == 1) {
        costas++;
      }
    }
  }
  return costas;
}
/* no int main solicito ao usuario que informe a qauntidade de linhas e colunas, e depois faço uma alocação dinamica de ponteiro para ponteiro e depois eu aloco dinamicamente a matriz*/
int main(void) {
  int M, N;
  int i, j;
  printf("Defina as linhas: \n"); 
  scanf(" %d", &M);
  printf("Defina as colunas: \n"); 
  scanf(" %d", &N);
  char **matriz = (char **)malloc(M * sizeof(char *)); 
  if (matriz == NULL) {
    printf("ERRO!");
    exit(1);
  }
  for (i = 0; i < M; i++) {
    matriz[i] = (char *)malloc(N * sizeof(char)); 
  }
/* peço que o usuario digite os caracteres para a matriz*/
printf("informe os caracteres! ");
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      scanf(" %c", &matriz[i][j]);
    }
  }
  imprima(matriz, M, N);
  printf("Costas: %i\n", retornaCosta(matriz, M, N));
  /*nessse trecho fasso a liberacão dos vetores e da matriz*/
  for (i = 0; i < M; i++) {
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}