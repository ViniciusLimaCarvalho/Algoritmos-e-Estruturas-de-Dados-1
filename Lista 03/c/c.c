#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int pot(int x, int y);

double fat(int x);

int main(){
    int x, n, i, taylor = 1;

    printf("Insira o numero x: ");
    scanf("%d",&x);

    printf("Insira o numero n: ");
    scanf("%d",&n);

    for(i = 0; i <= n; i++){
        taylor += (pot(x,i) / fat(i));
    }

    printf("e^x = %d\n",taylor);

    system("pause");

    return 0;
}

int pot(int x, int y){


    int i, temp;

    temp = 1;

    for(i = 0; i < y; i++){
        temp *= x;
    }

    return temp;
}


double fat(int x){
    if(x <= 1){
        return 1;
    }

    else{
        return x * fat(x-1);
    }
}
