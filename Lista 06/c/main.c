#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include "matriz.h"

int main(){
    int lin, col;
    float min, max;

    printf("Insira o valor minimo e o maximo para os elementos das matrizes: ");
    scanf("%f %f",&min, &max);

    printf("Insira as dimensoes da matriz: ");
    scanf("%d %d",&lin,&col);


    matriz *m = criar(lin,col);

    printf("Matriz 1 antes de preencher: \n");

    mostrar(m);

    preenche(m,min,max);

    printf("Matriz 1 depois de preencher: \n");

    mostrar(m);

    matriz *n = criar(lin,col);

    preenche(n,min,max);

    printf("Matriz 2 depois de preencher: \n");

    mostrar(n);

    matriz *s = soma(m,n);

    printf("Soma das matrizes: \n");
    mostrar(s);

    printf("\nA matriz Soma tem %d linhas e %d colunas\n",linha(s),coluna(s));

    destruir(m);
    destruir(n);
    destruir(s);


    system("pause");

    return 0;
}
