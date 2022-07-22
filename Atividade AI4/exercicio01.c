/*
[3,5 pontos] Escreva uma função recursiva para calcular o produto de todos os valores naturais
menores ou iguais a N. O valor de N deverá ser informado pelo usuário do programa, ou seja,
deverá ser lido o valor de N. Escreva uma mensagem na tela para informar ao usuário que ele
deverá digitar um número natural quando o programa começar a executar. Após o usuário digitar
o número, o programa deverá lê-lo, calcular o produto de todos os números naturais usando a
função criada e informar ao usuário o resultado.
*/
#include <stdio.h>
#include <stdlib.h>

int menorIgual(int n){
  if (n == 0){
    return 0;
  }
  if (n == 1){
    return 1;
  }

  return n * menorIgual(n - 1);
}

int main()
{
  int numero;

  printf("Dgite um numero natural: \n");
  scanf("%d ", &numero);

  printf("O produto de todos os numeros menores ou iguais a %d é %d\n", numero, menorIgual(numero));

  return 0;
}
