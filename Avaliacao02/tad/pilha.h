#ifndef PILHA_H
#define PILHA_H

typedef struct lst lista;

int esta_vazia(lista* l);
int esta_cheia_lst(lista *l);

lista* criar(int capacidade);

void topo(lista *l);
int inserir_fim_lst(lista *l, int valor);
int liberar_lst(lista **l);

int remover_fim_lst(lista *l, int *valor_removido);


#endif 