
typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar(int tam);

void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it, int tam);
int inserirFim(Lista *l,Aluno it, int tam);
int inserirPosicao(Lista *l,Aluno it,int pos, int tam);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,Aluno it);

int buscarItemChave(Lista *l,int chave,Aluno *retorno);
int buscarPosicao(Lista *l,int posicao,Aluno *retorno);
int contemItem(Lista *l, Aluno it);
int contaItem(Lista *l, char *nome);

int listaVazia(Lista *l);
int listaCheia(Lista *l, int tam);

int tamanho(Lista *l);

void mostrar(Lista *l);
void reversa(Lista *l, Lista *r, int tam);