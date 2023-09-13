/*Exemplos de entrada
7
abcdefghijklmnopqrstuvwxyz
ProgRamAr LegAL VAMOS eH FutEbOl comPutaDor paLaVRa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **CountingSort(char **, char *, int, int);
char **RadixSort(char **, char **, char *, int, int);
int Max(char **, int);
void MudaLetra(char **, int);
void Imprime(char **, int);
int Ver_tam(char **, int);
char Achar_letra(char, char *);
void Liberar(char **, char **, char *, int);
void Arruma_espaco( char**, int);

void Liberar(char **A, char **novo, char *letras, int qnt) {}

char Achar_Letra(char A, char *letras) {
  for (int cont = 0; cont < strlen(letras); cont++) {
    if (A == letras[cont]) {
      return cont;
    }
  }
  // return 1;
}

char **CountingSort(char **A, char *letras, int qnt, int j) {
  char **C = (char **)malloc(qnt * sizeof(char *));
  int Aux[27], pos = 0;
  // A- vetor q entrA, B- vetor q ColoCA ordenAdo
  for (int cont = 0; cont < 27; cont++) {
    Aux[cont] = 0;
  }
  for(int i=0; i<qnt;i++){
    C[i] = (char*) malloc(20 * sizeof(char));
  }
  // AgorA vAi contAsr quAntAs vezes ApAreCe CAdA elemento
  for (int cont = 0; cont < qnt; cont++) {
    // C[A[cont]] = C[A[cont]] + 1;
    if (A[cont][j] == ' ') {
      Aux[0]++;
    } else {
      pos = Achar_Letra(A[cont][j], letras);
      Aux[pos + 1]++;
    }
  }
  // AgorA ver quAntos elementos tem menor ou iguAl A posisAo q tA
  for (int cont = 1; cont < 27; cont++) {
    // C[cont] = C[cont] + C[cont - 1];
    Aux[cont] = Aux[cont] + Aux[cont - 1];
  }
  // Agora vai imprimir cada “digito” i do Radix sort
  for (int cont = 0; cont < 27; cont++) {
    printf("%i ", Aux[cont]);
  }
  printf("\n");

  // AgorA vAi ordenAr
  // ele ve no vetor a o numero depois olha no vetor v quantos numeros(nus) tem
  // menor ou igual e coloca na posicao nus do vetor B, depois diminui a
  // quantidade do nus
  for (int cont = qnt - 1, pos = 0; cont >= 0; cont--) {
    if (A[cont][j] == ' ') {
      C[Aux[0] - 1] = A[cont];
      Aux[0]--;
    } else {
      pos = Achar_Letra(A[cont][j], letras);
      C[Aux[pos + 1] - 1] = A[cont];
      Aux[pos + 1]--;
    }
    // B[C[A[cont]]] = A[cont];
    // C[A[cont]] = C[A[cont]] - 1;
  }
  return C;
}

char **RadixSort(char **A, char **B, char *letras, int qnt, int tam) {
  int max;
  // max= maior elemento
  max = Ver_tam(A, qnt); // retorna o maior elemento
  printf("%d\n", max);
  for (int cont = (max - 1); cont >= 0; cont--) { // pemsar q cont é a coluna
    B = CountingSort(A, letras, qnt, cont);
  }
  return B;
}

void MudaLetra(char **palavra, int qnt){
  int i, j, maior;
  for (i = 0; i < qnt; i++) {
    int tam = strlen(palavra[i]);
    for (j = 0; j < tam; j++) {
      if (palavra[i][j] < 91) {
        palavra[i][j] += 32;
      }
    }
  }
}

void Arruma_espaco( char** A, int qnt){
  int i, j, maior = Ver_tam(A, qnt);;
  for (i = 0; i < qnt; i++) {
    for (j = strlen(A[i]); j < maior; j++) {
      A[i][j] = ' ';
    }
  }
}

void Imprime(char **palavra, int qnt) {
  for (int cont = 0; cont < qnt; cont++) {
    printf("%s\n", palavra[cont]);
  }
}

int Ver_tam(char **palavra, int qnt) {
  int i, maior = 0;
  for (i = 0; i < qnt; i++) {
    if (maior < strlen(palavra[i])) {
      maior = strlen(palavra[i]);
    }
  }
  return maior;
}

int main(void) {
  int qnt, cont, tam;
  char **palavra, **novo;
  char *letra;
  scanf("%d", &qnt);
  getchar();
  letra = (char *)malloc(26 * sizeof(char));
  scanf("%s", letra);
  palavra = (char **)malloc(qnt * sizeof(char *));
  novo = (char **)malloc(qnt * sizeof(char *));
  for (int cont = 0; cont < qnt; cont++) {
    palavra[cont] = (char *)malloc(20 * sizeof(char));
    scanf("%s", palavra[cont]); // entrada das palavras
  }
  MudaLetra(palavra, qnt);
  for (int cont = 0; cont < qnt; cont++) {
    printf("%s.\n", palavra[cont]);
  }
  Arruma_espaco(palavra, qnt);
  novo = RadixSort(palavra, novo, letra, qnt, tam);
  Imprime(novo, qnt);
  for (int i = 0; i < qnt; i++) {
    // free (A[i]);
    free(novo[i]);
  }
  // free (A);
  free(novo);
  free(letra);
  return 0;
}