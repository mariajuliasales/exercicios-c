#include <stdlib.h>
#include <stdio.h>

#define FALSO 0
#define VERDADEIRO 1
#define NULL_ERROR -1

typedef struct
{
  int *dados;
  int inicio, fim;
  int capacidade;
} lista;

lista *criarLista(int capacidade){
  lista *novaLista = (lista *)malloc(sizeof(lista));
  if (novaLista == NULL)
    return NULL;

  novaLista->dados = (int *)malloc(capacidade * sizeof(int));

  if (novaLista->dados == NULL){
    free(novaLista);
    return NULL;
  }

  novaLista->inicio = -1;
  novaLista->fim = 0;

  if (capacidade != 0){
    novaLista->capacidade = capacidade;
    for (int i = 0; i < capacidade; i++){
      novaLista->dados[i] = novaLista->fim + 1;
      novaLista->fim++;
    }
    novaLista->inicio = 0;
  }

  return novaLista;
}

int tamanho(lista *l){
  int tam;
  if (l->inicio == -1)
    return 0;
  if (l->fim > l->inicio)
    return l->fim - l->inicio;
  else
    return l->fim - l->inicio + l->capacidade;
}

int esta_vazia(lista *l){
  if (l == NULL)
    return NULL_ERROR;

  if (tamanho(l) == 0)
    return VERDADEIRO;

  return FALSO;
}

void exibir_n_vezes_lc(lista *l, int N){
  if (l == NULL || esta_vazia(l))
    return;

  int i, id_pos = l->inicio;
  id_pos = l->inicio;

  for (i = 1; i <= (tamanho(l) * N); i++){
    printf("%d ", l->dados[id_pos++]);
    if (id_pos == l->capacidade){
      id_pos = 0;
    }
  };
  
  printf("\n");
}
