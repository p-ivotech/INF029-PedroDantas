#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

void inicializarItens(Item vP[], int tam) {
    for (int i = 0; i < tam; i++) {
        vP[i].p = NULL;
        vP[i].TAM = TAM_PADRAO;
        vP[i].qtd = 0;
    }
}

int alocarItem(Item *it) {
    if (it->p != NULL)
        return 1;

    it->p = malloc(it->TAM * sizeof(int));
    return it->p != NULL;
}

void liberarItens(Item vP[], int tam) {
    for (int i = 0; i < tam; i++) {
        free(vP[i].p);
        vP[i].p = NULL;
    }
}


int inserirValor(Item *it, int valor) {
    if (it->p == NULL || it->qtd >= it->TAM)
        return 0;

    it->p[it->qtd++] = valor;
    return 1;
}

int excluirElemento(Item *it, int valor) {
    if (it->p == NULL || it->qtd == 0)
        return 0;

    for (int i = 0; i < it->qtd; i++) {
        if (it->p[i] == valor) {
            for (int j = i; j < it->qtd - 1; j++) {
                it->p[j] = it->p[j + 1];
            }
            it->qtd--;
            return 1;
        }
    }
    return 0;
}

void ordenarVetor(int *v, int n) {
    int chave, j;

    for (int i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void listarOrdenadoPorItem(Item vP[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (vP[i].p != NULL && vP[i].qtd > 0) {

            ordenarVetor(vP[i].p, vP[i].qtd);

            printf("\nPosição %d (ordenado): ", i);
            for (int j = 0; j < vP[i].qtd; j++) {
                printf("%d ", vP[i].p[j]);
            }
        }
    }
}

void listarTodosOrdenados(Item vP[], int tam) {
    int total = 0;

    for (int i = 0; i < tam; i++)
        total += vP[i].qtd;

    if (total == 0) {
        printf("\nNenhum elemento cadastrado.\n");
        return;
    }

    int *aux = malloc(total * sizeof(int));
    int k = 0;

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < vP[i].qtd; j++) {
            aux[k++] = vP[i].p[j];
        }
    }

    ordenarVetor(aux, total);

    printf("\nTodos os números ordenados:\n");
    for (int i = 0; i < total; i++) {
        printf("%d ", aux[i]);
    }

    free(aux);
}

void menu() {
    printf("\n1 - Inserir valor");
    printf("\n2 - Listar ordenado por posição");
    printf("\n3 - Listar todos ordenados");
    printf("\n4 - Excluir elemento");
    printf("\n0 - Sair");
    printf("\nEscolha: ");
}

int main() {
    Item vP[TAM_VP];
    int opcao, pos, valor;

    inicializarItens(vP, TAM_VP);

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Posição (0 a 9): ");
            scanf("%d", &pos);

            if (pos < 0 || pos >= TAM_VP) {
                printf("Posição inválida\n");
                break;
            }

            if (!alocarItem(&vP[pos])) {
                printf("Erro de memória\n");
                break;
            }

            printf("Valor: ");
            scanf("%d", &valor);

            if (!inserirValor(&vP[pos], valor))
                printf("Vetor cheio\n");
            break;

        case 2:
            listarOrdenadoPorItem(vP, TAM_VP);
            break;

        case 3:
            listarTodosOrdenados(vP, TAM_VP);
            break;

        case 4:
            printf("Posição (0 a 9): ");
            scanf("%d", &pos);

            printf("Valor a excluir: ");
            scanf("%d", &valor);

            if (pos < 0 || pos >= TAM_VP ||
                !excluirElemento(&vP[pos], valor))
                printf("Elemento não encontrado\n");
            else
                printf("Elemento removido\n");
            break;

        case 0:
            break;

        default:
            printf("Opção inválida\n");
        }

    } while (opcao != 0);

    liberarItens(vP, TAM_VP);
    return 0;
}
