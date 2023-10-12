#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void multiplica(int *vet, int tam, int num);

int main(){
    int *vet, tam, num, i;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int *) calloc(tam, sizeof(int));

    for(i = 0; i < tam; i++){
        printf("%d. ",i+1);
        scanf("%d",vet+i);
    }

    printf("Insira o numero a multiplicar o vetor: ");
    scanf("%d",&num);

    printf("Antes da multiplicacao: \n");

    for(i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }

    multiplica(vet,tam,num);

    printf("\nDepois da multiplicacao: \n");

    for(i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }

    printf("\n");

    system("pause");

    return 0;
}

void multiplica(int *vet, int tam, int num){
    int i; 

    for(i = 0; i < tam; i++){
        *(vet + i) *= num;
    }
}
