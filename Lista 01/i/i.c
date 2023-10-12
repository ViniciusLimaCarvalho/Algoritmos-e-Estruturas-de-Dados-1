#include <stdio.h>
#include <windows.h>

#define NUM_LIVROS 5

struct Livro {
    char titulo[100];
    int ano_edicao;
    int num_paginas;
    float preco;
};

int main() {
    struct Livro livros[NUM_LIVROS];

    printf("Digite os dados dos livros:\n");
    for (int i = 0; i < NUM_LIVROS; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: ");
        fgets(livros[i].titulo, sizeof(livros[i].titulo), stdin);
        printf("Ano de Ediçao: ");
        scanf("%d", &livros[i].ano_edicao);
        printf("Numero de Paginas: ");
        scanf("%d", &livros[i].num_paginas);
        printf("Preço: ");
        scanf("%f", &livros[i].preco);

        while (getchar() != '\n');
        printf("\n");
    }

    int soma_paginas = 0;
    for (int i = 0; i < NUM_LIVROS; i++) {
        soma_paginas += livros[i].num_paginas;
    }
    float media_paginas = (float)soma_paginas / NUM_LIVROS;

    printf("Media do numero de paginas dos livros: %.2f\n", media_paginas);

    system("pause");

    return 0;
}
