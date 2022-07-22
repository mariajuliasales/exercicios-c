#ifndef LISTA_CIRC_INTEIROS_H
#define LISTA_CIRC_INTEIROS_H

typedef struct lista lista;

int buscar_lc(lista* l, int e); // retornar o índice ou -1
int capacidade_lc(lista *l);
lista* criar_lc();
int esta_cheia_lc(lista* l);
int esta_vazia_lc(lista* l);
void exibir_lc(lista* l);
int inserir_fim_lc(lista* l, int e);
void liberar_lc(lista** l);
int remover_inicio_lc(lista* l, int *v);
int tamanho_lc(lista* l);
void dobrarValor(lista *l)

#endif // LISTA_CIRC_INTEIROS_H
