#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"strings.h"

typedef struct String{
    char *str;
    int tam;
} string;

string *criar(int tam){
    string *s;
    s = (string *)malloc(sizeof(string));
    s->str = (char *) malloc (tam*sizeof(char));
    s->tam = tam;
    return s;
}

void valor(string *s){
    setbuf(stdin,NULL);
    fgets(s->str,s->tam,stdin);
}

int tamanho(string *s){
    return s->tam;
}

int numCarac(string *s, char ch){
    int i, num = 0;

    for(i = 0; i <= s->tam; i++){
        if(s->str[i] == ch){
            ++num;
        }
    }

    return num;
}

void imprimeString(string *s){
    int i;

    for(i = 0; i < strlen(s->str); i++){
        printf("%c",s->str[i]);
    }
}