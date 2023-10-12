#define TAM 2000

typedef struct histo{
    char ch;
    int ocorr;
} Histo;

typedef struct lista Lista;

Lista* criar();

void limpar(Lista *l);

int inserirString(Lista *l, char *str);

int tamanho(Lista *l);

void mostrar(Lista *l);