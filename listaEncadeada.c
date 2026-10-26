#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct lista{
    int valor;
    struct lista *proximo;
}Lista;


void criarLista(Lista *novo){
    for(int i = 0; i < TAM;i++){
        novo->proximo = NULL;
        novo[i].valor = 0;
    }
}

Lista *adicionarInicio(Lista *head,int valor){
    Lista *novoAluno = (Lista*)malloc(sizeof(Lista));
    novoAluno->proximo = head;
    novoAluno->valor = valor;
    return novoAluno;
}

int main(){
    Lista *aluno = (Lista*)malloc(sizeof(Lista));
    criarLista(aluno);
    aluno = adicionarInicio(aluno,56);
    aluno = adicionarInicio(aluno,99);

    for(int i = 0; i<2;i++){
        printf("Posicao %d - Endereco: %p Valor: %d\n",i+1,aluno[i].proximo,aluno[i].valor);
    }

}