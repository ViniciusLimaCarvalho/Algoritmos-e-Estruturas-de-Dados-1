#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    int mat[5][10], soma[5], result[5][10], i, j;

    srand(time(NULL));

    for (i = 0; i < 5; i++) {             //loop de preenchimento da matriz
        for (j = 0; j < 10; j++) {       
            mat[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < 5; i++) {             //loop de impressão da matriz
        for (j = 0; j < 10; j++) {       
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 5; i++) {             //loop para zerar os elementos do vetor de soma
        soma[i] = 0;
    }

    for (i = 0; i < 5; i++) {             //loop para realizar a soma das linhas
        for (j = 0; j < 10; j++) {       
            soma[i] += mat[i][j];
        }
    }

    for (i = 0; i < 5; i++) {             //loop para realizar a multiplicação dos elementos da matriz pela soma da linha correspondente
        for (j = 0; j < 10; j++) {       
            result[i][j] = mat[i][j] * soma[i];
        }
    }

    printf("\n\n");

    for (i = 0; i < 5; i++) {             //loop para imprimir a matriz resultante
        for (j = 0; j < 10; j++) {       
            printf("%4d", result[i][j]);
        }
        printf("\n");
    }

    system("pause");

    return 0;
}
