#include <stdlib.h>
#include <stdio.h>

#include "./tad/pilha.c"

int main(){

    lista *p1 = criar(100);

    int valor;

    for(int i=1; i<50; i+2){
        inserir_fim_lst(p1, i);
    }

    for(int i=0; i<26; i++){
        topo(p1);
        remover_fim_lst(p1, valor );
    }



    return 0;
}