#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void pot(int x,int y, int *result);

int main(){
    int x, y, result;

    printf("Insira o valor de 'x': ");
    scanf("%d",&x);

    printf("Insira o valor de 'y': ");
    scanf("%d",&y);

    pot(x,y,&result);

    printf("%d a potencia de %d eh %d\n",x,y,result);

    system("pause");

    return 0;
}

void pot(int x, int y, int*result){
    int i;

    *result = 1;

    for(i = 0; i < y; i++){
        *result *= x;
    }

}

