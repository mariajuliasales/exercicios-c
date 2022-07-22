#include <stdlib.h>
#include <stdio.h>
#include "abb_enc.h"
// IMPLEMENTAÇÃO DA ÁRVORE BINÁRIA DE BUSCA (ENCADEADA)

#define FALSO 0
#define VERDADEIRO 1

struct no
{
    int info;
    no *sae; // sae
    no *sad; // sad
};

struct arv
{
    no *raiz;
};

int adicionar_no_arv(arvore *a, int valor){
    if (a == NULL)
        return FALSO;

    no *temp = a->raiz;
    while (temp != NULL){
        if (valor <= temp->info){
            if (temp->sae == NULL){
                temp->sae = criar_no(valor);
                break;
            }
            temp = temp->sae;
        }
        else{
            if (temp->sad == NULL){
                temp->sad = criar_no(valor);
                break;
            }
            temp = temp->sad;
        }
    }

    return VERDADEIRO;
}


arvore *criar_arv(int valor_raiz)
{
    arvore *a = (arvore *)malloc(sizeof(arvore));
    if (a == NULL)
        return NULL;

    no *novo_no = (no *)criar_no(valor_raiz);
    if (novo_no != NULL)
        a->raiz = novo_no;
    else
    {
        free(a);
        return NULL;
    }

    return a;
}

no *criar_no(int valor)
{
    no *novo = (no *)malloc(sizeof(no));
    if (novo == NULL)
        return NULL;

    novo->info = valor;
    novo->sad = NULL;
    novo->sae = NULL;

    return novo;
}

no *get_raiz_arv(arvore *a)
{
    if (a == NULL)
        return NULL;

    return a->raiz;
}

no *sae_arv(no *n)
{
    if (n == NULL)
        return NULL;

    return n->sae;
}

no *sad_arv(no *n)
{
    if (n == NULL)
        return NULL;

    return n->sad;
}

int quantidade(no *n)
{
    if(n == NULL){
        return 0;
    }
    if (n->sae == NULL && n->sad == NULL){
        return 1;
    }
    else{
        return quantidade(n->sae) + quantidade(n->sad);
    }
}