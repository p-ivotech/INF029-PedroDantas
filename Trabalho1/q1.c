#include <stdio.h>

int Bissexto(int ano) {
    return (ano % 400 == 0) ||
           (ano % 4 == 0 && ano % 100 != 0);
}

int validarAno(int ano) {
    if (ano < 100) {  
        ano += 2000;
    }
    return ano;
}

int diasNoMes(int mes, int ano) {
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    ano = validarAno(ano);

        if (Bissexto(ano))
            diasMes[2] = 29;

            if (mes < 1 || mes > 12)
                return -1;

    return diasMes[mes];
}

int validarData(int dia, int mes, int ano) {

    ano = validarAno(ano);

    int maxDias = diasNoMes(mes, ano);

    if (maxDias == -1)
        return 0; 

    if (dia < 1 || dia > maxDias)
        return 0;

    return 1; 
}


int lerData(const char *entrada, int *dia, int *mes, int *ano) {
    return sscanf(entrada, "%d/%d/%d", dia, mes, ano) == 3;
}

int main() {
    char entrada[20];
    int d, m, a;

    printf("Digite uma data (d/m/aa ou d/m/aaaa): ");
    scanf("%19s", entrada);

        if (!lerData(entrada, &d, &m, &a)) {
            printf("Formato invalido!\n");
            return 0;
        }

            if (validarData(d, m, a)) {
                printf("Data valida.\n");
            } else {
                printf("Data invalida.\n");
            }

    return 0;
}
