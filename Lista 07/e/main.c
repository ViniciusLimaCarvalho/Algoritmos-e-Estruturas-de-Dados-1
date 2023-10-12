#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"lista.h"

int main(){
    Lista *l;
    char str[2000];
    int len;

    l = criar();

    printf("Insira um texto de ate 2000 caracteres: ");
    setbuf(stdin,NULL);
    fgets(str,1999,stdin);

    len = strlen(str);

    str[len - 1] = ' ';

    inserirString(l,str);
    mostrar(l);

    system("pause");

    return 0;
}