#include <stdio.h>
#include <stdlib.h>

void menorVetor(int *vetor, int tamanho){

    int menor=vetor[0];
    int menor2= vetor[0];
    
    for(int i=0; i<tamanho; i++){
        if(vetor[i]<menor){
            menor = vetor[i];
        }
        if(vetor[i]<menor2){
            menor2 = vetor[i];
        }
    }

}