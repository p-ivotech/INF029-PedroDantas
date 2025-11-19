#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char texto[251];
    char letra;
    int contador = 0;

    printf("Digite um texto (até 250 caracteres):\n");
    fgets(texto, 251, stdin);

    printf("Digite uma letra para buscar: ");
    scanf(" %c", &letra);

    letra = normalizar(letra);

        for (int i = 0; texto[i] != '\0'; i++) {
            if (normalizar(texto[i]) == letra) {
                contador++;
            }
        }

    printf("\nA letra '%c' aparece %d vezes no texto.\n", letra, contador);

return 0;

}
