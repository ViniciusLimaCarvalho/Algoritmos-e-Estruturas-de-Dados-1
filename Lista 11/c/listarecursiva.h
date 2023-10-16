typedef struct no* lista;

lista *Criar();

int inserirInicio(lista *l, int it);
int inserirFim(lista *l, int it);
int inserirPosicao(lista *l, int it, int pos);

int removerInicio(lista *l);
int removerFim(lista *l);
int removerPosicao(lista *l);
int removerItem(lista *l);

int listaVazia(lista *l);
int buscarItem(lista *l, int it);
int buscarPosicao(lista *l, int pos, int *it);

void mostrar(lista *l);
int tamanho(lista *l);

int ultimoElemento (lista *l, int *valor);
int somaElementos(lista *l);