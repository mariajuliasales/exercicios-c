#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int soma(int n){

    if(n==0){
        return 0;
    }

    if(n==1){
        return 1;
    }

    return n + soma(n-1)*n ;

}


int main(){

    int n;

    printf("Informe um numero natural:\n");
    scanf("%d", &n);

    printf("A soma dos numeros menores ou iguais a %d é %d", n, soma(n));

    return 0;
}