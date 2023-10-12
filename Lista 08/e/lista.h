typedef struct aeroporto{
    char nome[30];
    char sigla[4];
}Aero;

typedef struct lista Lista;

Lista *criar();

void limpar(Lista *l);

float precoTrecho(Lista *l, float taxa);

int inserirFim(Lista *l, Aero p);
int inserirTrecho(Lista *l, Aero origem, Aero destino, float distancia);

