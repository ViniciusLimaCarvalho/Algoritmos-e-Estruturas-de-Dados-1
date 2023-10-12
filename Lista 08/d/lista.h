#define MAX 100

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

int inserirInicio(Lista *l,Aluno it);
int inserirFim(Lista *l,Aluno it);
int inserirPosicao(Lista *l,Aluno it,int pos);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,Aluno it);
int removeNprimeiros(Lista *l, int *n);

int buscarItemChave(Lista *l,int chave,Aluno *retorno);
int buscarPosicao(Lista *l,int posicao,Aluno *it);
int contemItem(Lista *l, Aluno *it);
int maiorNota(Lista *l,Aluno *retorno);

int listaVazia(Lista *l);
int listaCheia(Lista *l);

Lista *concat(Lista *l,Lista *r);

void mostrar(Lista *l);