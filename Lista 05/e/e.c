#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

int main() {
    int loto[50], bet[50], *acert = NULL, tamanho = 0;
    int i, j, count = 0, percent;

    printf("Insira os numeros sorteados na lotomania:\n");
    for (i = 0; i < 50; i++) {
        int repeticao = 0;
        do {
            printf("%d. ", i + 1);
            scanf("%d", &loto[i]);

            repeticao = 0;
            for (j = 0; j < i; j++) {
                if (loto[i] == loto[j]) {
                    repeticao = 1;
                    printf("Erro: numero ja informado\n");
                    break;
                }
            }
        } while (repeticao > 0);
    }

    printf("\nInsira os numeros da sua aposta:\n");
    for (i = 0; i < 50; i++) {
        int repeticao = 0;
        do {
            printf("%d. ", i + 1);
            scanf("%d", &bet[i]);

            repeticao = 0;
            for (j = 0; j < i; j++) {
                if (bet[i] == bet[j]) {
                    repeticao = 1;
                    printf("Erro: numero ja informado\n");
                    break;
                }
            }
        } while (repeticao > 0);
    }

    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            if (bet[i] == loto[j]) {
                count++;
                tamanho++;
                acert = (int *)realloc(acert, tamanho * sizeof(int));
                acert[tamanho - 1] = bet[i];
            }
        }
    }

    percent = (count * 100) / 50;

    printf("Numeros sorteados: ");
    for (i = 0; i < 50; i++) {
        printf("%d ", loto[i]);
    }

    printf("\nNumeros acertados: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", acert[i]);
    }

    printf("\nPorcentagem de acertos: %d%%\n", percent);

    free(acert);

    system("pause");

    return 0;
}
