#define MAX 100

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

int inserirInicio(Lista *l,struct aluno it);
int inserirFim(Lista *l,struct aluno it);
int inserirPos(Lista *l, Aluno it, int pos);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removePosicao(Lista *l, int pos);

int buscarItemChave(Lista *l,int chave,Aluno *retorno);
int buscarPosicao(Lista *l,int posicao,Aluno *retorno);

int listaVazia(Lista *l);
int listaCheia(Lista *l);

int tamanho(Lista *l);

void mostrar(Lista *l);

int maiorNota(Lista *l, Aluno *retorno);

int trocarPosicoes(Lista *l, int pos1, int pos2);

int comparar(Lista *l, Lista *r);