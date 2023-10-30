#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"pilha.h"


int main(){
    Pilha *p = criar();
    int *aux = (int *) malloc(sizeof(int));

    push(p,11); push(p,34); pop(p,aux); pop(p,aux); push(p,23); push(p,45); pop(p,aux); push(p,121); push(p,22); pop(p,aux); pop(p,aux);

    mostrar(p);

    system("pause");

    return 0;
}