#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb_enc.h"

/* 
[3,5 pontos] Crie um programa que deverá solicitar ao usuario três numeros inteiros m, M e v. O
valor m será o menor valor presente no vetor, enquanto que M será o maior valor. O valor v é
aquele a ser buscado no vetor. A partir desses três valores, o programa deve criar um vetor de
tamanho 100, sendo que além do menor e maior valores, os demais (98 valores) devem ser
gerados aleatoriamente no intervalo ]m, M[. O vetor deverá ser ordenado de modo crescente.
Altere o algoritmo de busca binária para que, a cada etapa, seja impresso na tela o número de
elementos descartados durante a busca do elemento v.
*/

void numeros(int *i, int *j, int *k){
   
    int m, M, v;
   
    printf("Digite o menor valor presente no vetor:\n");
    scanf("%d", &m);
   
    printf("Digite o maior valor presente no vetor:\n");
    scanf("%d", &M);
   
    while(m>M){
        printf("O numero %d é maior que %d.\n", m, M);
        printf("Digite o maior valor presente no vetor:\n");
        scanf("%d", &M);
    }
   
    printf("Digite o valor a ser buscado no vetor:\n");
    scanf("%d", &v);
   
    while(v<=m || v>=M){
        printf("O numero %d nao esta presente entre %d e %d.\n", v, m, M);
        printf("Digite o valor a ser buscado no vetor:\n");
        scanf("%d", &v);
    }
   
    *i= m;
    *j= M;
    *k = v;
}

void crescente(int *vet, int n) {
    int i, j, k;
    for(i = 1; i < n; i++) {
        for(j = 0; j < i; j++) {
            if(vet[i] < vet[j]) {
                int temp = vet[i];
                for(k = i; k > j; k--) {
                    vet[k] = vet[k-1];
                }
                vet[j] = temp;
            }
        }
    }
}

int main() {

    srand(time(NULL));

    int m, M, v, n= 15, nos[n];
    int i, qtde_nos = sizeof(nos)/sizeof(int);
   
    numeros(&m, &M, &v);
   
    nos[0]=m;
    nos[qtde_nos-1]=M;

    for(i = 1; i < qtde_nos-1; i++){
        nos[i]= m + rand()%(M-m);
    }
   
    printf("Vetor gerado de %d ate %d de tamanho %d\n", m, M, n);
    for(i = 0; i < qtde_nos; i++){
        printf("%d ", nos[i]);
    }
    
    printf("\n");

    crescente(nos, n);

    printf("Vetor ordenado de modo crescente");
    for(i = 0; i < qtde_nos; i++){
        printf("%d ", nos[i]);
    }
    
    printf("\n");
    
    arvore* a = criar_arv(nos[0]);

    for(i = 1; i < qtde_nos; i++){
        adicionar_no_arv(a, nos[i]);
    }
    
    no* r = get_raiz_arv(a);
    
    printf("\n");
    
    if(r != NULL) {
    printf("\n");
        if(buscar_arv(a, v))
            printf("\nValor %d esta na arvore\n", v);
        else
            printf("\nValor %d nao ekkkncontrado\n", v);
       
    printf("\n");
    }

    liberar_arv(&a);
    printf("\nArvore liberada: %s", (a == NULL ? "Sim" : "Nao"));
    return 0;
}
