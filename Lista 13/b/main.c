#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"pilha.h"


void exibirMenu() {
    printf("MENU\n");
    printf("1) Inserir elemento na Pilha 1\n");
    printf("2) Inserir elemento na Pilha 2\n");
    printf("3) Remover elemento da Pilha 1\n");
    printf("4) Remover elemento da Pilha 2\n");
    printf("5) Comparar pilhas\n");
    printf("6) Sair\n");
    printf("Opcao: ");
}

int main() {
    Pilha *pilha1 = criar();
    Pilha *pilha2 = criar();

    int opcao, elemento, num;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido na Pilha 1: ");
                scanf("%d", &elemento);
                push(pilha1, elemento);
                break;

            case 2:
                printf("Digite o elemento a ser inserido na Pilha 2: ");
                scanf("%d", &elemento);
                push(pilha2, elemento);
                break;

            case 3:
                if (pop(pilha1, &elemento)) {
                    
                }
                break;

            case 4:
                if (pop(pilha2, &elemento)) {
                    
                }
                break;

            case 5:
                num = saoIguais(pilha1, pilha2);
                if(num == 0) printf("Pilhas diferentes\n");
                else printf("Pilhas iguais\n");
                break;

            case 6:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Escolha uma opção válida.\n");
                break;
        }
    } while (opcao != 6);

    limpar(pilha1);
    limpar(pilha2);

    system("pause");

    return 0;
}