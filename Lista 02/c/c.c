#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int **mat1, **mat2, **matSoma, i, j;

    srand(time(NULL));




    mat1 = (int **) calloc(3,sizeof(int *));

    for(i = 0; i < 3; i++){
        mat1[i] = (int *) calloc(3,sizeof(int));
    }

    mat2 = (int **) calloc(3,sizeof(int *));

    for(i = 0; i < 3; i++){
        mat2[i] = (int *) calloc(3,sizeof(int));
    }

    matSoma = (int **) calloc(3,sizeof(int *));

    for(i = 0; i < 3;  i++){
        matSoma[i] = (int *) calloc(3,sizeof(int));
    }




    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            mat1[i][j] = rand() % 100;
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            mat2[i][j] = rand() % 100;
        }
    }

    for(i = 0; i < 3;  i++){
        for(j = 0; j < 3; j++){
            matSoma[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("Matriz 1:\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3;j++){
            printf("%2d ",mat1[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz 2:\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3;j++){
            printf("%2d ",mat2[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz Soma:\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3;j++){
            printf("%3d ",matSoma[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    for(i = 0; i < 3; i++){
        free(mat1[i]);
        free(mat2[i]);
        free(matSoma[i]);
    }

    free(mat1);
    free(mat2);
    free(matSoma);

    printf("\n\n");

    system("pause");

    return 0;
}
