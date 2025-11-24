
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trabalho1.h"

int ehBissexto(int ano) {
    return (ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0));
}

int validarAno(int ano) {
    if (ano < 100) ano += 2000;
    return ano;
}

int diasNoMes(int mes, int ano) {
    if (mes < 1 || mes > 12) return -1;
    ano = validarAno(ano);
    int dias[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (mes == 2 && ehBissexto(ano)) return 29;
    return dias[mes];
}

int somar(int x, int y) { return x + y; }
int fatorial(int x) {
    int i, fat = 1;
    for (i = x; i > 1; i--) fat *= i;
    return fat;
}

int q1(char data[]) {
    DataQuebrada dq = quebraData(data);
    if (!dq.valido) return 0;
    int d = dq.iDia, m = dq.iMes, a = dq.iAno;
    if (diasNoMes(m,a) == -1) return 0;
    if (d < 1 || d > diasNoMes(m,a)) return 0;
    return 1;
}

DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos resultado = {0,0,0,0};
    DataQuebrada d1 = quebraData(datainicial);
    DataQuebrada d2 = quebraData(datafinal);

    if (!d1.valido) { resultado.retorno = 2; return resultado; }
    if (!d2.valido) { resultado.retorno = 3; return resultado; }

        if (d1.iAno > d2.iAno || (d1.iAno == d2.iAno && d1.iMes > d2.iMes) ||
            (d1.iAno == d2.iAno && d1.iMes == d2.iMes && d1.iDia > d2.iDia)) {
            resultado.retorno = 4; return resultado;
        }

        int dia = d2.iDia - d1.iDia;
        int mes = d2.iMes - d1.iMes;
        int ano = d2.iAno - d1.iAno;

            if (dia < 0) {
                int mesAnterior = d2.iMes - 1;
                int anoAnterior = d2.iAno;
                if (mesAnterior == 0) { mesAnterior = 12; anoAnterior--; }
                dia += diasNoMes(mesAnterior, anoAnterior);
                mes--;
            }

                if (mes < 0) { mes += 12; ano--; }

                resultado.qtdDias = dia;
                resultado.qtdMeses = mes;
                resultado.qtdAnos = ano;
                resultado.retorno = 1;
                return resultado;
}


int q3(char *texto, char c, int isCaseSensitive) {
    if (!texto) return 0;
    int cont = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (isCaseSensitive) {
            if (texto[i] == c) cont++;
        } else {
            if (tolower((unsigned char)texto[i]) == tolower((unsigned char)c)) cont++;
        }
    }
    return cont;
}

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    if (!strTexto || !strBusca || !posicoes) return 0;
    int tamT = strlen(strTexto);
    int tamB = strlen(strBusca);
    if (tamB == 0 || tamT < tamB) return 0;

    int encontrados = 0;
    for (int i = 0; i <= tamT - tamB; i++) {
        int ok = 1;
        for (int j = 0; j < tamB; j++) {
            if (!compararCharIgnoreCase(strTexto[i+j], strBusca[j])) { ok = 0; break; }
        }
        if (ok) {
            if (encontrados*2 + 1 < 30) {
                posicoes[encontrados*2] = i + 1; 
                posicoes[encontrados*2 + 1] = i + tamB; 
            }
            encontrados++;
        }
    }
    return encontrados;
}

int q5(int num) {
    int negativo = 0;
    if (num < 0) { negativo = 1; num = -num; }
    int inv = 0;
    if (num == 0) return 0;
    while (num > 0) {
        inv = inv * 10 + (num % 10);
        num /= 10;
    }
    return negativo ? -inv : inv;
}

int q6(int numerobase, int numerobusca) {
    if (numerobase == 0 && numerobusca == 0) return 1;
    if (numerobusca == 0) {
        int cont = 0;
        if (numerobase == 0) return 1;
        while (numerobase != 0) {
            if (abs(numerobase % 10) == 0) cont++;
            numerobase /= 10;
        }
        return cont;
    }

    int qtdOcorrencias = 0;
    int divisor = 1;
    int temp = abs(numerobusca);
    while (temp > 0) { divisor *= 10; temp /= 10; }

    int base = abs(numerobase);
    while (base > 0) {
        if (base % divisor == abs(numerobusca)) qtdOcorrencias++;
        base /= 10;
    }
    return qtdOcorrencias;
}

int q7(char matriz[8][10], char palavra[5]) {
    int tamanho = strlen(palavra);
    if (tamanho == 0) return 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            
            if (j + tamanho <= 10) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i][j+k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (j - tamanho + 1 >= 0) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i][j-k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i + tamanho <= 8) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i+k][j] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i - tamanho + 1 >= 0) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i-k][j] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i + tamanho <= 8 && j + tamanho <= 10) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i+k][j+k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i - tamanho + 1 >= 0 && j - tamanho + 1 >= 0) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i-k][j-k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i - tamanho + 1 >= 0 && j + tamanho <= 10) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i-k][j+k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
            
            if (i + tamanho <= 8 && j - tamanho + 1 >= 0) {
                int ok = 1;
                for (int k = 0; k < tamanho; k++) if (matriz[i+k][j-k] != palavra[k]) { ok = 0; break; }
                if (ok) return 1;
            }
        }
    }
    return 0;
}

DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    dq.valido = 0;
    dq.iDia = dq.iMes = dq.iAno = 0;
    if (!data) return dq;

    int len = strlen(data);
    if (len < 4) return dq;

    char sDia[5] = {0}, sMes[5] = {0}, sAno[6] = {0};
    int p = 0, si = 0;

    while (data[p] != '\0' && data[p] != '/') {
        if (si < 4) sDia[si++] = data[p];
        p++;
    }
    if (data[p] != '/') return dq; 
    sDia[si] = '\0';
    p++; 

 
    si = 0;
    while (data[p] != '\0' && data[p] != '/') {
        if (si < 4) sMes[si++] = data[p];
        p++;
    }
    if (data[p] != '/') return dq;
    sMes[si] = '\0';
    p++;

    
    si = 0;
    while (data[p] != '\0') {
        if (si < 5) sAno[si++] = data[p];
        p++;
    }
    sAno[si] = '\0';

    
    int lenDia = strlen(sDia), lenMes = strlen(sMes), lenAno = strlen(sAno);
    if (!((lenDia == 1 || lenDia == 2) && (lenMes == 1 || lenMes == 2) && (lenAno == 2 || lenAno == 4))) return dq;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
    dq.valido = 1;
    return dq;
}

