#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "listarecursiva.h"


int main(){
    int aux;
    lista *l = Criar();

    while(1){
        printf("Insira numero: ");
        scanf("%d",&aux);
        inserirFim(l,aux);
        if(aux == (-1)) break;
    }
    int *num;
    ultimoElemento(l, num);

    printf("O ultimo elemento eh %d",*num);

    int soma = somaElementos(l);
    printf("%d",soma);

    system("pause");
    return 0;

}