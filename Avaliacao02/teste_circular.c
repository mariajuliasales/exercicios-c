#include <stdlib.h>
#include <stdio.h>
#include "./tad/lista_circular.c"

int main(){

    lista *l1 = criar_lc(30);

    for(int i=-10; i<11; i++){
        inserir_fim_lc(l1, i);
    }

    exibir_lc(l1);

    printf("\n");
    
    return 0;
}