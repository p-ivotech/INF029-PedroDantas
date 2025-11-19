#include <stdio.h>
#include <string.h>
int contarOcorrencias(long long N, long long K);

int main() {
    long long N, K;

    printf("Digite N: ");
    scanf("%lld", &N);

    printf("Digite K: ");
    scanf("%lld", &K);

    printf("\nO numero %lld ocorre %d vezes em %lld.\n",
           K, contarOcorrencias(N, K), N);

    return 0;
}

int contarOcorrencias(long long N, long long K) {
    char strN[50], strK[50];
    int cont = 0;

    sprintf(strN, "%lld", N);
    sprintf(strK, "%lld", K);

    char *p = strN;

    while ((p = strstr(p, strK)) != NULL) {
        cont++;
        p++;
    }

    return cont;
}


