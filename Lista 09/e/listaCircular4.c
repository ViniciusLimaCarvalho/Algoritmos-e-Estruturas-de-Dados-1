#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"

typedef struct no {
    Aluno valor;
    struct no *prox;
} No;

typedef struct lista {
    No *final;
} ListaCircular;

Lista *criar() {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if (l == NULL) {
        printf("Erro: não foi possível alocar memória para a lista.\n");
        return NULL;
    }
    l->final = NULL;
    return l;
}

void limpar(Lista *l) {
    if (l == NULL) {
        printf("Erro: lista é nula.\n");
        return;
    }

    while (listaVazia(l) != 0) {
        removerInicio(l);
    }

    free(l);
}

int inserirInicio(Lista *l, Aluno it) {
    if (l == NULL) {
        printf("Erro: lista é nula.\n");
        return 2;
    }

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro: não foi possível alocar memória para o nó.\n");
        return 2;
    }

    no->valor = it;

    if (listaVazia(l) == 0) {
        l->final = no;
        no->prox = no;
    } else {
        no->prox = l->final->prox;
        l->final->prox = no;
    }

    return 0;
}

int inserirFim(Lista *l, Aluno it) {
    if (l == NULL) {
        printf("Erro: lista é nula.\n");
        return 2;
    }

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro: não foi possível alocar memória para o nó.\n");
        return 2;
    }

    no->valor = it;

    if (listaVazia(l) == 0) {
        l->final = no;
        no->prox = no;
    } else {
        No *temp = l->final;
        while (temp->prox != l->final)
            temp = temp->prox;

        temp->prox = no;
        no->prox = l->final;
    }

    return 0;
}

int inserirPosicao(Lista *l, struct aluno it, int pos) {
    if (l == NULL) {
        printf("Erro: lista é nula.\n");
        return 2;
    }

    if (pos < 0) {
        printf("Erro: posição inválida.\n");
        return 2;
    }

    int tamanhoLista = tamanho(l);

    if (pos > tamanhoLista) {
        printf("Erro: posição maior que o tamanho da lista.\n");
        return 2;
    }

    if (pos == 0) {
        return inserirInicio(l, it);
    } else if (pos == tamanhoLista) {
        return inserirFim(l, it);
    }

    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: não foi possível alocar memória para o nó.\n");
        return 2;
    }

    novoNo->valor = it;

    No *anterior = NULL;
    No *atual = l->final->prox;

    while (pos > 0) {
        anterior = atual;
        atual = atual->prox;
        pos--;
    }

    anterior->prox = novoNo;
    novoNo->prox = atual;

    return 0;
}


int removerInicio(Lista *l) {
    if (l == NULL) {
        printf("Erro: lista é nula.\n");
        return 2;
    }

    if (listaVazia(l) == 0) {
        printf("Erro: lista está vazia.\n");
        return 1;
    }

    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }

    No *no = l->final;
    while (no->prox != l->final) {
        no = no->prox;
    }

    No *temp = l->final;
    no->prox = temp->prox;
    l->final = temp->prox;
    free(temp);

    return 0;
}

int removerFim(Lista *l) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *anterior = NULL, *no = l->final;
    while (no->prox != l->final) {
        anterior = no;
        no = no->prox;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int removerPosicao(Lista *l,int pos) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    if (l->final->prox == l->final) {
        free(l->final);
        l->final = NULL;
        return 0;
    }
    No *anterior = NULL, *no = l->final;
    while ((no->prox != l->final)&&(pos > 0)) {
        anterior = no;
        no = no->prox;
        pos--;
    }
    anterior->prox = no->prox;
    free(no);
    return 0;
}

int removerItem(Lista *l, int it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;

    No *anterior = NULL;
    No *atual = l->final->prox;

    // Percorre a lista para encontrar o nó com a chave especificada
    int encontrado = 0;
    do {
        if ((atual->valor).mat == it) {
            encontrado = 1;
            break;
        }

        anterior = atual;
        atual = atual->prox;
    } while (atual != l->final);

    if (!encontrado) {
        printf("Erro: Item não encontrado.\n");
        return 1;  // Item não encontrado
    }

    // Se o item a ser removido está no início da lista
    if (atual == l->final->prox) {
        return removerInicio(l);
    }

    // Se o item a ser removido está no fim da lista
    if (atual == l->final) {
        return removerFim(l);
    }

    // Se o item a ser removido está no meio da lista
    anterior->prox = atual->prox;
    free(atual);
    return 0;
}

