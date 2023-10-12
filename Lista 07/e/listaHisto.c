#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"


typedef struct lista {
    int total;
    Histo valores[TAM];
}Lista;

Lista* criar(){
    Lista *l = (Lista *) malloc (sizeof(Lista));
    if(l != NULL) l->total = 0;
    return l;
}

void limpar(Lista *l){
    if(l != NULL) l->total = 0;
}

int inserirString(Lista *l, char *str){
    int i, j, len, verifica, idx = 0;
    char *noRepeat;

    noRepeat = (char *) malloc(1 * sizeof(char));

    len = strlen(str);

    for(i = 0; i < len; i++){
        verifica = 0;
        for(j = 0; j < i; j++){
            if(str[i] == str[j]){
                verifica = 1;
                break;
            }
        }
        if(verifica == 0){
            noRepeat = (char *) realloc(noRepeat,(idx+1) * sizeof(char));
            noRepeat[idx] = str[i];
            idx++;
        }
    }

    for(i = 0; i < idx; i++){
        l->total++;
        l->valores[i].ch = noRepeat[i];
        l->valores[i].ocorr = 0;
    }

    for(i = 0; i < idx; i++){
        for(j = 0; j < len; j++){
            if(l->valores[i].ch == str[j]){
                l->valores[i].ocorr += 1;
            }
        }
    }

    free(noRepeat);
    return 1;
}

int tamanho(Lista *l){
    return l->total;
}

void mostrar(Lista *l){
    int i, j;

    for(i = 0; i < l->total; i++){
        printf("%c :",l->valores[i].ch);
        for(j = 0; j < l->valores[i].ocorr; j++){
            printf("*");
        }
        printf("\n");
    }
}