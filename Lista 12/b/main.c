#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(){
    int escolha,aux,num;
    Fila *f = criar();

    while(1){
        do{
            printf("MENU\n");
            printf("1)Inserir elemento na fila\n");
            printf("2)Remover elemento da fila\n");
            printf("3)Mostrar elementos da fila\n");
            printf("4)Intercalar duas listas\n");
            printf("5)Sair\n");
            printf("Escolha: ");
            scanf("%d",&escolha);
        }while(escolha < 0 || escolha > 5);

        switch(escolha){
        case 1:
            system("cls");
            printf("Insira o numero a ser inserido: ");
            scanf("%d",&aux);
            inserir(f,aux);
            break;

        case 2:
            system("cls");
            printf("O primeiro na elemento na fila sera removido.\n");
            remover(f,&num);
            break;

        case 3:
            system("cls");
            mostrar(f);
            break;

        case 4:
            system("cls");
            printf("Insira os elementos da fila secundaria (-1 para parar)\n");

            Fila *r = criar();
            Fila *intercalada = criar();

            while(1){
                printf("Insira o numero: ");
                scanf("%d",&aux);
                if(aux == -1) break;
                inserir(r,aux);
            }

            intercalarFilas(f,r,intercalada);

            mostrar(intercalada);

            limpar(intercalada);
            limpar(r);
            break;

        }

        if(escolha == 5) break;
    }

    system("pause");
    return 0;
}
