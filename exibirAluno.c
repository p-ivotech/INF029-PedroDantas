#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    char nome[50];
    int idade;
    float nota;
}Aluno;

void cadastrarAluno(Aluno *estudante);
void exibirAluno(Aluno *estudante);

int main(){
    Aluno *estudante = malloc(sizeof(Aluno));
    cadastrarAluno(estudante);
    exibirAluno(estudante);
    free(estudante);
}

void cadastrarAluno(Aluno *estudante){
        printf("Digite um nome: ");
        fgets(estudante->nome,50,stdin);
        printf("\nDigite a idade: ");
        scanf(" %d",&estudante->idade);
        printf("\nDigite a nota: ");
        scanf("%f",&estudante->nota);

}

void exibirAluno(Aluno *estudante){
        printf("Nome: %s",estudante->nome);
        printf("Idade: %d",estudante->idade);
        printf("\nNota: %.2f\n",estudante->nota);
}