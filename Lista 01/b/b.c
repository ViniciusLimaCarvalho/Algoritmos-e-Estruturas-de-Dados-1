#include<stdio.h>
#include<windows.h>

int main(){
    int idade, idade2030, anoNascimento, anoAtual;
    char aniversarioFeito;

    printf("Insira o ano atual: ");
    scanf("%d",&anoAtual);

    printf("Insira o ano de seu nascimento: ");
    scanf("%d",&anoNascimento);

    do{
        printf("Voce ja fez aniversario esse ano ? (S/N): ");
        scanf(" %c",&aniversarioFeito);

        if(aniversarioFeito == 'S' || aniversarioFeito == 's'){
            idade = anoAtual - anoNascimento;
        }

        else if(aniversarioFeito == 'N' || aniversarioFeito == 'n'){
            idade = (anoAtual - 1) - anoNascimento;
        }

    }while(aniversarioFeito != 'S' && aniversarioFeito != 's' && aniversarioFeito != 'N' && aniversarioFeito != 'n');


    idade2030 = 2030 - anoNascimento;

    printf("Idade atual = %d\n",idade);
    printf("Idade em 2030 = %d\n",idade2030);

    system("pause");

    return 0;
}