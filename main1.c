#include<stdio.h>
#include<stdlib.h>

float misterio2( float num){
    long i;
    float x2,y;
    const float threehalfs = 1.5F;
    x2 = num * 0.5F;
    y=num;
    i=*(long*)&y;
    i=0x5f3759df-(i>>1);
    y=*(float*)&i;
    y=y*(threehalfs-(x2*y*y));
    return y;

}

float misterio3(int **a, int **b, int **c, int n, int m){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i][j]=0;
            for(k=0;k<n;k++){
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    return 0;

}

short main(){
    float num;
    printf("Digite um numero: ");
    unsigned long int numero =  213123123123123;
    printf("%lu\n", numero);
    scanf("%f", &num);
    printf("Resultado: %f\n", misterio2(num));
    int **a, **b, **c, n, m;
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &n, &m);
    a = (int**)malloc(n*sizeof(int*));
    b = (int**)malloc(n*sizeof(int*));
    c = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        a[i] = (int*)malloc(m*sizeof(int));
        b[i] = (int*)malloc(m*sizeof(int));
        c[i] = (int*)malloc(m*sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Digite o elemento a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Digite o elemento b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    misterio3(a,b,c,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}