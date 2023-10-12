#include<stdio.h>
#include<windows.h>

int main(){
    int num, soma = 0, count = 0;

    do{

        printf("Insira um numero: ");
        scanf("%d",&num);

        if(num > 10){
            soma += num;
        }

        else if(num < 10){
            count += 1;
        }

    }while(num != 10);

    printf("Soma dos maiores que 10: %d\n",soma);

    printf("Quantidade de numeros menores que 10: %d\n",count);

    system("pause");

    return 0;
}