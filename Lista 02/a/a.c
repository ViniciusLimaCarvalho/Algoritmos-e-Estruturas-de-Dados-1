#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){
    double vet[10];
    char nome[25] = "Carla Faria";
    int i;

    srand(time(NULL));

    for(i = 0; i < 10; i++){
        *(vet + i) = rand() % 100;
    }

    printf("Nome: ");

    for(i = 0;i < 11; i++){
        printf("%c",*(nome + i));
    }

    printf("\n\nNumeros do vetor: ");

    for(i = 0; i < 10; i++){
        printf("%.1lf ",*(vet + i));
    }

    printf("\n\n");

    system("pause");

    return 0;
}
