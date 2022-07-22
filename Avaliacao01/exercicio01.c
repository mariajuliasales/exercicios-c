#include <stdio.h>
#include <stdlib.h>

float mediaVetor(int *vetor, int tamanho){

    float media=0;
    
    for(int i=0; i<tamanho; i++){
        media = media + vetor[i];
    }
    media = media / tamanho;
    return media;

}