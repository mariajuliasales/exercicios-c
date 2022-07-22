#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista_seq.h"


int main(){

    srand(time(NULL));

    int capacidade =45;
    int valor;

    lista *l = criar_lst(capacidade);

    for(int i=0; i<capacidade; i++){
        valor = rand()%101 - 50;
        inserir_inicio_lst(l, valor);
    }

    printf("Lista criada:\n");
    exibir_lst(l);
    printf("\n");

    ordenar_lst(l);
    printf("Lista apos a ordenação por selecao:\n");
    exibir_lst(l);

    printf("\n");

    return 0;
}