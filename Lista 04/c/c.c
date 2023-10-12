#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void swap (int *a, int *b);

void ordemSwap (int *vet, int tam);

int main(){
    int *vet, tam, i;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int *) calloc (tam,sizeof(int));

    for(i = 0; i < tam; i++){
        printf("Insira o %do. elemento do vetor: ",i+1);
        scanf("%d",vet+i);
    }

    printf("Antes da inversao da ordem:\n");

    for(i = 0; i < tam; i++){
        printf("%d. %d\n",i+1,vet[i]);
    }

    ordemSwap(vet,tam);

    printf("Depois da inversao da ordem:\n");

    for(i = 0; i < tam; i++){
        printf("%d. %d\n",i+1,vet[i]);
    }

    system("pause");

    return 0;
}

void swap(int *a, int *b){
    int aux; 
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordemSwap (int *vet, int tam){
    int i;

    float temp = (tam / 2);

    for(i = 0; i < temp; i++){
        swap(&vet[i],&vet[(tam - i)]);
    }
}