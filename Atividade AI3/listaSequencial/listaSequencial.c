#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
#define ERRO -1

typedef struct {
  int qtde, capacidade;
  int *dados;
} lista;


int esta_vazia(lista *l) {
    if(l == NULL)
        return 77777777;

    if(l->qtde == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

// Exercicio 1
int buscar_qtde_lst(lista *l, int valor) {
    if(l == NULL || esta_vazia(l))
        return ERRO;
    
    int quantidade=0;

    for(int i=0;i<l->capacidade;i++){
      if(l->dados[i]==valor){
        quantidade++;
      };
    };

    return quantidade;
}

//  Exercicio 2
lista* criarLista (int MAX, int MIN){
    int capacidade=50;

    lista *novaLista = (lista*) calloc(1, sizeof(lista));
    if(novaLista == NULL)
        return NULL;

    novaLista->capacidade = capacidade;
    novaLista->qtde=0;

    novaLista->dados = (int*) calloc(capacidade, sizeof(int));
    if(novaLista->dados == NULL) {
        free(novaLista);
        return NULL;
    }
    novaLista->capacidade = capacidade;
    for(int i=0; i<novaLista->capacidade;i++){
      novaLista->dados[i] = rand()%MAX + MIN;
      novaLista->qtde++;
    }

    return novaLista;
}


// EXERCICIO 3 

void histograma(int numero, int quantidade){
  printf("%d: ", numero);
  for(int i=0; i<quantidade; i++)
      printf("*");

  printf("\n");
}