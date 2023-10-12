#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void somaN (int num, int *soma);

int main(){
    int num,soma;

    printf("Insira um numero 'N': ");
    scanf("%d",&num);

    somaN(num,&soma);

    printf("A soma de todos os numeros de 1 ate N eh %d\n",soma);

    system("pause");

    return 0;
}

void somaN (int num, int *soma){
    int i;

    *soma = 0;

    for(i = 1; i <= num; i++){
        *soma += i;
    }
}
