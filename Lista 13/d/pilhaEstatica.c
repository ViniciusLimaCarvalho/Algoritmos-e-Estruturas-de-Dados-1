#include <stdio.h>
#include<stdlib.h>
#include "pilha.h"

typedef struct pilha {
    int topo;
    int valores[MAX];
}Pilha;

Pilha *criar() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = 0;
    return p;
}

void limpar(Pilha *p) {
    free(p);
    p = NULL;
}

int saoIguais(Pilha* p1, Pilha* p2){
    if (p1 == NULL || p2 == NULL) {
        return 0;
    }

    if (p1->topo != p2->topo) {
        return 0; 
    }

    for (int i = 0; i < p1->topo; i++) {
        if (p1->valores[i] != p2->valores[i]) {
            return 0; 
        }
    }

    return 1;
}

int push(Pilha *p, int it) {
    if (p == NULL) return 2;
    if (pilhaCheia(p) == 0) return 1;
    p->valores[p->topo] = it;
    p->topo++;
    return 0;
}

int pop(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    *it = p->valores[p->topo-1];
    p->topo--;
    return 0;
}

int consultar(Pilha *p, int *it) {
    if (p == NULL) return 2;
    if (pilhaVazia(p) == 0) return 1;
    *it = p->valores[p->topo-1];
    return 0;
}

int tamanho(Pilha *p) {
    if (p == NULL) return -1;
    return p->topo;
}

int pilhaVazia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == 0) return 0;
    else return 1;
}

int pilhaCheia(Pilha *p) {
    if (p == NULL) return 2;
    if (p->topo == MAX) return 0;
    else return 1;
}

void mostrar(Pilha *p) {
    if (p != NULL) {
        printf("[");
        int i;
        for (i=0;i<p->topo;i++) {
            printf("{%d}, ",p->valores[i]);
        }
        printf("]\n");
    }
}

void decimalParaBinario(int numero) {
    Pilha *p = criar();

    while (numero > 0) {
        push(p, numero % 2);
        numero /= 2;
    }

    printf("O numero em binario eh: ");

    while (pilhaVazia(p) != 0) {
        int bit;
        pop(p, &bit);
        printf("%d", bit);
    }

    printf("\n");

    limpar(p);
}