#include<stdio.h>
#include<windows.h>

int main(){
    float base, altura, area;

    do{

        printf("Insira a medida da base do triangulo: ");
        scanf("%f",&base);

        if(base <= 0){
            printf("Erro: Insira medida maior que 0\n");
        }

    }while(base <= 0);

    do{

        printf("Insira a medida da altura do triangulo: ");
        scanf("%f",&altura);

        if(altura <= 0){
            printf("Erro: Insira medida maior que 0\n");
        }

    }while(altura <= 0);

    area = (base * altura) / 2;

    printf("A area do triangulo eh %.1f\n",area);

    system("pause");

    return 0;
}