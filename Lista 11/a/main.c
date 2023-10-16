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
    mostrar(l);
    int tam = tamanho(l);
    printf("%d",tam);
    system("pause");
    return 0;

}