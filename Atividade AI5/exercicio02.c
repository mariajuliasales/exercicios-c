#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_seq.h"

/*
[3,5 pontos] Crie uma função na lista sequencial para ordenar o conteúdo da lista de modo não
crescente, usando o algoritmo de ordenação por inserção. Utilize o protótipo void
ordenar_lst(lista* l). Faça um programa para testar a função criada. Crie uma lista com
tamanho 30 e a preencha totalmente com valores aleatórios no intervalo [50, 200]. Mostre o
conteúdo da lista. Ordene a lista com a função criada e apresente o conteúdo da lista
novamente.
*/

int main(){
    
    srand(time(NULL));
    int capacidade=10, valor;

    lista *lista = criar_lst(capacidade);
    
    for(int i=0; i<capacidade;i++){
        valor=rand()%151+50;
        inserir_inicio_lst(lista,valor);
    }
    
    printf("Lista de 50 a 150 com capacidade %d\n",capacidade);
    exibir_lst(lista);
    ordenar_lista(lista,capacidade);
    printf("\n");
    printf("Lista ordenada de modo decrescente %d\n",capacidade);
    exibir_lst(lista);


    return 0;
}