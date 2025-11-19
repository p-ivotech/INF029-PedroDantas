#include <stdio.h>
#include <string.h>

#define MAX 50

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

int main() {
    
}
