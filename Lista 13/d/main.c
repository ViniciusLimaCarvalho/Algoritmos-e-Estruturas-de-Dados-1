#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"pilha.h"

int main() {
    int numeroDecimal;

    printf("Digite um numero decimal: ");
    scanf("%d", &numeroDecimal);

    decimalParaBinario(numeroDecimal);

    system("pause");

    return 0;
}