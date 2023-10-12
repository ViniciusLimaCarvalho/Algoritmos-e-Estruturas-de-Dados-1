#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include<windows.h>

int main() {
    char str[100];
    bool isRepeated[256] = {false}; // Array para verificar se o caractere foi encontrado anteriormente

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);

    if (str[length - 1] == '\n') {
        str[length - 1] = '\0'; // Removendo o caractere de nova linha
    }

    int i;
    bool hasRepeated = false;

    for (i = 0; str[i] != '\0'; i++) {
        char currentChar = str[i];

        if (isalpha(currentChar) && isRepeated[currentChar]) {
            printf("A letra '%c' se repete na string.\n", currentChar);
            hasRepeated = true;
        }

        isRepeated[currentChar] = true;
    }

    if (!hasRepeated) {
        printf("Nenhuma letra se repete na string.\n");
    }

    system("pause");

    return 0;
}
