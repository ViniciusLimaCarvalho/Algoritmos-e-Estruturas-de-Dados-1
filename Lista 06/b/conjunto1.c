#include<stdio.h>
#include<stdlib.h>
#include"conjunto.h"

typedef struct Conjunto{
    int *vet;
    int tam;
} conjunto;

conjunto *criar(int tam){
    conjunto *c;
    c = (conjunto *) malloc(sizeof(conjunto));
    
    c->tam = tam;

    c->vet = (int *) malloc(tam*sizeof(int));

    return c;
}

void insere(conjunto *c, int posicao){
    int aux, i, idx = 0;

    while(1){
        scanf("%d",&aux);

        for(i = 0; i < posicao; i++){
            if(aux == c->vet[i]){
                break;
                ++idx;
            }
        }

        if(idx == 0){
            break;
        }
    }

    c->vet[posicao] = aux;
}

void removeElemento(conjunto *c, int posicao){
      int i;

    if (posicao < 0 || posicao >= c->tam) {
        printf("Posição inválida.\n");
        return;
    }

    for (i = posicao; i < c->tam - 1; i++) {
        c->vet[i] = c->vet[i + 1];
    }

    c->tam--;
    c->vet = (int *)realloc(c->vet, c->tam * sizeof(int));
}

conjunto *uniao(conjunto *c, conjunto *d){
    conjunto *resultado;
    resultado = criar(c->tam + d->tam);

    for (int i = 0; i < c->tam; i++) {
        insere(resultado, c->vet[i]);
    }

    for (int i = 0; i < d->tam; i++) {
        insere(resultado, d->vet[i]);
    }

    return resultado;
}

conjunto *interseccao(conjunto *c, conjunto *d){
    conjunto *resultado;
    resultado = criar(c->tam < d->tam ? c->tam : d->tam);

    for (int i = 0; i < c->tam; i++) {
        for (int j = 0; j < d->tam; j++) {
            if (c->vet[i] == d->vet[j]) {
                insere(resultado, c->vet[i]);
                break;
            }
        }
    }

    return resultado;
}

conjunto *diferenca(conjunto *c, conjunto *d){
    conjunto *resultado;
    resultado = criar(c->tam);

    for (int i = 0; i < c->tam; i++) {
        int estaNaD = 0;

        for (int j = 0; j < d->tam; j++) {
            if (c->vet[i] == d->vet[j]) {
                estaNaD = 1;
                break;
            }
        }

        if (!estaNaD) {
            insere(resultado, c->vet[i]);
        }
    }

    return resultado;
}