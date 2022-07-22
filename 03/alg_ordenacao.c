#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void ord_insercao1(int *vet, int n) {  // Insertion sort
    int i, j, k;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(vet[i] > vet[j]) {
                int temp = vet[i];
                for(k = i; k > j; k--) {
                    vet[k] = vet[k-1];
                }
                vet[j] = temp;
            }
        }
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
void conteudoVetor(int vetor[], int tamanho){

    for(int i=0; i<tamanho; i++){
        printf("%d ",vetor[i]);
    }

    printf("\n");
    printf("\n");

}

int main(){

    srand(time(NULL));

    int tam=45, vet[tam];

    for(int i=0; i<tam; i++){
        vet[i]= rand()%201 - 100;
    }

    conteudoVetor(vet, tam);

    ord_insercao1(vet, tam);

    conteudoVetor(vet, tam);


    return 0;
}