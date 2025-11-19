#include <stdio.h>
#include <string.h>
#include <ctype.h>

char tolowerBR(char c) {
    return tolower((unsigned char)c);
}

int comparaChar(char a, char b) {
    return tolowerBR(a) == tolowerBR(b);
}

int main() {
    char texto[250];
    char palavra[50];
    int tamTexto, tamPalavra;

    printf("Digite um texto (até 250 caracteres):\n");
    fgets(texto, 251, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite a palavra a procurar (até 50 caracteres):\n");
    fgets(palavra, 51, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    tamTexto = strlen(texto);
    tamPalavra = strlen(palavra);

    int encontrou = 0;

    printf("\nOcorrências encontradas:\n");

    for (int i = 0; i <= tamTexto - tamPalavra; i++) {
        int igual = 1;

        for (int j = 0; j < tamPalavra; j++) {
            if (!comparaChar(texto[i + j], palavra[j])) {
                igual = 0;
                break;
            }
        }

        if (igual) {
            printf("Início: %d | Fim: %d\n", i, i + tamPalavra - 1);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma ocorrência encontrada.\n");
    }

    return 0;
}
