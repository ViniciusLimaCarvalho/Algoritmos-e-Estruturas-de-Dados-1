#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int substitui(char *str, int tam, char ch);

int main(){
    char *str, ch;
    int tam, qtd;

    printf("Insira o tamanho da string: ");
    scanf("%d",&tam);

    str = (char *) calloc(tam,sizeof(char));

    printf("Insira a string: ");
    setbuf(stdin,NULL);
    fgets(str,tam,stdin);

    printf("Insira o caractere a ser substituido: ");
    scanf(" %c",&ch);

    qtd = substitui(str, tam, ch);

    printf("String apos substituicao: %s",str);
    printf("Quantidade de substituicoes: %d\n",qtd);

    system("pause");

    return 0;
}

int substitui(char *str, int tam, char ch){
    int i, aux = 0;

    for(i = 0; i < tam; i++){
        if(*(str + i) == ch){
            *(str + i) = '*';
            aux++;
        }
    }

    return aux;
}