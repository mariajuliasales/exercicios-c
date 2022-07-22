#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./listaEncadeada.c"

int main(){
  lista* l1= criarLista(10);
  alterarValor(l1);
  return 0;
}