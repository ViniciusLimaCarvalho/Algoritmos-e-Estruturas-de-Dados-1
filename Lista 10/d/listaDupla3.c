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

int removeRepeticao(Lista *l){
    if(listaVazia(l) == 0){
        return 2;
    }
    if(l == NULL) return 1;

    int *aux = (int *) malloc(1 * sizeof(int));
    int tam = 1, i;
    No *noLista = l->inicio;
    
    while(noLista != NULL){
        for(i = 0; i < tam; i++){
            if(noLista->valor.mat == aux[i]){
                removePosicao(l,i + 1);
            }
        }
        *(aux + tam - 1) = noLista->valor.mat;
        tam++;
        aux = (int *) realloc(aux,tam * sizeof(int));
        noLista = noLista->prox;
    }

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

int trocarPosicoes(Lista *l, int pos1, int pos2){
    Aluno aux1, aux2;
    
    buscarPosicao(l,pos1,&aux1);

    buscarPosicao(l,pos2,&aux2);

    removePosicao(l,pos1);

    inserirPos(l,aux2,pos1);

    removePosicao(l,pos2);

    inserirPos(l,aux1,pos2);

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

int comparar(Lista *l, Lista *r){
    No *noLista = l->inicio;
    No *noAux = r->inicio;

    Aluno ok;
    Aluno key;

    int tam1 = 1, tam2 = 1, i;

    int *vet1 = (int *) calloc(tam1,sizeof(int));
    int *vet2 = (int *) calloc(tam2,sizeof(int));

    int verificador = 0;
    int verificador1 = 0;
    
    while(noLista != NULL){
        vet1 = (int *) realloc(vet1,tam1 *sizeof(int));
        vet1[tam1 - 1] = noLista->valor.mat;
        noLista = noLista->prox; 
        tam1++;
    }

    while(noAux != NULL){
        vet2 = (int *) realloc(vet2,tam2 * sizeof(int));
        vet2[tam2 - 1] = noAux->valor.mat;
        noAux = noAux->prox;
        tam2++;
    }
    
    tam1--;
    tam2--;

    for(i = 0; i < tam1; i++){
        if(buscarItemChave(r,vet1[i],&ok) == 0){
            verificador += 1;
        }
    }

    for(i = 0; i < tam2; i++){
        if(buscarItemChave(l,vet2[i],&key) == 0){
            verificador1 += 1;
        }
    }



    if (verificador == tam1 && verificador1 == tam2){
        return 0;
    }
    else{
        return 1;
    }
}