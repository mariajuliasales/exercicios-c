#ifndef LISTA_SEQ_H
#define LISTA_SEQ_H

/** @file lista_seq.h
 *  @brief Interface de uma lista linear sequencial
 *
 *  Este arquivo contém a interface do tipo e das funções definidas
 *  para uma lista linear sequencial.
 *
 *  @author Anderson Grandi Pires
 *  @bug Nenhum bug conhecido
 */

// Interface da lista

// Tipo de dados
typedef struct lst lista;

// Operações
/*
Entrada: lista l e o valor a ser procurado
Saída: verdadeiro caso o valor esteja na lista e falso c.c.
*/
int buscar(lista *l, int valor);

int capacidade_lst(lista *l);
lista* criar_lst(int capacidade_lista);

int esta_vazia_lst(lista* l);
int esta_cheia_lst(lista* l);
int esvaziar_lst(lista *l);
void exibir_lst(lista *l);

int liberar_lst(lista **l);

/*
Entrada: lista l e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_fim_lst(lista *l, int valor);
int inserir_inicio_lst(lista *l, int valor);
int inserir_meio_lst(lista *l, int valor, int k);

int remover_fim_lst(lista *l, int *valor_removido);
int remover_inicio_lst(lista *l, int *valor_removido);
int remover_meio_lst(lista *l, int k, int *valor_removido);

int tamanho_lst(lista *l);
void ordenar_lst(lista *l);
#endif // LISTA_SEQ_H