#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct no no;

struct no{
    int conteudo;
    no *prox;
};

typedef struct lista {
    no *prim;
    int qtde;
}lista;

int estaVazia(lista* l) {
    if(l == NULL)
      return ERRO;
    
    if(l->qtde == 0)
      return VERDADEIRO;

    return FALSO;
}

static no* criarNo(int valor) {
    no* novo = (no*) calloc(1, sizeof(no));
    if(novo == NULL)
        return NULL;
    
    novo->prox = NULL;
    novo->conteudo = valor;

    return novo;
}

lista* criarLista(int capacidade) {
    lista* l = (lista*) calloc(1, sizeof(lista));
    if(l == NULL){
        printf("passou\n");
        return NULL;
    }
    int i=0;
    no *cel = criarNo(i);
    if(cel == NULL)
        return FALSO;
    
    l->prim = cel;
    no *temp = l->prim;
    for(int i=-2; i<capacidade;i++){
      temp->prox = criarNo(i);
      temp->conteudo = i;
      printf("%d ", temp->conteudo);
      temp = temp->prox;
      l->qtde++;
    }
    return l;

}

void alterarValor(lista *l){
  if(l ==NULL || estaVazia(l)){
    printf("deu merda");
    return;
  }
  printf("\n");
  no *temp = l->prim;
  for(int i=0; i<l->qtde;i++)
  {
    if(temp->conteudo % 2 == 0){
      temp->conteudo = temp->conteudo + 1;
    } else {
      temp->conteudo = temp->conteudo - 1;
    }
    printf("%d ", temp->conteudo);
    temp = temp->prox;
  }

}
