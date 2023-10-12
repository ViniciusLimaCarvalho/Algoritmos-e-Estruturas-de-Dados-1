#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"


typedef struct lista {
    int total;
    Aluno *valores;
}Lista;

Lista *criar(int tam){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL) l->total = 0;

    l->valores = (Aluno *) calloc(tam,sizeof(Aluno));
    return l;
}

void limpar(Lista *l) {
    if (l != NULL) l->total = 0;
}

int inserirInicio(Lista *l, Aluno it, int tam) {
    int i;
    if (l == NULL) return 2;
    if (listaCheia(l,tam) == 0) return 1;
    for (i=l->total;i>0;i--) {
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = it;
    l->total++;
    return 0;
}

int inserirFim(Lista *l, Aluno it, int tam) {
    if (l == NULL) return 2;
    if (listaCheia(l,tam) == 0) return 1;
    l->valores[l->total] = it;
    l->total++;
    return 0;
}

int inserirPosicao(Lista *l,Aluno it,int pos, int tam){
    if (l == NULL){
        return 2;
    }

    if(listaCheia(l, tam) == 0){
        return 1;
    }

    int i;
    ++l->total;
    for(i = (l->total - pos); i > pos;i--){
        l->valores[i] = l->valores[i-1];
    }
    l->valores[pos] = it;

    return 0;
}

int buscarItemChave(Lista *l, int chave,Aluno *retorno) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0;i<l->total;i++)
        if (l->valores[i].mat == chave) {
            *retorno = l->valores[i];
            return 0;
        }
    return -1;
}

int buscarPosicao(Lista* l,int posicao,Aluno *retorno){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    int i;

    retorno->mat = l->valores[posicao].mat;
    strcpy(retorno->nome,l->valores[posicao].nome);
    retorno->n1 = l->valores[posicao].n1;      
        
    return 0;


}

int contemItem(Lista *l, Aluno it){
    int i;

    for(i = 0; i < l->total; i++){
        if(l->valores[i].mat == it.mat){
            if(strcmp(l->valores[i].nome,it.nome)){
                if(l->valores[i].n1 == it.n1){
                    return 0;
                }
            }
        }
    }

    return 1;
}

int contaItem(Lista *l, char *nome){
    int i, num = 0;

    for(i = 0; i < l->total; i++){
        if(strcmp(l->valores[i].nome,nome) == 0){
            num++;
        }
    }

    return num;
}

int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->total == 0) return 0;
    else return 1;
}

int removerInicio(Lista *l) {
    int i;
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    for (i=0;i<l->total-1;i++)
    l->valores[i] = l->valores[i+1];
    l->total--;
    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    l->total--;
    return 0;
}

int removerPosicao(Lista *l,int pos){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    int i;

    for(i = pos; i < l-> total; i++){
        l->valores[i] = l->valores[i+1];
    }

    l->total--;

    return 0;
}

int removerItem(Lista*l,Aluno it){
    if(l == NULL){
        return 2;
    }

    if(listaVazia(l) == 0){
        return 1;
    }

    int i, aux;

    for(i = 0; i < l->total; i++){
        if(l->valores[i].mat == it.mat){
            aux = i;
        }
    }

    removerPosicao(l,aux);

    return 0;
}

int listaCheia(Lista *l, int tam) {
    if (l == NULL) return 2;
    if (l->total == tam) return 0;
    else return 1;
}

void mostrar(Lista *l) {
    int i;
    if (l != NULL) {
        printf("[");
        for (i=0;i<l->total;i++) {
            printf(" {%d, ",l->valores[i].mat);
            printf("%s, ",l->valores[i].nome);
            printf("%.2f} ",l->valores[i].n1);
        }
        printf("]\n");
    }
}

void reversa(Lista *l, Lista *r, int tam){
    int i;

    limpar(r);

    for(i = l->total - 1; i >= 0; i--){
        inserirFim(r,l->valores[i],tam);
    }

    mostrar(r);
}