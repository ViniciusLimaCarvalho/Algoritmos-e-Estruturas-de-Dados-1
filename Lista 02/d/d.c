#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void impares (int *vet, int tam, int *vetAux, int *qtdImpar);     //função para colocar apenas os números ímpares do vetor original em um auxiliar

int main(){
    int *vet, tam, *vetAux, qtdImpar = 0, i;

    printf("Insira o tamanho do vetor: ");
    scanf("%d",&tam);

    vet = (int *) calloc(tam,sizeof(int));
    vetAux = (int *) calloc(tam,sizeof(int));

    for(i = 0; i < tam; i++){                    //loop de entrada de dados
        printf("Insira o %do. numero: ",i+1);
        scanf("%d",vet + i);
    }

    impares(vet, tam, vetAux, &qtdImpar);        //chama a função para armazenar números ímpares

    for(i = 0; i < qtdImpar; i++){             //loop de cópia do vetor auxiliar para o principal
        vet[i] = vetAux[i];
    }

    int *vetTest = realloc(vet,qtdImpar * sizeof(int));     //teste de realocação de memória

    if(vetTest == NULL){
        printf("Erro ao realocar memoria");
        return 1;
    }

    vet = vetTest;         //realocação de memória do vetor principal

    printf("Vetor so com impares: ");

    for(i = 0; i < qtdImpar; i++){         //loop de impressão
        printf("%d ",vet[i]);
    }

    printf("\n\n");

    system("pause");

    return 0;
}

void impares (int *vet, int tam, int *vetAux, int *qtdImpar){
    int i;

    for(i = 0; i < tam; i++){
        if(*(vet + i) % 2 != 0){
            *(vetAux + *qtdImpar) = *(vet + i);
            (*qtdImpar)++;
        }
    }
}