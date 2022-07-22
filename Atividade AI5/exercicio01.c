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
    
    int n=50, vet[n];
    
    for(int i=0; i<n; i++){
        vet[i]=rand()%200+1;
    }
    printf("Vetor criado de 1 a 200 de tamanho %d\n", n);
    exibir(vet, n);
    printf("\n");
    
    ord_selecao(vet,n);
    printf("Vetor ordenado de modo decrescente\n");
    exibir(vet, n);
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
            if(vet[j] > vet[idx_menor])
                idx_menor = j;
        int temp = vet[i];
        vet[i] = vet[idx_menor];
        vet[idx_menor] = temp;
    }
}

