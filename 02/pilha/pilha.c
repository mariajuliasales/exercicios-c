#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct no no;

typedef struct no{
    int conteudo;
    no *prox;
} no;

typedef struct pilha{
    no *prim;
    int qtde;
} pilha;


pilha *criarPilha(){
    pilha *p = (pilha *)calloc(1, sizeof(pilha));

    if (p == NULL)
        return NULL;
    
    return p;
}


static no *criarNo(int valor){
    no *novo = (no *)calloc(1, sizeof(no));

    if (novo == NULL)
        return NULL;

    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}


int esta_vazia(pilha *p){
    if (p == NULL){
        printf("A pilha está vazia\n");
        return ERRO;
    }
    
    if (p->qtde == 0){
        printf("A pilha está vazia\n");
        return VERDADEIRO;
    }
    return FALSO;
}

void exibirPilha(pilha *p){
    if (p == NULL || esta_vazia(p))
        return;

    no *temp = p->prim;
    while (temp != NULL){
        printf("%d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("\n");
}

void topo(pilha *p){
    if (p == NULL || esta_vazia(p))
        return;
    
    no *temp = p->prim;
    while (temp->prox != NULL)
        temp = temp->prox;
    
    if (temp->prox == NULL)
        printf("%d ", temp->conteudo);

    printf("\n");
}

int inserir(pilha *p, int valor){

    no *cel = criarNo(valor);

    if (p == NULL || cel == NULL)
        return FALSO;

    cel->conteudo = valor;
    if (esta_vazia(p))
        p->prim = cel;
    else{
        no *temp = p->prim;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = cel;
    }
    p->qtde++;
    return VERDADEIRO;
}

void liberar_lst(pilha **p){
    if (p == NULL || *p == NULL)
        return;

    no *temp = (*p)->prim;
    while (temp != NULL){
        (*p)->prim = (*p)->prim->prox;
        free(temp);
        temp = (*p)->prim;
        (*p)->qtde--;
    }
    free(*p);
    *p = NULL;
}

int remover(pilha *p){
    if (p == NULL || esta_vazia(p))
        return FALSO;

    no *temp = p->prim;
    if (p->qtde == 1){
        free(temp);
        p->prim = NULL;
    } else{
        int i;
        for (i = 1; i <= p->qtde - 2; i++)
            temp = temp->prox;

        no *aux = temp->prox;
        free(aux);
        temp->prox = NULL;
    }
    p->qtde--;

    return VERDADEIRO;
}
