#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./exercicio05.c"

#define TAM 10

int main(){

    srand(time(NULL));

    circulo *circulo[TAM] ;

    for(int i=0; i<TAM; i++){
        circulo[i]->x = rand()% 21 - 10;
        circulo[i]->y = rand()% 20 - 10;
        circulo[i]->r = rand()% 5 + 1 ;
    }

    printf("ola");

    return 0;
}