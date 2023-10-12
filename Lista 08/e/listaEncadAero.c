#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

typedef struct no{
    Aero valor;
    struct no *prox;
}No;

typedef struct lista{
    No *inicio;
    float distancia;
} Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    int distancia = 0;
    return l;
}

void limpar(Lista *l){
    l->inicio->prox = NULL;
    free(l->inicio->prox);
    free(l->inicio);
    free(l);
}

float precoTrecho(Lista *l, float taxa){
    float preco = taxa * l->distancia;
    return preco;
}

int inserirFim(Lista *l, Aero p){
    No *noLista = l->inicio;
    while (noLista->prox != NULL){
        noLista = noLista->prox;
    }
    No *no = (No*)malloc(sizeof(No));
    no->valor = p;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirTrecho(Lista *l, Aero origem, Aero destino, float distancia){
    strcpy(l->inicio->valor.nome, origem.nome);
    strcpy(l->inicio->valor.sigla,origem.sigla);

    No *noLista = (No *) malloc(sizeof(No));

    l->inicio->prox = noLista;

    strcpy(noLista->valor.nome, destino.nome);
    strcpy(noLista->valor.sigla,destino.sigla);

    l->distancia = distancia;

    noLista->prox = NULL;

    if(l == NULL){
        return 1;
    }

    return 0;
}

