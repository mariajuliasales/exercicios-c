/*
2) [3,5 pontos] Escreva uma função recursiva para imprimir o conteúdo de um vetor de inteiros da
primeira até a última posição. Os elementos do vetor deverão ser impressos separados por um
espaço. Implemente uma função principal (main) para testar a função recursiva. Na função
principal crie um vetor de tamanho 15 e utilize uma função para geração de números aleatórios
para preencher o vetor com valores gerados no intervalo [12, 83].
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir(int vet[], int tam){

  if(tam==1){
    printf("%d ", vet[tam-1]);
  }
  else{
    imprimir(vet, tam-1);
    printf("%d ", vet[tam-1]);
  }
}

int numAleatorio(){
  return rand()% 72 +12;
}

int main(){

  srand(time(NULL));

  int n=15, vet[n];

  for(int i=0;  i<n; i++){
    vet[i]=numAleatorio();
  }

  imprimir(vet, n);
  return 0;
}
