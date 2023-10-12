#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

typedef struct Conjunto {
    int *vet;
    int tam;
} conjunto;

conjunto *criar(int tam);
void insere(conjunto *c, int posicao);
void removeElemento(conjunto *c, int posicao);
conjunto *uniao(conjunto *c, conjunto *d);
conjunto *interseccao(conjunto *c, conjunto *d);
conjunto *diferenca(conjunto *c, conjunto *d);

int main() {
    int tamConjuntoA, tamConjuntoB;

    printf("Digite o tamanho do conjunto A: ");
    scanf("%d", &tamConjuntoA);
    conjunto *A = criar(tamConjuntoA);

    printf("Preencha o conjunto A:\n");
    for (int i = 0; i < tamConjuntoA; i++) {
        insere(A, i);
    }

    printf("Digite o tamanho do conjunto B: ");
    scanf("%d", &tamConjuntoB);
    conjunto *B = criar(tamConjuntoB);

    printf("Preencha o conjunto B:\n");
    for (int i = 0; i < tamConjuntoB; i++) {
        insere(B, i);
    }

    conjunto *uniaoAB = uniao(A, B);
    conjunto *interseccaoAB = interseccao(A, B);
    conjunto *diferencaAB = diferenca(A, B);

    printf("Conjunto A: ");
    for (int i = 0; i < A->tam; i++) {
        printf("%d ", A->vet[i]);
    }
    printf("\n");

    printf("Conjunto B: ");
    for (int i = 0; i < B->tam; i++) {
        printf("%d ", B->vet[i]);
    }
    printf("\n");

    printf("União de A e B: ");
    for (int i = 0; i < uniaoAB->tam; i++) {
        printf("%d ", uniaoAB->vet[i]);
    }
    printf("\n");

    printf("Interseção de A e B: ");
    for (int i = 0; i < interseccaoAB->tam; i++) {
        printf("%d ", interseccaoAB->vet[i]);
    }
    printf("\n");

    printf("Diferença de A e B: ");
    for (int i = 0; i < diferencaAB->tam; i++) {
        printf("%d ", diferencaAB->vet[i]);
    }
    printf("\n");

    free(A->vet);
    free(A);
    free(B->vet);
    free(B);
    free(uniaoAB->vet);
    free(uniaoAB);
    free(interseccaoAB->vet);
    free(interseccaoAB);
    free(diferencaAB->vet);
    free(diferencaAB);

    return 0;
}
