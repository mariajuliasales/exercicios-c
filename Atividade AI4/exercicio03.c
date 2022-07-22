/*
3) [3 pontos] Escreva uma função para contar o número de nós folhas em uma árvore binária de
busca. Implemente uma função principal (main) para testar a função criada. Na função principal
insira 10 valores aleatórios no intervalo [1, 100] na árvore e utilize a função criada para informar
o número de nós folhas na árvores.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb_enc.c"


int main(){
    srand(time(NULL));

    int n=10, nos[n] ;
    int qtde_nos = sizeof(nos) / sizeof(int);

    printf("Valores a serem inseridos na árvore: ");
    for (int i = 0; i < n; i++){
        nos[i]=  rand()% 100 +1;
        printf("%d ", nos[i]);
    }

    printf("\n");

    arvore *a = criar_arv(nos[0]);

    for (int i = 1; i < qtde_nos; i++){
        adicionar_no_arv(a, nos[i]);
    }

    no *r = get_raiz_arv(a);


    printf("Quantidade de nós folhas: %d", quantidade(r));
    return 0;
}