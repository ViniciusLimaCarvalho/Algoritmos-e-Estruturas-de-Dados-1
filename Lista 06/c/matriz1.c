#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matriz.h"

typedef struct Matriz{
    float **mat;
    int lin;
    int col;
}matriz;

matriz *criar (int lin, int col){
    int i;
    matriz *m = (matriz *) calloc( 1,sizeof(matriz));

    m->lin = lin;
    m->col = col;

    m->mat = (float **) calloc (lin,sizeof(float));

    for(i = 0; i < lin; i++){
        m->mat[i] = (float *) calloc (col,sizeof(float));
    }

    return m;
}

void destruir(matriz *m){
    int i;

    for(i = 0; i < m->lin; i++){
        free(m->mat[i]);
    }

    free(m->mat);
    free(m);

    m = NULL;
}

float elemento (int lin, int col, matriz *m){
    return m->mat[lin][col];
}

void mostrar (matriz *m){
    int i, j;

    for(i = 0; i < m->lin; i++){
        for(j = 0; j < m-> col; j++){
            printf("%.1f ",m->mat[i][j]);
        }
        printf("\n");
    }
}

matriz *soma (matriz *m, matriz *n){
    int i, j;

    matriz *s = criar(m->lin,m->col);

    for(i = 0; i < m->lin; i++){
        for(j = 0; j < m->col; j++){
            s->mat[i][j] = m->mat[i][j] + n->mat[i][j];
        }
    }

    return s;
}

void preenche(matriz *m, float min, float max){
    srand(time(NULL));
    int i, j;
    float range = max - min;

    for(i = 0; i < m->lin; i++){
        for(j = 0; j < m->col; j++){
            int random_int = rand(); 
            float normalized_random = (float)random_int / RAND_MAX; 
            m->mat[i][j] = min + normalized_random * range; 
        }
    }
}




int linha (matriz *m){
    return m->lin;
}

int coluna(matriz *m){
    return m->col;
}
