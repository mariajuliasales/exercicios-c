#include <stdlib.h>
#include <stdio.h>

#include "./tad/lista_seq.c"

int main(){

    lista *l1 = criar_lst(100);

    for(int i=-7; i<9; i++){
        inserir_fim_lst(l1,i);
    }

    exibir_lst(l1);

    printf("\nCapacidade da lista: %d\n", capacidade_lst(l1));
    printf("\nTamanho da lista: %d\n", tamanho_lst(l1));

    remover_inicio_lst(l1);
    remover_inicio_lst(l1);
    remover_inicio_lst(l1);

    exibir_lst(l1);

    printf("\nTamanho da lista: %d\n", tamanho_lst(l1));

    printf("\nQtd de valores negativos: %d\n", qtde_negativos_lst(l1));

    return 0;
}