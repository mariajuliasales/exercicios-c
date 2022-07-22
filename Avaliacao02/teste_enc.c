#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "./tad/lista_enc.c"



int main(){

    srand(time(NULL));

    lista *l1 = criar_lst();

    for(int i=0; i<25; i++){
        int valor;
        valor = rand()%25 - 15;
        inserir_inicio_lst(l1, valor);

    }
    exibir_lst(l1);

    oposto_lst(l1);

    exibir_lst(l1);

    return 0;
}