#include <stdio.h>
#include <string.h>
#include<windows.h>
#include "pilha.h"


int main() {
    char expressao[MAX];
    printf("Digite a sequencia de delimitadores: ");
    fgets(expressao, MAX, stdin);

    Pilha *p = criar();

    int i;
    int erro = 0;

    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            push(p, expressao[i]);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            int topoPilha;

            if (pilhaVazia(p)) {
                erro = 1;
                break;
            } else {
                pop(p, &topoPilha);
                if ((expressao[i] == ')' && topoPilha != '(') || (expressao[i] == ']' && topoPilha != '[') || (expressao[i] == '}' && topoPilha != '{')) {
                    erro = 1;
                    break;
                }
            }
        }
    }

    if (!pilhaVazia(p)) {
        erro = 1;
    }

    if (erro) {
        printf("A sequencia de delimitadores esta incorreta.\n");
    } else {
        printf("A sequencia de delimitadores esta correta.\n");
    }

    limpar(p);

    system("pause");

    return 0;
}
