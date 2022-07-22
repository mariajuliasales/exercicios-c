#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./listaSequencial.c"

int main()
{
    srand(time(NULL));
    lista *l1 = criarLista(15, 1);

    printf("\n");
    printf("Existem %d ocorrencias do valor 3 presentes na lista l1. \n", buscar_qtde_lst(l1, 3));
    printf("Existem %d ocorrencias do valor 8 presentes na lista l1. \n", buscar_qtde_lst(l1, 8));
    printf("Existem %d ocorrencias do valor 15 presentes na lista l1. \n", buscar_qtde_lst(l1, 15));
    printf("\n");

    lista *l2 = criarLista(5, 1);

    printf("Existem %d ocorrencias do valor 1 presentes na lista l2. \n", buscar_qtde_lst(l2, 1));
    printf("Existem %d ocorrencias do valor 2 presentes na lista l2. \n", buscar_qtde_lst(l2, 2));
    printf("Existem %d ocorrencias do valor 3 presentes na lista l2. \n", buscar_qtde_lst(l2, 3));
    printf("Existem %d ocorrencias do valor 4 presentes na lista l2. \n", buscar_qtde_lst(l2, 4));
    printf("Existem %d ocorrencias do valor 5 presentes na lista l2. \n", buscar_qtde_lst(l2, 5));
    printf("\n");

    histograma(1, buscar_qtde_lst(l2, 1));
    histograma(2, buscar_qtde_lst(l2, 2));
    histograma(3, buscar_qtde_lst(l2, 3));
    histograma(4, buscar_qtde_lst(l2, 4));
    histograma(5, buscar_qtde_lst(l2, 5));

    return 0;
}
