#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
    char CPF[12];
    char EstadoCivil;
    int nFilhos;
    char *nomeFilho[50];
};

typedef struct cliente cliente;

int main() {
    cliente *c;
    int num, count = 0, i, j, escolha, remocao;

    printf("Insira a quantidade de clientes: ");
    scanf("%d", &num);

    c = (cliente *)malloc(num * sizeof(cliente));

    menu:
    do {
        printf("Escolha uma das opcoes abaixo:\n\n");
        printf("(1).Inserir cliente no vetor\n");
        printf("(2).Remover cliente do vetor\n");
        printf("(3).Listar CPFs\n");
        printf("(4).Sair\n");
        scanf("%d", &escolha);
    } while (escolha > 4 || escolha < 1);

    if (escolha == 1) {
        printf("Insira o CPF do %do. cliente: ", count + 1);
        setbuf(stdin,NULL);
        fgets(c[count].CPF,11,stdin);
        setbuf(stdin,NULL);

        printf("Insira Estado Civil do %do. cliente (V para viuvo(a), S para solteiro(a), C para casado(a), D para divorciado(a)): ", count + 1);
        scanf("%c", &(c + count)->EstadoCivil);

        printf("Insira a quantidade de filhos do %do. cliente: ", count + 1);
        scanf("%d", &(c + count)->nFilhos);

        for (j = 0; j < c[count].nFilhos; j++) {
            c[count].nomeFilho[j] = (char *)malloc(50 * sizeof(char));  // Alocação para o nome do filho
            printf("Insira o nome do %do. filho: ", j + 1);
            setbuf(stdin, NULL);
            fgets(c[count].nomeFilho[j], 50, stdin);
        }

        count++;

        goto menu;
    }

    else if (escolha == 2) {
        printf("Qual o cliente a ser removido? ");
        scanf("%d", &remocao);

        remocao--;

        if (remocao >= 0 && remocao < count) {
            free(c[remocao].nomeFilho);  // Liberar memória alocada para os nomes dos filhos

            for (i = remocao; i < count - 1; i++) {
                c[i] = c[i + 1];  // Deslocar elementos após o cliente removido
            }

            count--;  // Decrementar o contador de clientes

            goto menu;
        } else {
            printf("Cliente invalido!\n");
        }
    }

    else if(escolha == 3){
        for(i = 0; i < count; i++){
            printf("%d. %s\n",i+1,c[i].CPF);
        }
        goto menu;
    }

    else{
        
        printf("\n\n");
    
        system("pause");

        return 0;
    }

}
