#include<stdio.h>
#include<stdlib.h>
#include"listarecursiva.h"

typedef struct no{
    int valor;
    struct no* prox;
}No;

lista *Criar(){
    lista *l = (lista*)malloc(sizeof(lista));
    (*l) = NULL;
    return l;
}

int inserirInicio(lista *l, int it){
    if (*l == NULL)
        return 2;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = (*l);
    *l = no;
    return 0;
}

int inserirFim(lista *l, int it){
    if (l == NULL)
    return 2;
    if (listaVazia(l) == 0)
        return inserirInicio(l,it);
    No *noLista = *l;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao(lista *l, int it, int pos){
    if(l == NULL) return 2;

    No *noLista = *l;
    No *noAux = (No *) malloc(sizeof(No));

    int i = 1;

    while(noLista->prox != NULL || i < pos){
        noLista = noLista->prox;
        i++;
    }

    noAux->valor = it;
    noAux->prox = noLista->prox->prox;
    noLista->prox = noAux;

    return 0;
}

int removerInicio(lista *l);
int removerFim(lista *l);
int removerPosicao(lista *l);
int removerItem(lista *l);

int listaVazia(lista *l){
    if(l == NULL) return 2;
    if((*l) == NULL) return 0;
    else return 1;
}

int buscarItem(lista *l, int it);
int buscarPosicao(lista *l, int pos, int *it);

void mostrar(lista *l){
    printf("{");
    imprime(l);
    printf("}");
}

int imprime(lista *l){
    if(*l == NULL) return 0;

    No *n = (*l);

    printf("%d; ",n->valor);

    imprime(&(n->prox));
}

int tamanho(lista *l){
    if(l == NULL) return (-1);

    if(listaVazia(l) == 0) return 0;

    No *n = (*l);

    return tamanho(&(n->prox)) + 1; 
}