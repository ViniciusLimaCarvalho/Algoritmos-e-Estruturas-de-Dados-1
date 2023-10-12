#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
}No;

typedef struct lista {
    No *inicio;
}Lista;

Lista *criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    return l;
}

int listaVazia(Lista *l) {
    if (l == NULL)
        return 2;
    if (l->inicio == NULL)
        return 0;
    return 1;
}

int inserirInicio(Lista *l, Aluno it) {
    if (l == NULL)
        return 2;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = l->inicio;
    l->inicio = no;
    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL)
    return 2;
    if (listaVazia(l) == 0)
        return inserirInicio(l,it);
    No *noLista = l->inicio;
    while (noLista->prox != NULL)
        noLista = noLista->prox;
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int inserirPosicao(Lista *l, Aluno it, int pos) {
    if (l == NULL) return 2;
    if (pos < 0) return 3;
    if ((listaVazia(l) == 0)||(pos == 0))
        return inserirInicio(l,it);
    No *noLista = l->inicio;
    int p = 1;
    while ((noLista->prox != NULL)&&(p != pos)) {
        p++;
        noLista = noLista->prox;
    }
    No *no = (No*)malloc(sizeof(No));
    no->valor = it;
    no->prox = noLista->prox;
    noLista->prox = no;
    return 0;
}

int removerInicio(Lista *l) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noLista = l->inicio;
    l->inicio = noLista->prox;
    free(noLista);
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL)
        return 2;
    if (listaVazia(l) == 0)
        return 1;
    No *noAuxiliar = NULL;
    No *noLista = l->inicio;
    while (noLista->prox != NULL) {
        noAuxiliar = noLista;
        noLista = noLista->prox;
    }
    if (noAuxiliar == NULL) l->inicio = NULL;
    else noAuxiliar->prox = NULL;
    free(noLista);
    return 0;
}

int removerPosicao(Lista *l, int pos) {
    if (l == NULL) {
        return 2;
    }

    if (listaVazia(l) == 0) {
        return 1;
    }

    if (pos == 0) {
        
        return removerInicio(l);
    }

    No *noAux = NULL;
    No *noLista = l->inicio;
    int p = 0;

   
    while (p < pos - 1 && noLista->prox != NULL) {
        noAux = noLista;
        p++;
        noLista = noLista->prox;
    }

    
    if (noLista->prox == NULL) {
        return 1; 
    }

   
    noAux = noLista;
    noLista = noLista->prox;
    noAux->prox = noLista->prox;

    free(noLista);

    return 0;
}

int removerItem(Lista *l, Aluno it){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    No *noLista = l->inicio;
    int p = 0;

    while((noLista->prox != NULL) && (noLista->valor.mat == it.mat)){
        noLista = noLista->prox;
        p++;
    }

    return removerPosicao(l,p);
}

int removeNprimeiros(Lista *l, int *n){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    int i;

    for(i = *n; i > 0; i--){
        removerInicio(l);
    }

    return 0;
}

int buscarItemChave(Lista *l,int chave,Aluno *retorno) {
    if (l == NULL)
        return 2;
    No *noLista = l->inicio;
    while ((noLista != NULL)) {
        if ((noLista->valor).mat == chave) {
            *retorno = noLista->valor;
            return 0;
        }
        noLista = noLista->prox;
    }
    return 1;
}

int buscarPosicao(Lista *l,int posicao,Aluno *it){
    if(l == NULL) return 2;

    if(listaVazia(l) == 0){
        return 1;
    }

    No *noLista = l->inicio;
    int p = 0;

    while((noLista->prox != NULL) && (p != posicao)){
        p++;
        noLista = noLista->prox;
    }



    it->mat = noLista->valor.mat;
    it->n1 = noLista->valor.n1;
    strcpy(it->nome,noLista->valor.nome);

    return 0;
}

int contemItem(Lista *l, Aluno *it){
    if(l == NULL) return 2;

    if(listaVazia(l) == 0){
        return (-1);
    }

    No *noLista = l->inicio;

    while(noLista->prox !=NULL){
        if(noLista->valor.mat == it->mat){
            return 0;
        }
        noLista = noLista->prox;
    }
    if(noLista->valor.mat == it->mat){
        return 0;
    }

    return 1;
}

int maiorNota(Lista *l,Aluno *retorno){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    No *noLista = l->inicio;
    No *noAux;
    int maior = l->inicio->valor.n1;

    while(noLista->prox != NULL){
        if(noLista->valor.n1 > maior){
            maior = noLista->valor.n1;
            noAux = noLista;
        }
        noLista = noLista->prox;
    }

    retorno->mat = noAux->valor.mat;
    retorno->n1 = maior;
    strcpy(retorno->nome,noAux->valor.nome);

    return 0;
}

void limpar(Lista *l) {
    while (listaVazia(l) != 0)
    removerInicio(l);
}

Lista* concat(Lista *l,Lista *r){
    No *noLista = l->inicio;
    int p = 0;

    while(noLista->prox != NULL){
        noLista = noLista->prox;
    }

    noLista->prox = r->inicio;

    Lista *c = criar();
    c->inicio = l->inicio;

    return c;
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