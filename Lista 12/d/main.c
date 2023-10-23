#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(){
    int escolha,aux,num, senha = 1;
    Fila *f = criar();

    while(1){
        do{
            printf("MENU\n");
            printf("1)Gerar senha\n");
            printf("2)Paciente atendido\n");
            printf("3)Sair\n");
            printf("Escolha: ");
            scanf("%d",&escolha);
        }while(escolha < 0 || escolha > 3);

        switch(escolha){
        case 1:
            system("cls");
            printf("A senha gerada eh %d.\n", senha);
            inserir(f,aux);
            senha++;
            break;

        case 2:
            system("cls");
            printf("O primeiro paciente na fila sera removido.\n");
            remover(f,&num);
            consultar(f,&num);
            printf("O proximo a ser atendido eh %d\n",num);
            break;
        }

        if(escolha == 3) break;
    }

    system("pause");
    return 0;
}
