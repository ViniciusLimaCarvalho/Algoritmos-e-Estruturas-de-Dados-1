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
int inserirPosicao(Lista *l,struct aluno it,int pos);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int pos);
int removerItem(Lista *l,int it);
void removerElementoPosicaoCentral(Lista *l);

int buscarItem(Lista *l, int chave, Aluno *it);
int buscarPosicao(Lista *l,int posicao,Aluno *retorno);

int listaVazia(Lista *l);
int listaCheia(Lista *l);

int tamanho(Lista *l);

void mostrar(Lista *l);

Lista *intersecao(Lista *L1, Lista *L2);