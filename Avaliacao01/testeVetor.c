#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./exercicio01.c"
#include "./exercicio02.c"
#include "./exercicio03.c"

#define TAM 15

int main(){

    srand(time(NULL));

    int x, y;

    int *vetor[TAM];
    for(int i=0; i<TAM; i++){
        vetor[i] = rand()% 46 - 20;
    }

    imprimirVetor(vetor, TAM);

    printf("Media: %.2f \n", mediaVetor(vetor, TAM));

    menorVetor(vetor,TAM);

    return 0;
}