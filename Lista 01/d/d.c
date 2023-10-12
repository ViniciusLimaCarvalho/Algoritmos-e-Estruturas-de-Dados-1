#include<stdio.h>
#include<windows.h>

int main(){
    float n1, n2, n3, mediaFinal, exameFinal;

    printf("Insira a nota 1: ");
    scanf("%f",&n1);

    printf("Insira a nota 2: ");
    scanf("%f",&n2);

    printf("Insira a nota 3: ");
    scanf("%f",&n3);

    mediaFinal = (n1 + n2 + n3) / 3;

    if(mediaFinal >= 0 && mediaFinal < 3){
        printf("Aluno reprovado.\n");
    }

    else if(mediaFinal >=3 && mediaFinal < 7){
        exameFinal = 12 - mediaFinal;
        printf("Aluno em exame final (precisa de %.1f pontos).\n",exameFinal);
    }

    else if(mediaFinal >= 7 && mediaFinal <= 10){
        printf("Aluno aprovado.\n");
    }

    system("pause");

    return 0;
}