typedef struct Matriz matriz;

matriz *criar (int lin, int col);

void destruir(matriz *m);

float elemento (int lin, int col, matriz *m);

void mostrar (matriz *m);

matriz *soma (matriz *m, matriz *n);

void preenche (matriz *m, float min, float max);

int linha (matriz *m);

int coluna(matriz *m);
