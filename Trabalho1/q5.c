#include <stdio.h>

int inverterNumero(int n) {
    int inverso = 0;

    while (n > 0) {
        inverso = inverso * 10 + (n % 10);
        n /= 10;
    }

    return inverso;
}

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    printf("Numero invertido: %d\n", inverterNumero(n));

    return 0;
}
