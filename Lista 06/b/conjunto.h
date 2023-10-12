typedef struct Conjunto conjunto;

conjunto *criar(int tam);

void insere(conjunto *c, int posicao);

void removeElemento(conjunto *c, int posicao);

conjunto *uniao(conjunto *c, conjunto *d);

conjunto *interseccao(conjunto *c, conjunto *d);

conjunto *diferenca(conjunto *c, conjunto *d);