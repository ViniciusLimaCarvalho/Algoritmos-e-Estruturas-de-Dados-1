#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void elementosMat(int **mat, int col, int lin, int tam, int *vet);

void removeRepeticoes(int **vetor, int *tamanho);

int main() {
    int **mat, *vet = NULL, i, j, col, lin, tam = 0;

    printf("Insira a quantidade de linhas da matriz: ");
    scanf("%d", &lin);

    printf("Insira a quantidade de colunas da matriz: ");
    scanf("%d", &col);

    mat = (int **)calloc(lin, sizeof(int *));
    for (i = 0; i < lin; i++) {
        mat[i] = (int *)calloc(col, sizeof(int));
    }

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Insira o elemento de linha %d e coluna %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    tam = col * lin;
    vet = (int *)calloc(tam, sizeof(int));
    elementosMat(mat, col, lin, tam, vet);

    removeRepeticoes(&vet, &tam);

    printf("Matriz: \n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor sem repeticoes:\n");
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }


    free(vet);
    for (i = 0; i < lin; i++) {
        free(mat[i]);
    }
    free(mat);

    printf("\n");

    system("pause");

    return 0;
}

void elementosMat(int **mat, int col, int lin, int tam, int *vet) {
    int a = 0, i, j;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            vet[a] = mat[i][j];
            a++;
        }
    }
}

void removeRepeticoes(int **vetor, int *tamanho) {
    int novoTamanho = 0;
    int *novoVetor = (int *)calloc(*tamanho, sizeof(int));

    for (int i = 0; i < *tamanho; i++) {
        int repetido = 0;

        for (int j = 0; j < novoTamanho; j++) {
            if ((*vetor)[i] == novoVetor[j]) {
                repetido = 1;
                break;
            }
        }

        if (!repetido) {
            novoVetor[novoTamanho] = (*vetor)[i];
            novoTamanho++;
        }
    }

    free(*vetor);
    *vetor = (int *)calloc(novoTamanho, sizeof(int));
    for (int i = 0; i < novoTamanho; i++) {
        (*vetor)[i] = novoVetor[i];
    }
    free(novoVetor);

    *tamanho = novoTamanho;
}
