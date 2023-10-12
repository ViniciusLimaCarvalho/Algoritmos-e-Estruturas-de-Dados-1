#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int preencheVet(int *vet, int *vezes);

int main(){
    char escolha;
    int vezes = 0, *vet;

    while(1){
        vet = (int *) calloc(1,sizeof(int));
        if(vezes > 0){
            printf("\nVoce quer entrar com outro vetor ? (S/N): ");
            scanf(" %c",&escolha);

            if(escolha == 's' || escolha == 'S'){
                preencheVet(vet,&vezes);
            }
            else{
                break;
            }
        }

        else{
            preencheVet(vet,&vezes);
        }
    }
    
    system("pause");

    return 0;
}

int preencheVet(int *vet, int *vezes){
    int tamanho = 0, entrada, i;


    while(1){
        printf("Insira um numero(-1 para parar): ");
        scanf("%d",&entrada);

        if(entrada == (-1)){
            break;
        }

        if(entrada != vet[tamanho]){
            tamanho++;

            vet = (int *) realloc(vet,tamanho * (sizeof(int)));

            if(vet == NULL){
                printf("Erro ao alocar memoria");
                return 1;   
            }

            vet[tamanho - 1] = entrada;
        }

    }


    for(i = 0; i < tamanho; i++){
        printf("%d ",vet[i]);
    }

    printf("\nTamanho do vetor: %d",tamanho);

    free(vet);

    (*vezes)++;
}