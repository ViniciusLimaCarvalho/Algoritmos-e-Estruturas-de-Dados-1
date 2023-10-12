#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"lista.h"

int main(){
    Lista *l = criar();
    int escolha, escolha2, escolha3, escolha4;
    int vezes = 0, len;
    int pos, chave, idx;
    Aluno aux, aux2;

    while(1){
        do{
            printf("MENU\n");
            printf("1)Inserir aluno na lista\n");
            printf("2)Remover aluno da lista\n");
            printf("3)Buscar na lista\n");
            printf("4)Concatenar duas listas\n");
            printf("5)Sair\n");
            scanf("%d",&escolha);

        }while(escolha < 1 || escolha > 5);

        if(escolha == 1){
            if(vezes != 0){
                do{
                    printf("INSERIR ALUNO\n");
                    mostrar(l);
                    printf("\n1)Inserir no inicio da lista\n");
                    printf("2)Inserir aluno no fim da lista\n");
                    printf("3)Inserir aluno em uma posicao da lista\n");
                    scanf("%d",&escolha2);
                }while(escolha2 < 1 || escolha2 > 3);
            }
            else{
                escolha2 = 1;
            }

            if(escolha2 == 1){
                printf("Insira a matricula do aluno: ");
                scanf("%d",&aux.mat);
                printf("Insira o nome do aluno: ");
                setbuf(stdin,NULL);
                fgets(aux.nome,29,stdin);
                len = strlen(aux.nome);
                aux.nome[len -1] = ' ';
                printf("Insira a nota do aluno: ");
                scanf("%f",&aux.n1);

                inserirInicio(l,aux);
                mostrar(l);
            }

            else if(escolha2 == 2){
                printf("Insira a matricula do aluno: ");
                scanf("%d",&aux.mat);
                printf("Insira o nome do aluno: ");
                setbuf(stdin,NULL);
                fgets(aux.nome,29,stdin);
                len = strlen(aux.nome);
                aux.nome[len -1] = ' ';
                printf("Insira a nota do aluno: ");
                scanf("%f",&aux.n1);
                
                inserirFim(l,aux);
                mostrar(l);
            }

            else if(escolha2 == 3){
                printf("Insira a matricula do aluno: ");
                scanf("%d",&aux.mat);
                printf("Insira o nome do aluno: ");
                setbuf(stdin,NULL);
                fgets(aux.nome,29,stdin);
                len = strlen(aux.nome);
                aux.nome[len -1] = ' ';
                printf("Insira a nota do aluno: ");
                scanf("%f",&aux.n1);
                printf("Insira a posicao que deseja inserir: ");
                scanf("%d",&pos);
                pos--;

                inserirPosicao(l,aux,pos);
                mostrar(l);
            }

            vezes++;
        }

        else if(escolha == 2){
            do{
                printf("REMOVER ALUNO\n");
                mostrar(l);
                printf("\n1)Remover aluno do inicio da lista\n");
                printf("2)Remover aluno do fim da lista\n");
                printf("3)Remover aluno de uma posicao escolhida da lista\n");
                printf("4)Remover aluno de acordo com o numero de matricula\n");
                scanf("%d",&escolha3);
            }while(escolha3 < 1 || escolha3 > 4);

            if(escolha3 == 1){
                removerInicio(l);
                mostrar(l);
            }

            else if(escolha3 == 2){
                removerFim(l);
                mostrar(l);
            }

            else if(escolha3 == 3){
                printf("Qual posicao deseja remover: ");
                scanf("%d",&pos);
                --pos;
                removerPosicao(l,pos);
                mostrar(l);
            }

            else{
                printf("Insira o numero de matricula do aluno: ");
                scanf("%d",&aux.mat);
                removerItem(l,aux);
                mostrar(l);
            }
        }

        else if(escolha == 3){
            do{
                printf("BUSCAR\n");
                printf("1)Buscar item da lista\n");
                printf("2)Buscar posicao da lista\n");
                printf("3)Verificar se aluno esta na lista\n");
                printf("4)Buscar aluno com maior nota\n");
                scanf("%d",&escolha4);
            }while(escolha4 < 1 || escolha4 > 4);

            if(escolha4 == 1){
                printf("Insira a matricula do aluno buscado: ");
                scanf("%d",&chave);
                idx = buscarItemChave(l,chave,&aux2);

                if(idx == 0){
                    printf("Aluno encontrado!\n");
                    printf("Matricula: %d\n",aux2.mat);
                    printf("Nome: %s\n",aux2.nome);
                    printf("Nota: %.2f\n",aux2.n1);
                }

                else{
                    printf("O aluno nao existe na lista\n");
                }
            }

            else if(escolha4 == 2){
                printf("Insira a posicao buscada: ");
                scanf("%d",&pos);
                pos--;

                idx = buscarPosicao(l,pos,&aux2);
                
                if(idx == 0){
                    printf("Aluno encontrado\n");
                    printf("Matricula: %d\n",aux2.mat);
                    printf("Nome: %s\n",aux2.nome);
                    printf("Nota: %.2f\n",aux2.n1);
                }
            }

            else if(escolha4 == 3){
                int number;
                Aluno *ex = (Aluno *) malloc (sizeof(Aluno));
                printf("Insira a matricula do aluno buscado: ");
                scanf("%d",&ex->mat);
                number = contemItem(l,ex);
                if(number == 0){
                    printf("O aluno esta na lista.\n");
                }
                else{
                    printf("O aluno nao esta na lista.\n");
                }
            }

            else if(escolha4 == 4){
                Aluno func;

                int verif = maiorNota(l,&func);

                if(verif == 1 || verif == 2){
                    printf("Erro\n");
                }

                printf("Aluno de maior nota:\n");
                printf("Matricula: %d\n",func.mat);
                printf("Nome: %s\n",func.nome);
                printf("Nota: %.2f\n",func.n1);
            }
        }

        else if(escolha == 4){ 
            Lista* r = criar();
            Aluno exemplo;
            int len1;
            printf("CONCATENAR LISTAS\n");
            printf("Sera criada outra lista, quando nao quiser mais inserir elementos, digite -1 na matricula\n");

            while(1){
                printf("Insira a matricula do aluno: ");
                scanf("%d",&exemplo.mat);
                if(exemplo.mat == (-1)){
                    break;
                }
                printf("Insira o nome do aluno: ");
                setbuf(stdin,NULL);
                fgets(exemplo.nome,29,stdin);
                len1 = strlen(exemplo.nome);
                exemplo.nome[len1 - 1] = ' ';
                printf("Insira a nota do aluno: ");
                scanf("%f",&exemplo.n1);

                inserirFim(r,exemplo);
            }

            Lista *c = concat(l,r);
            mostrar(c);
        }

        else if(escolha == 5){
            break;
        }


    }

    limpar(l);

    system("pause");

    return 0;
}