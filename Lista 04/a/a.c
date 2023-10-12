#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void medMaior(int *vet, int tam, int *maior, float *media);

int main(){
    int *vet, tam, maior, i;
    float media;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int *) calloc(tam,sizeof(int));

    for(i = 0; i < tam; i++){
        printf("Insira o %do. numero do vetor: ",i+1);
        scanf("%d",vet + i);
    }

    medMaior(vet, tam, &maior, &media);

    printf("O maior numero eh %d\n",maior);
    printf("A media aritmetica dos elementos do vetor eh %.1f\n",media);

    system("pause");

    return 0;
}

void medMaior(int *vet, int tam, int *maior, float *media){
    int i, soma = 0, aux = *vet;

    for(i = 0; i < tam;i++){
        if(*(vet + i) > aux){
            aux = *(vet + i);
        }
        soma += *(vet + i);
    }

    *media = soma / tam;

    *maior = aux;
}