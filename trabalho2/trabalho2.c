#include <stdio.h>
#include <stdlib.h>
#include "trabalho2.h"

#define TAM 10

typedef struct {
    int *auxiliar;
    int tamanho_total;
    int qtd_elementos;
} EstruturaPrincipal;

EstruturaPrincipal vetorPrincipal[TAM];

void inicializar() {
    for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i].auxiliar = NULL;
        vetorPrincipal[i].tamanho_total = 0;
        vetorPrincipal[i].qtd_elementos = 0;
    }
}

void finalizar() {
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].auxiliar != NULL) {
            free(vetorPrincipal[i].auxiliar);
            vetorPrincipal[i].auxiliar = NULL;
        }
    }
}

int ehPosicaoValida(int posicao) {
    if (posicao < 1 || posicao > 10) {
        return POSICAO_INVALIDA;
    }
    return SUCESSO;
}

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar != NULL) return JA_TEM_ESTRUTURA_AUXILIAR;
    if (tamanho < 1) return TAMANHO_INVALIDO;
    
    vetorPrincipal[indice].auxiliar = malloc(tamanho * sizeof(int));
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESPACO_DE_MEMORIA;
    
    vetorPrincipal[indice].tamanho_total = tamanho;
    vetorPrincipal[indice].qtd_elementos = 0;
    
    return SUCESSO;
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if (vetorPrincipal[indice].qtd_elementos >= vetorPrincipal[indice].tamanho_total) return SEM_ESPACO;
    
    int posicao_livre = vetorPrincipal[indice].qtd_elementos;
    vetorPrincipal[indice].auxiliar[posicao_livre] = valor;
    vetorPrincipal[indice].qtd_elementos++;
    
    return SUCESSO;
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if (vetorPrincipal[indice].qtd_elementos == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    
    vetorPrincipal[indice].qtd_elementos--;
    
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if (vetorPrincipal[indice].qtd_elementos == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    
    int achou = 0;
    int pos_remover = -1;
    
    for (int i = 0; i < vetorPrincipal[indice].qtd_elementos; i++) {
        if (vetorPrincipal[indice].auxiliar[i] == valor) {
            pos_remover = i;
            achou = 1;
            break;
        }
    }
    
    if (achou == 0) return NUMERO_INEXISTENTE;
    
    for (int i = pos_remover; i < vetorPrincipal[indice].qtd_elementos - 1; i++) {
        vetorPrincipal[indice].auxiliar[i] = vetorPrincipal[indice].auxiliar[i+1];
    }
    
    vetorPrincipal[indice].qtd_elementos--;
    return SUCESSO;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    
    for (int i = 0; i < vetorPrincipal[indice].qtd_elementos; i++) {
        vetorAux[i] = vetorPrincipal[indice].auxiliar[i];
    }
    
    return SUCESSO;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    int retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
    if (retorno != SUCESSO) return retorno;
    
    int indice = posicao - 1;
    int qtd = vetorPrincipal[indice].qtd_elementos;
    
    for (int i = 0; i < qtd - 1; i++) {
        for (int j = 0; j < qtd - i - 1; j++) {
            if (vetorAux[j] > vetorAux[j+1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }
    return SUCESSO;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int contador_geral = 0;
    int tem_elementos = 0;
    
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].auxiliar != NULL && vetorPrincipal[i].qtd_elementos > 0) {
            tem_elementos = 1;
            for (int j = 0; j < vetorPrincipal[i].qtd_elementos; j++) {
                vetorAux[contador_geral] = vetorPrincipal[i].auxiliar[j];
                contador_geral++;
            }
        }
    }
    
    if (tem_elementos == 0) return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    
    return SUCESSO;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (retorno == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS) return retorno;
    
    int total_elementos = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].auxiliar != NULL) {
            total_elementos += vetorPrincipal[i].qtd_elementos;
        }
    }
    
    for (int i = 0; i < total_elementos - 1; i++) {
        for (int j = 0; j < total_elementos - i - 1; j++) {
            if (vetorAux[j] > vetorAux[j+1]) {
                int temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    }
    
    return SUCESSO;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    
    int tamanhoFinal = vetorPrincipal[indice].tamanho_total + novoTamanho;
    
    if (tamanhoFinal < 1) return NOVO_TAMANHO_INVALIDO;
    
    int *novo_array = realloc(vetorPrincipal[indice].auxiliar, tamanhoFinal * sizeof(int));
    if (novo_array == NULL) return SEM_ESPACO_DE_MEMORIA;
    
    vetorPrincipal[indice].auxiliar = novo_array;
    vetorPrincipal[indice].tamanho_total = tamanhoFinal;
    
    if (vetorPrincipal[indice].qtd_elementos > tamanhoFinal) {
        vetorPrincipal[indice].qtd_elementos = tamanhoFinal;
    }
    
    return SUCESSO;
}

int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) return POSICAO_INVALIDA;
    
    int indice = posicao - 1;
    
    if (vetorPrincipal[indice].auxiliar == NULL) return SEM_ESTRUTURA_AUXILIAR;
    if (vetorPrincipal[indice].qtd_elementos == 0) return ESTRUTURA_AUXILIAR_VAZIA;
    
    return vetorPrincipal[indice].qtd_elementos;
}

No *montarListaEncadeadaComCabecote() {
    No *cabecote = malloc(sizeof(No));
    cabecote->prox = NULL;
    No *atual = cabecote;
    
    int inseriu_algo = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i].auxiliar != NULL) {
            for (int j = 0; j < vetorPrincipal[i].qtd_elementos; j++) {
                No *novo = malloc(sizeof(No));
                novo->conteudo = vetorPrincipal[i].auxiliar[j];
                novo->prox = NULL;
                
                atual->prox = novo;
                atual = novo;
                inseriu_algo = 1;
            }
        }
    }
    
    if (inseriu_algo == 0) {
        free(cabecote);
        return NULL;
    }
    
    return cabecote;
}

void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    if (inicio == NULL) return;
    
    No *atual = inicio->prox;
    int i = 0;
    
    while (atual != NULL) {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

void destruirListaEncadeadaComCabecote(No **inicio) {
    if (inicio == NULL || *inicio == NULL) return;
    
    No *atual = *inicio;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    
    *inicio = NULL;
}