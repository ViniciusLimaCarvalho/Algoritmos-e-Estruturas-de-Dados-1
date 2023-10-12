#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"strings.h"

int main(){
    int tam;
    char ch;

    printf("Insira o tamanho da string: ");
    scanf("%d",&tam);

    string *s = criar(tam);

    printf("Preencha a string: ");
    valor(s);

    printf("Insira uma letra: ");
    scanf(" %c",&ch);

    printf("Numero de repeticoes dessa letra: %d\n",numCarac(s,ch));
    printf("Tamanho da string: %d\n",tamanho(s));

    printf("\nString: ");
    imprimeString(s);
    printf("\n");

    system("pause");

    return 0;
}