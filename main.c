#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main(){
    int loto[10], bet[10], *acert = NULL, percent, i, j, aux, verifica, tam = 0, idx = 0;

    for(i = 0; i < 10; i++){
        verifica = 0;
        do{
            printf("Insira o %do. numero sorteado na lotomania: ",i+1);
            scanf("%d",&aux);

            for(j = 0; j < i; j++){
                if(aux == loto[j]){
                    printf("Numero ja inserido");
                    verifica++;
                    break;
                }
            }
        }while(verifica != 0);

        loto[i] = aux;
    }

    for(i = 0; i < 10; i++){
        verifica = 0;
        do{
            printf("Insira os numeros sorteados na lotomania: ");
            scanf("%d",&aux);

            for(j = 0; j < i; j++){
                if(aux == bet[j]){
                    printf("Numero ja inserido");
                    verifica++;
                    break;
                }
            }
        }while(verifica != 0);

        bet[i] = aux;

        for(j = 0; j < 10; j++){
            if(bet[i] == loto[j]){
                tam++;
                acert = (int *) realloc(acert,tam*sizeof(int));
                acert[idx] = bet[i];
                idx++;
            }
        }
    }

    percent = (tam * 100) / 10;

    printf("Numeros sorteados: \n");

    for(i = 0; i < 10; i++){
        printf("%d ",loto[i]);
    }

    printf("\nNumeros apostados: \n");

    for(i = 0; i < 10; i++){
        printf("%d ",bet[i]);
    }

    printf("\nNumeros acertados: \n");

    for(i = 0; i < tam; i++){
        printf("%d ",acert[i]);
    }

    printf("\nPorcentagem de acertos: %d%%",percent);

    return 0;
}