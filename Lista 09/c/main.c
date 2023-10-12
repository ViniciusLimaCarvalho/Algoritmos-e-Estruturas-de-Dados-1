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
            printf("4)Sair\n");
            scanf("%d",&escolha);

        }while(escolha < 1 || escolha > 4);

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
                printf("5)Remover meio da lista\n");
                scanf("%d",&escolha3);
            }while(escolha3 < 1 || escolha3 > 5);

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
                removerPosicao(l,pos);
                mostrar(l);
            }

            else if(escolha3 == 4){
                printf("Insira o numero de matricula do aluno: ");
                scanf("%d",&aux.mat);
                removerItem(l,aux.mat);
                mostrar(l);
            }

            else if(escolha3 == 5){
                removerElementoPosicaoCentral(l);
                mostrar(l);
            }
        }

        else if(escolha == 3){
            do{
                printf("BUSCAR\n");
                printf("1)Buscar item da lista\n");
                printf("2)Buscar posicao da lista\n");
                scanf("%d",&escolha4);
            }while(escolha4 < 1 || escolha4 > 2);

            if(escolha4 == 1){
                printf("Insira a matricula do aluno buscado: ");
                scanf("%d",&chave);
                idx = buscarItem(l,chave,&aux2);

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

            else if(escolha4 == 4){
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

        

           
        }

        else if(escolha == 4){
            break;
        }


    }

    limpar(l);

    system("pause");

    return 0;
}