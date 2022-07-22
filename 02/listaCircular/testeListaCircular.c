#include <stdio.h>
#include <stdlib.h>

#include "listaCircular.c"

int main(){
  lista *l1 = criarLista(5);
// Exibir a lista l1 5 vezes 
  exibir_n_vezes_lc(l1, 5);
  printf("\n");

  lista *l2 = criarLista(9);
// Exibir a lista l2 2 vezes
  exibir_n_vezes_lc(l2,2);

  return 0;
}