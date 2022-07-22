#include <stdlib.h>
#include <stdio.h>

#include "pilha.c"

//  criar, inserir, remover, topo, liberar e esta_vazia.

int main(){
  pilha *p1 = criarPilha();

  inserir(p1, 3);
  inserir(p1, 5);

  printf("Pilha: ");
  exibirPilha(p1);

  printf("Topo da pilha : ");
  topo(p1);

  inserir(p1, 7);

  printf("Pilha: ");
  exibirPilha(p1);

  printf("Topo da pilha : ");
  topo(p1);

  remover(p1);

  printf("Pilha: ");
  exibirPilha(p1);

  printf("Topo da pilha : ");
  topo(p1);

  remover(p1);
  printf("Pilha: ");
  exibirPilha(p1);

  printf("Topo da pilha : ");
  topo(p1);

  liberar_lst(&p1);

  esta_vazia(p1);

  return 0;
}