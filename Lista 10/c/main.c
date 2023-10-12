#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lista.h"

int main(){
    Lista *l = criar();
    Aluno aux;
    int escolha, escolha2, escolha3;
    int vezes = 0;
    int len, pos;                                                                                                                                                      
    
    while(1){
        do{
            printf("MENU\n");
            printf("1)Cadastrar aluno\n");
            printf("2)Remover aluno\n");
            printf("3)Listar alunos cadastrados\n");
            printf("4)Mostrar dados do aluno com maior nota\n");
            printf("5)Remover todos os alunos\n");
            printf("6)Trocar posicoes\n");
            printf("7)Verificar igualdade de listas\n");
            printf("8)Sair\n");
            scanf("%d",&escolha);
        }while(escolha < 1 || escolha > 8);

        if(escolha == 1){
            if(vezes != 0){
                do{
                    printf("CADASTRAR ALUNO\n");
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

                inserirPos(l,aux,pos);
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
                scanf("%d",&escolha3);
            }while(escolha3 < 1 || escolha3 > 3);

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
                removePosicao(l,pos);
                mostrar(l);
            }

    
        }
        else if(escolha == 3){
            mostrar(l);
        }
        else if(escolha == 4){
            maiorNota(l,&aux);

            printf("Matricula: %d\n",aux.mat);
            printf("Nome: %s\n",aux.nome);
            printf("Nota: %.2f\n",aux.n1);
        }
        else if(escolha == 5){
            while(listaVazia(l) != 0){
                removerFim(l);
            }
        }

        else if(escolha == 6){
            int pos1, pos2;

            printf("Digite, separado por espaco, as posicoes a serem trocadas: ");
            scanf("%d %d",&pos1, &pos2);
            pos1--;pos2--;

            trocarPosicoes(l,pos1,pos2);
        }

        else if(escolha == 7){
            Lista* r = criar();
            Aluno exemplo;
            int len1;
            printf("COMPARAR LISTAS\n");
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

            int verifier = comparar(l,r);

            if(verifier == 0){
                printf("Listas iguais\n");
            }

            else{
                printf("Listas diferentes\n");
            }

            limpar(r);
        }

        else if(escolha == 8){
            break;
        }
    
    }

    system("pause");
    return 0;
}