void removerElementoPosicaoCentral(Lista *l) {
    if (l == NULL) {
        printf("Erro: Lista é nula.\n");
        return;
    }

    int tamanhoLista = tamanho(l);

    if (tamanhoLista == 0) {
        printf("Erro: Lista está vazia.\n");
        return;
    }

    int posicaoCentral = tamanhoLista / 2;

    // Remover o elemento na posição central
    removerPosicao(l, posicaoCentral);
}



int buscarItem(Lista *l, int chave, Aluno *it) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    No *no = l->final;
    while ((no->prox != l->final)&&((no->valor).mat != chave))
        no = no->prox;
    if ((no->valor).mat != chave )
        return 1;
    else {
        *it = no->valor;
        return 0;
    }
}

int buscarPosicao(Lista *l, int posicao, Aluno *retorno) {
    if (l == NULL) return 2;
    if (listaVazia(l) == 0) return 1;
    int tamanhoLista = tamanho(l);

    if (posicao < 0 || posicao >= tamanhoLista) {
        printf("Erro: Posição inválida.\n");
        return 2;
    }

    No *atual = l->final->prox;
    int i = 0;

    // Percorre a lista até a posição desejada
    while (i < posicao) {
        atual = atual->prox;
        i++;
    }

    *retorno = atual->valor;
    return 0;
}


int listaVazia(Lista *l) {
    if (l == NULL) return 2;
    if (l->final == NULL)
    return 0;
    else
    return 1;
}

int listaCheia(Lista *l) {
    return 1;
}

int tamanho(Lista *l) {
    if (l == NULL) return -1;
    if (listaVazia(l) == 0) return 0;
    No *noLista = l->final;
    int cont = 0;
    do {
        cont++;
        noLista = noLista->prox;
    } while (noLista != l->final);
    return cont;
}

void mostrar(Lista *l) {
    if (l != NULL) {
        printf("[");
        if (listaVazia(l) != 0) {
            No *noLista = l->final;
            do {
                printf(" {%d, ",noLista->valor.mat);
                printf("%s, ",noLista->valor.nome);
                printf("%.2f} ",noLista->valor.n1);
                noLista = noLista->prox;
            } while (noLista != l->final);
        }
        printf("]\n");
    }
}

Lista *intersecao(Lista *L1, Lista *L2) {
    if (L1 == NULL || L2 == NULL) {
        printf("Erro: Pelo menos uma das listas é nula.\n");
        return NULL;
    }

    Lista *listaIntersecao = criar();

    if (listaIntersecao == NULL) {
        printf("Erro: Não foi possível criar a lista de interseção.\n");
        return NULL;
    }

    No *atualL1 = L1->final->prox;
    No *atualL2 = L2->final->prox;

    // Percorre L1 e L2 e adiciona elementos em comum na lista de interseção
    while (atualL1 != L1->final->prox) {
        while (atualL2 != L2->final->prox) {
            if ((atualL1->valor).mat == (atualL2->valor).mat) {
                // Adiciona à lista de interseção
                Aluno alunoIntersecao = atualL1->valor;
                inserirFim(listaIntersecao, alunoIntersecao);
            }
            atualL2 = atualL2->prox;
        }
        atualL2 = L2->final->prox;
        atualL1 = atualL1->prox;
    }

    return listaIntersecao;
}

int contaOcorrencias(Lista *l, Aluno it) {
    if (l == NULL) return 0;
    if (listaVazia(l) == 0) return 0;

    No *atual = l->final->prox;
    int ocorrencias = 0;

    do {
        if (memcmp(&atual->valor, &it, sizeof(Aluno)) == 0)
            ocorrencias++;

        atual = atual->prox;
    } while (atual != l->final->prox);

    return ocorrencias;
}

int inserirNoFinalSemRepeticao(Lista *l, Aluno it) {
    if (l == NULL) {
        printf("Erro: Lista é nula.\n");
        return 2;
    }

    if (contaOcorrencias(l, it) > 0) {
        printf("O elemento já existe na lista. Inserção não realizada.\n");
        return 1;
    }

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL) {
        printf("Erro: Não foi possível alocar memória para o nó.\n");
        return 2;
    }

    no->valor = it;

    if (listaVazia(l) == 0) {
        l->final = no;
        no->prox = no;
    } else {
        no->prox = l->final->prox;
        l->final->prox = no;
        l->final = no;
    }

    return 0;
}
