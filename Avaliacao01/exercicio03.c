#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *vetor, int tamanho){

    for(int i=0; i<tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

}