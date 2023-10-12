#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
    struct no *ant;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

void limpar(Lista *l) {
    while (listaVazia(l) != 0)
    removerInicio(l);
    free(l);
    l = NULL;
}

int tamanho(Lista *l) {
    if (l == NULL) return -1;
    No *no = l->inicio;
    int cont = 0;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

void mostrar(Lista *l) {
    if (l != NULL) {
        printf("[");
        No *noLista = l->inicio;
        while (noLista != NULL) {
            printf(" {%d, ",noLista->valor.mat);
            printf("%s, ",noLista->valor.nome);
            printf("%.2f} ",noLista->valor.n1);
            noLista = noLista->prox;
        }
        printf("]\n");
    }
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->inicio == NULL)
    return 0;
    else    
    return 1;
}
    
int listaCheia(Lista *l) {
    return 1;
}

int inserirInicio(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    No *no = (No *)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    no->ant = NULL;
    if (l->inicio != NULL)
    l->inicio->ant = no;
    l->inicio = no;
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
    return inserirInicio(l,it);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
    noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = NULL;
    no->ant = noLista;
    noLista->prox = no;
    return 0;
}

int inserirPos(Lista *l, Aluno it, int pos){
    if (l == NULL) return 1;
    if ((listaVazia(l) == 0)||(pos == 0))
    return inserirInicio(l,it);
    No *nl = l->inicio;
    while ((nl->prox != NULL)&&(pos > 1)) {
        nl = nl->prox;
        pos--;
    }
    No *n = (No*)malloc(sizeof(No));
    n->valor = it;
    n->ant = nl;
    n->prox = nl->prox;
    nl->prox = n;
    if (n->prox != NULL) n->prox->ant = n;
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
    return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    if (l->inicio != NULL)
    l->inicio->ant = NULL;
    free(noLista);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0)
    return 1;
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
    noLista = noLista->prox;
    if (noLista->ant == NULL)
    l->inicio = NULL;
    else
    noLista->ant->prox = NULL;
    free(noLista);
    return 0;

}

int removePosicao(Lista *l, int pos) {
    if (l == NULL) return 1;
    if (listaVazia(l) == 0) return 2;
    No *n = l->inicio;
    while ((n->prox != NULL)&&(pos > 0)) {
        n = n->prox;
        pos--;
    }
    if (n->ant == NULL) return removerInicio(l);
    if (n->prox == NULL) return removerFim(l);
    n->ant->prox = n->prox;
    n->prox->ant = n->ant;
    free(n);
    return 0;
}

int maiorNota(Lista *l, Aluno *retorno){
    if(listaVazia(l) == 0) return 1;
    if(l == NULL) return 2;

    int maior = l->inicio->valor.n1;

    No* noLista = l->inicio;

    while(noLista->prox != NULL){
        if(noLista->valor.n1 > maior){
            maior = noLista->valor.n1;
        }
        noLista = noLista->prox;
    }

    noLista = l->inicio;

    while(noLista->prox != NULL){
        if(maior == noLista->valor.n1){
            retorno->mat = noLista->valor.mat;
            retorno->n1 = noLista->valor.n1;
            strcpy(retorno->nome,noLista->valor.nome);
            break;
        }
    }

    return 0;
}

