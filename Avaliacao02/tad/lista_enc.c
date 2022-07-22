#include <stdio.h>
#include <stdlib.h>

#include "lista_enc.h"

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

struct c {
    int conteudo;
    celula *prox;
};

struct lista {
    celula *prim;
    int qtde;
};

int busca_seq_lst(lista *l, int valor, int *pos) {
    if(esta_vazia_lst(l))
        return FALSO;
    
    int cont = 1;
    celula *temp = l->prim;
    while(temp != NULL) {
        if(temp->conteudo == valor) {
            *pos = cont;
            return VERDADEIRO;
        }
        temp = temp->prox;
        cont++;
    }

    return FALSO;
}

lista* criar_lst() {
    lista* l = (lista*) calloc(1, sizeof(lista));
    if(l == NULL)
        return NULL;

    l->prim = NULL;
    l->qtde = 0;

    return l;
}

static celula* criar_no(int valor) {
    celula* novo = (celula*) calloc(1, sizeof(celula));
    if(novo == NULL)
        return NULL;
    
    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

int esta_vazia_lst(lista* l) {
    if(l == NULL)
        return ERRO;
    
    if(l->qtde == 0)        // if(l->prim == NULL)
        return VERDADEIRO;

    return FALSO;
}

void exibir_lst(lista* l) {
    if(l == NULL)
        return;
    
    celula *temp = l->prim;
    while(temp != NULL) {
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("\n");

}

int inserir_fim_lst(lista* l, int valor) {
    celula *cel = criar_no(valor);
    if(l == NULL || cel == NULL)
        return FALSO;
    
    if(esta_vazia_lst(l))
        l->prim = cel;
    else {
        celula *temp = l->prim;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }

    l->qtde++;

    return VERDADEIRO;
}

int inserir_meio_lst(lista* l, int valor, int k) {
    celula *cel = criar_no(valor);
    if(l == NULL || cel == NULL || k < 1 || k > tamanho_lst(l)+1)
        return FALSO;
    
    if(k == 1) {
        cel->prox = l->prim;
        l->prim = cel;
    } else {
        celula *temp = l->prim;
        int i;
        for(i = 1; i < k-1; i++)
            temp = temp->prox;
    
        cel->prox = temp->prox;
        temp->prox = cel;
    }
    l->qtde++;

    return VERDADEIRO;
}

int inserir_inicio_lst(lista* l, int valor) {
    celula *cel = criar_no(valor);
    if(l == NULL || cel == NULL)
        return FALSO;
    
    cel->prox = l->prim;
    l->prim = cel;

    l->qtde++;

    return VERDADEIRO;
}

void liberar_lst(lista **l) {
    if(l == NULL || *l == NULL)
        return;

    celula *temp = (*l)->prim;
    while(temp != NULL) {
        (*l)->prim = (*l)->prim->prox;
        free(temp);
        temp = (*l)->prim;
        (*l)->qtde--;
    }

    free(*l);
    *l = NULL;
}

int remover_fim_lst(lista* l, int* valor) {
    if(l == NULL || esta_vazia_lst(l) || valor == NULL)
        return FALSO;
    
    celula* temp = l->prim;
    if(l->qtde == 1) {
        *valor = temp->conteudo;
        l->prim = NULL;
        free(temp);
    } else {
        int i;
        for(i = 1; i <= l->qtde - 2; i++)
            temp = temp->prox;
        *valor = temp->prox->conteudo;
        celula *aux = temp->prox;
        free(aux);
        temp->prox = NULL;
    }

    l->qtde--;

    return VERDADEIRO;
}

int remover_meio_lst(lista* l, int* valor, int k) {
    if(l == NULL || esta_vazia_lst(l) || valor == NULL || k < 1 || k > l->qtde)
        return FALSO;

    celula *temp = l->prim;
    if(l->qtde == 1) {
        *valor = l->prim->conteudo;
        free(temp);
        l->prim = NULL;
    } else {
        int i;
        for(i = 1; i < k - 1; i++)
            temp = temp->prox;
        *valor = temp->prox->conteudo;
        celula *aux = temp->prox;
        temp->prox = temp->prox->prox;
        free(aux);
    }

    l->qtde--;

    return VERDADEIRO;
}

int remover_inicio_lst(lista *l, int *valor) {
    if(l == NULL || esta_vazia_lst(l) || valor == NULL)
        return FALSO;
    
    *valor = l->prim->conteudo;
    celula *temp = l->prim;
    l->prim = l->prim->prox;
    free(temp);
    l->qtde--;
    
    return VERDADEIRO;
}

int remover_fim_p_lst(lista* l, int* valor) {
    if(l == NULL || esta_vazia_lst(l) || valor == NULL)
        return FALSO;
    
    celula *temp = l->prim;
    if(l->qtde == 1) {
        *valor = temp->conteudo;
        l->prim = NULL;
        free(temp);
    } else {
        while(temp->prox->prox != NULL)
            temp = temp->prox;
        *valor = temp->prox->conteudo;
        free(temp->prox);
        temp->prox = NULL;
    }

    l->qtde--;

    return VERDADEIRO;
}

int tamanho_lst(lista* l) {
    if(l == NULL)
        return 0;
    
    return l->qtde;
}

void oposto_lst( lista *l){

    if(l == NULL)
        return;

    if(esta_vazia_lst(l))
        return;

    celula *temp = l->prim;
    while(temp != NULL) {
        temp->conteudo = temp->conteudo * (-1) ;
        temp = temp->prox;
    }

}