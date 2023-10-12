#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int *vetor(int tam);

int main(){
    int tam, *vet, i;

    srand(time(NULL));

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = vetor(tam);

    for(i = 0; i < tam; i++){
        vet[i] = rand() % 100;
    }

    for(i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }

    printf("\n");

    system("pause");

    return 0;
}

int *vetor(int tam){
    return (int *) calloc(tam, sizeof(int));
}


