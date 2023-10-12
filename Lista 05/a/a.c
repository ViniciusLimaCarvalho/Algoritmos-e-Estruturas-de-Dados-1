#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct data{
    int ano, mes, dia;
};

typedef struct data data;

void imprimeData(data d);

int main(){
    data d;

    do{
        printf("Insira o dia: ");
        scanf("%d",&d.dia);
    }while(d.dia < 1 || d.dia > 31);

    do{
        printf("Insira o mes: ");
        scanf("%d",&d.mes);
    }while(d.mes < 1 || d.mes > 12);

    printf("Insira o ano: ");
    scanf("%d",&d.ano);

    imprimeData(d);

    system("pause");
    
    return 0;
}

void imprimeData(data d){
    if(d.dia < 10 && d.mes < 10){
        printf("0%d/0%d/%4d\n",d.dia,d.mes,d.ano);
    }
    else if(d.dia < 10 && d.mes >= 10){
        printf("0%d/%d/%4d\n",d.dia,d.mes,d.ano);
    }
    else if(d.dia >= 10 && d.mes < 10){
        printf("%d/0%d/%4d\n",d.dia,d.mes,d.ano);
    }
    else{
        printf("%2d/%2d/%4d\n",d.dia,d.mes,d.ano);
    }
    
}