#include<stdio.h>
#include<windows.h>

int main(){
    float op1, op2, result;
    char operacao;

    printf("Insira a operacao: (ex. formato '2 + 3'): ");
    scanf("%f %c %f",&op1,&operacao,&op2);

    op:
    switch(operacao){
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
        case 'x':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        default:
            goto op;
    }

    printf("Resultado = %.2f\n",result);

    system("pause");

    return 0;
}