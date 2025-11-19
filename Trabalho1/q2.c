#include <stdio.h>
#include <time.h>

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

void calcularIdade(int dN, int mN, int aN,  
                   int dA, int mA, int aA,
                   int *anos, int *meses, int *dias)
{
    aN = validarAno(aN);

    *anos = aA - aN;
    *meses = mA - mN;
    *dias = dA - dN;

        if (*dias < 0) {
            mA--;
            *meses = mA - mN;
            *dias += diasNoMes((mA == 0 ? 12 : mA), (mA == 0 ? aA - 1 : aA));
        }

            if (*meses < 0) {
                *meses += 12;
                (*anos)--;
            }
}

int main() {
    char entrada[20];
    int dN, mN, aN;

    printf("Digite sua data de nascimento (d/m/aa ou d/m/aaaa): ");
    scanf("%19s", entrada);

        if (!lerData(entrada, &dN, &mN, &aN) || !validarData(dN, mN, aN)) {
            printf("Data invalida!\n");
            return 0;
        }
    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);

    int dA = hoje.tm_mday;
    int mA = hoje.tm_mon + 1;
    int aA = hoje.tm_year + 1900;

    int anos, meses, dias;
    calcularIdade(dN, mN, aN, dA, mA, aA, &anos, &meses, &dias);

    printf("\nIdade: %d anos, %d meses e %d dias.\n", anos, meses, dias);

    return 0;
}
