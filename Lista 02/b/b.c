#include<stdio.h>
#include<windows.h>

int main(){
    int *vet, i;

    vet = (int *) calloc(5,sizeof(int));

    for(i = 0; i < 5; i++){
        printf("Insira o %do. numero: ",i+1);
        scanf("%d",(vet + i));
    }

    for(i = 0; i < 5; i++){
        printf("%d. %d\n",i+1,*(vet+i));
    }

    free(vet);

    printf("\n\n");

    system("pause");

    return 0;
}
