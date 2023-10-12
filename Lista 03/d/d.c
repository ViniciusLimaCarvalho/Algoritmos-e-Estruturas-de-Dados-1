#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int divisao(int a, int b, int *quociente, int *resto);

int main(){
    int a, b, quociente, resto;

    printf("Insira os numeros'a' e 'b' separados por espaco: ");
    scanf("%d %d",&a,&b);

    divisao(a,b,&quociente,&resto);

    if(divisao(a,b,&quociente,&resto) == 0){
        printf("Quociente da divisao: %d\n",quociente);
        printf("Resto da divisao: %d\n",resto);
    }

    else{
        printf("Nao foi possivel realizar a divisao\n");
    }

    system("pause");

    return 0;

}

int divisao(int a, int b, int *quociente, int *resto){
    if(b != 0){
        *quociente = a / b;

        *resto = a % b;

        return 0;
    }
    else{
        return (-1);
    }
}
