
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct lst {
    int qtde, capacidade;
    int *dados;
};

int esta_vazia(lista *l) {
    if(l == NULL)
        return ERRO;

    if(l->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}
int esta_cheia_lst(lista *l) {
    if(l == NULL)
        return ERRO;

    return l->qtde == l->capacidade;
}

lista* criar(int capacidade) {
    if(capacidade <= 0)
        return NULL;

    lista *nova = (lista*) calloc(1, sizeof(lista));
    if(nova == NULL)
        return NULL;

    nova->qtde = 0;
    nova->dados = (int*) calloc(capacidade, sizeof(int));
    if(nova->dados == NULL) {
        free(nova);
        return NULL;
    }
    nova->capacidade = capacidade;

    return nova;
}

void topo(lista *l) {
    if(l == NULL || esta_vazia(l))
        return;
    
    int i = l->qtde;
    printf("%d ", l->dados[i]);
}


int inserir_fim_lst(lista *l, int valor) {
    if(l == NULL)
        return ERRO;
    
    if(esta_cheia_lst(l))
        return FALSO;

    l->dados[l->qtde] = valor;
    l->qtde++;

    return VERDADEIRO;
}

int liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return FALSO;
    
    free((*l)->dados);
    free(*l);
    *l = NULL;
    
    return VERDADEIRO;
}


int remover_fim_lst(lista *l, int *valor_removido) {
    if(l == NULL)
        return ERRO;
    
    if(esta_vazia(l))
        return FALSO;
    

    *valor_removido = l->dados[l->qtde-1];


    l->qtde--;

    return VERDADEIRO;
}