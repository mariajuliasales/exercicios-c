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
Busca valor na lista
Entrada: lista l e o valor a ser procurado
Saída: verdadeiro caso o valor esteja na lista e falso caso contrário
*/
int buscar(lista *l, int valor);

/*
Retorna a capacidade da lista
Entrada: lista l
Saída: capacidade da lista
*/
int capacidade_lst(lista *l);

/*
Cria uma nova lista com a capacidade capacidade_lista e a retorna
Entrada: capacidade_lista indica o número máximo de valores que a lista poderá ter
Saída: retorna uma lista com capacidade igual a capacidade_lista
*/
lista* criar_lst(int capacidade_lista);

/*
Verifica se a lista está vazia
Entrada: lista l
Saída: verdadeiro caso a lista esteja vazia
       falso caso contrário
*/
int esta_vazia_lst(lista* l);

/*
Verifica se a lista está cheia
Entrada: lista l
Saída: verdadeiro caso a lista esteja cheia
       falso caso contrário
*/
int esta_cheia_lst(lista* l);

/*
Esvazia a lista
Entrada: lista l
Saída: verdadeiro caso a lista tenha sido esvaziada com sucesso
       falso caso contrário
*/
int esvaziar_lst(lista *l);

/*
Exibe a lista com todos os valores em uma mesma linha separados por um espaço
Entrada: lista l
Saída: Não tem
*/
void exibir_lst(lista *l);

/*
Libera a memória alocada para a lista
Entrada: lista l
Saída: verdadeiro caso a lista tenha sido liberada com sucesso
       falso caso contrário
*/
int liberar_lst(lista **l);

/*
Insere valor no fim da lista
Entrada: lista l e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_fim_lst(lista *l, int valor);

/*
Insere valor no início da lista
Entrada: lista l e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_inicio_lst(lista *l, int valor);

/*
Insere valor na k-ésima posição da lista
Entrada: lista l e o valor a ser inserido
Saída: verdadeiro caso a inserção tenha ocorrido com sucesso
       falso caso contrário
*/
int inserir_meio_lst(lista *l, int valor, int k);

/*
Remove um elemento do fim da lista
Entrada: lista l e uma parâmetro valor_removido que armazenará o valor removido do fim da lista
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int remover_fim_lst(lista *l, int *valor_removido);

/*
Remove um elemento do início da lista
Entrada: lista l e uma parâmetro valor_removido que armazenará o valor removido do início da lista
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int remover_inicio_lst(lista *l);

/*
Remove um elemento da k-ésima posição da lista
Entrada: lista l e uma parâmetro valor_removido que armazenará o valor removido da k-ésima posição da lista
Saída: verdadeiro caso a remoção tenha ocorrido com sucesso
       falso caso contrário
*/
int remover_meio_lst(lista *l, int k, int *valor_removido);

/*
Retorna o tamanho da lista
Entrada: lista l
Saída: um inteiro representando o quantidade de itens na lista
*/
int tamanho_lst(lista *l);

int qtde_negativos_lst(lista *l);

#endif // LISTA_SEQ_H