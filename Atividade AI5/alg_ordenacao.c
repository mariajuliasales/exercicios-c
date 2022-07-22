#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibir(int *vet, int n);
void ord_flutuacao(int *vet, int n);
void ord_insercao(int *vet, int n);
void ord_combinacao(int *vet, int inicio, int fim);
void aux_comb(int *vet, int inicio, int meio, int fim);
void ord_rapida(int *number, int first, int last);
void ord_selecao(int *vet, int n);

int main() {
    srand(time(NULL));
    int tam, i;
    scanf("%d", &tam);
    int vet[tam], v[tam];

    double inicio, fim, tempo; // variaveis para medir o tempo

    for(i = 1; i <= tam; i++) {
      vet[i-1] = -20 + rand()%50;
      v[i-1] = vet[i-1];
    }

    inicio = (double) clock() / CLOCKS_PER_SEC;

    printf("ORDENACAO POR INSERCAO\n");
    //exibir(vet, tam);
    ord_insercao(vet, tam);
    //exibir(vet, tam);

    fim = (double) clock() / CLOCKS_PER_SEC;
    tempo = fim - inicio;
    printf("Tempo de execucao: %lf\n", tempo);

    for(i = 0; i < tam-1; i++)
      vet[i] = v[i];

    printf("ORDENACAO POR SELECAO\n");
    inicio = (double) clock() / CLOCKS_PER_SEC;
    //exibir(vet, tam);
    ord_selecao(vet, tam);
    //exibir(vet, tam);
    fim = (double) clock() / CLOCKS_PER_SEC;
    tempo = fim - inicio;
    printf("Tempo de execucao: %lf\n", tempo);

    for(i = 0; i < tam-1; i++)
      vet[i] = v[i];

    printf("ORDENACAO POR FLUTUACAO\n");
    inicio = (double) clock() / CLOCKS_PER_SEC;
    //exibir(vet, tam);
    ord_flutuacao(vet, tam);
    //exibir(vet, tam);
    fim = (double) clock() / CLOCKS_PER_SEC;
    tempo = fim - inicio;
    printf("Tempo de execucao: %lf\n", tempo);

    for(i = 0; i < tam-1; i++)
      vet[i] = v[i];

    printf("ORDENACAO POR COMBINACAO\n");
    inicio = (double) clock() / CLOCKS_PER_SEC;
    //exibir(vet, tam);
    ord_combinacao(vet, 0, tam-1);
    //exibir(vet, tam);
    fim = (double) clock() / CLOCKS_PER_SEC;
    tempo = fim - inicio;
    printf("Tempo de execucao: %lf\n", tempo);

    for(i = 0; i < tam-1; i++)
      vet[i] = v[i];

    printf("ORDENACAO RAPIDA\n");
    inicio = (double) clock() / CLOCKS_PER_SEC;
    //exibir(vet, tam);
    ord_rapida(vet, 0, tam-1);
    //exibir(vet, tam);
    fim = (double) clock() / CLOCKS_PER_SEC;
    tempo = fim - inicio;
    printf("Tempo de execucao: %lf\n", tempo);

    return 0;
}

void exibir(int *vet, int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n"); 
}

void ord_flutuacao(int *vet, int n) { // Bubble sort
    int i = 0, j, troca = 1;
    while(troca != 0) {
        troca = 0;
        for(int j = 0; j < n - 1 - i; j++) {
            if(vet[j] > vet[j+1]) {
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j + 1] = temp;
                troca = 1;
            }
        }
        i++;
    }
}

void ord_insercao(int *vet, int n) {  // Insertion sort
    int i, j, k;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(vet[i] < vet[j]) {
                int temp = vet[i];
                for(k = i; k > j; k--) {
                    vet[k] = vet[k-1];
                }
                vet[j] = temp;
            }
        }
    }
}

void ord_combinacao(int *vet, int inicio, int fim) {  // Merge sort
  if (inicio < fim) {
    int meio = inicio + (fim - inicio) / 2;
    ord_combinacao(vet, inicio, meio);
    ord_combinacao(vet, meio + 1, fim);
    aux_comb(vet, inicio, meio, fim);
  }
}

void aux_comb(int *vet, int inicio, int meio, int fim) {
  int tam1 = meio - inicio + 1;
  int tam2 = fim - meio;

  int esquerda[tam1], direita[tam2];

  for (int i = 0; i < tam1; i++)
    esquerda[i] = vet[inicio + i];
  for (int j = 0; j < tam2; j++)
    direita[j] = vet[meio + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = inicio;

  while (i < tam1 && j < tam2) {
    if (esquerda[i] <= direita[j]) {
      vet[k] = esquerda[i];
      i++;
    } else {
      vet[k] = direita[j];
      j++;
    }
    k++;
  }

  while (i < tam1) {
    vet[k] = esquerda[i];
    i++;
    k++;
  }

  while (j < tam2) {
    vet[k] = direita[j];
    j++;
    k++;
  }
}

void ord_rapida(int *number, int first, int last) {    // Quicksort
   int i, j, pivot, temp;

   if(first < last){
      pivot = first;
      i = first;
      j = last;

      while(i < j){
         while(number[i] <= number[pivot] && i < last)
            i++;
         while(number[j] > number[pivot])
            j--;
         if(i < j){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      ord_rapida(number, first, j-1);
      ord_rapida(number, j+1, last);
   }
}

void ord_selecao(int *vet, int n) {   // Selection sort
    int i, j, idx_menor = 0;
    for(int i = 0; i < n; i++) {
        idx_menor = i;
        for(int j = i + 1; j < n; j++)
            if(vet[j] < vet[idx_menor])
                idx_menor = j;
        int temp = vet[i];
        vet[i] = vet[idx_menor];
        vet[idx_menor] = temp;
    }
}