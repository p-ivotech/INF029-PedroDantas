// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Ivo Alves da Silva Dantas
//  email: pedroivodantas@gmail.com 
//  Matrícula: 20251160046
//  Semestre: 2º semestre

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

/*
1) Crie uma pasta com o seguinte nome: NomeSobrenomeAluno-MatriculaAluno
T1. Para o exemplo de João seria: JoaoSilva-2017902345-T1. Todos os arquivos
 do trabalho devem estar dentro dessa pasta. Ao final, compacte ela e envie por
 e-mail o arquivo compactado anexado.
*/

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
/*
2) Faça umprograma emque o usuário informa a sua data de aniversário, o
 programadeve: a) Verificar se a data é válida (usar função da questão anterior);
*/
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

/* 3 - Faça um programa que o usuário informa umtextode até250, e uma letra. O
 programa deve informar quantas vezes essa letra aparece no texto. Desconsidere
 acentosnasvogais.Ouseja,um'á'éiguala'a'.
 */
int main() {
    char texto[250];
    char letra;
    int contador = 0;

    printf("Digite um texto (até 250 caracteres):\n");
    fgets(texto, 250, stdin);

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

/*
4 - Faça um programa em que o usuário informa um texto de até 250,e uma palavra.
 O programa deve informar a posição inicial e fim de todas as ocorrências da palavra no
 texto.
*/

int main() {
    char texto[250];
    char palavra[50];
    int tamTexto, tamPalavra;

    printf("Digite um texto (até 250 caracteres):\n");
    fgets(texto, 250, stdin);
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite a palavra a procurar (até 50 caracteres):\n");
    fgets(palavra, 50, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    tamTexto = strlen(texto);
    tamPalavra = strlen(palavra);

    int encontrou = 0;

    printf("Ocorrências encontradas:\n");

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

/* Faça uma função que permita inverter um número inteiro N. Ex:
 456– 654
 5430– 345
 100– 1 
 */

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

/*
6 - Escreva uma função que determine quantas vezes um número K (de qualquer
 quantidade de dígitos) ocorre em um número natural N.
*/

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

/*
 7- Escreva uma função implemente o jogo caça palavras. Ela deve receber uma
 matriz de caracteres onde será feita a busca, e uma string a ser buscada. A função deve
 procurar a string em todas os sentidos possíveis: horizontal para frente e para trás,
 vertical para cima e para baixo, diagonal em todos os sentidos possíveis
*/



#define MAX 50

//direções
int dx[8] = { 0,  0,  1, -1,  1, -1,  1, -1 };
int dy[8] = { 1, -1,  0,  0,  1,  1, -1, -1 };

void cacaPalavras(char mat[MAX][MAX], int L, int C, char *palavra) {
    int encontrou = 0;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == palavra[0]) {
                for (int d = 0; d < 8; d++) {
                    if (buscaDirecao(mat, L, C, palavra, i, j, d)) {
                        encontrou = 1;
                        int fimX = i + dx[d] * (strlen(palavra) - 1);
                        int fimY = j + dy[d] * (strlen(palavra) - 1);
                        printf("Encontrado: (%d,%d) até (%d,%d)\n", i, j, fimX, fimY);
                    }
                }
            }
        }
    }

    if (!encontrou) {
        printf("Palavra nao encontrada.\n");
    }
}

int buscaDirecao(char mat[MAX][MAX], int L, int C,
                 char *palavra, int x, int y, int dir) 
{
    int tam = strlen(palavra);

    for (int i = 0; i < tam; i++) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;

            if (nx < 0 || nx >= L || ny < 0 || ny >= C)
                return 0;
                if (mat[nx][ny] != palavra[i])
                    return 0;
    }

    return 1;
}

int main() {
    
}