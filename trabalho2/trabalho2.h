#ifndef ITEM_H
#define ITEM_H

#define TAM_PADRAO 100
#define TAM_VP 10

typedef struct item {
    int *p;
    int TAM;
    int qtd;
} Item;

void inicializarItens(Item vP[], int tam);
int alocarItem(Item *it);
void liberarItens(Item vP[], int tam);
int inserirValor(Item *it, int valor);
int excluirElemento(Item *it, int valor);
void ordenarVetor(int *v, int n);
void listarOrdenadoPorItem(Item vP[], int tam);
void listarTodosOrdenados(Item vP[], int tam);

#endif
