#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

int main(){
    int escolha, len;
    Lista *l = criar();
    Aero idx;

    while(1){
        do{
            printf("MENU\n");
            printf("1)Inserir aeroporto\n");
            printf("2)Inserir rota\n");
            printf("3)Consultar preco\n");
            printf("4)Sair\n");
            scanf("%d",&escolha);
        }while(escolha < 1 || escolha > 4);

        if(escolha == 1){
            printf("Insira o nome do aeroporto: ");
            setbuf(stdin,NULL);
            fgets(idx.nome,29,stdin);
            len = strlen(idx.nome);
            idx.nome[len - 1] = ' ';

            printf("Insira a sigla do aeroporto: ");
            setbuf(stdin,NULL);
            fgets(idx.sigla,3,stdin);
            len = strlen(idx.sigla);
            idx.sigla[len - 1] = ' ';

            inserirFim(l,idx);
        }

        else if(escolha == 2){
            
        }


        
    }
}