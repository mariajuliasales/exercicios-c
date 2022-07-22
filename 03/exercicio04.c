#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "abb_enc.h"



int main(){

    int num=11, nos[num];

    nos[0]=5;

    for(int i=1; i<num; i++){
        nos[i]=rand()%10+1;
    }

    arvore *arv=criar_arv(nos[0]);

    for(int i=1; i<num; i++){
        adicionar_no_arv(arv, nos[i]);
    }
    busca_largura(arv);
    printf("\n");

    printf("\n");

    dobrar(arv);

    busca_largura(arv);





    return 0;
}



