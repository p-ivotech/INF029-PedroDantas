#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "utilidades.h"
#include "disciplina.h"

int menuDisciplina(){
    int opcaoDisciplina;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Inserir Disciplina");
    printf("\n2 - Excluir Disciplina");
    printf("\n3 - Atualizar Disciplina");
    printf("\n4 - Adicionar Aluno na Disciplina");
    printf("\n5 - Excluir Aluno da Disciplina");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcaoDisciplina);
    return opcaoDisciplina;
}

void inserirDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaProfessores[], int qtdProfessores){

    printf("Nome da disciplina: ");
    getchar();
    fgets(lista[qtdDisciplinas].nome, 50, stdin);

    printf("Codigo da disciplina: ");
    fgets(lista[qtdDisciplinas].codigo, 12, stdin);

    printf("Semestre: ");
    scanf("%d", &lista[qtdDisciplinas].semestre);

    int idProfessor;
    int existe = 0;

    printf("Matricula do professor: ");
    scanf("%d", &idProfessor);

    for (int i = 0; i < qtdProfessores; i++){
        if (listaProfessores[i].matricula == idProfessor && listaProfessores[i].ativo){
            existe = 1;
            break;
        }
    }

    if (!existe){
        printf("Professor nao encontrado!\n");
        return;
    }

    lista[qtdDisciplinas].matriculaProfessor = idProfessor;
    lista[qtdDisciplinas].qtdAlunos = 0;

    printf("Disciplina cadastrada com sucesso!\n");
}

void listarDisciplinas(Disciplina lista[], int qtdDisciplinas){

    for (int i = 0; i < qtdDisciplinas; i++){
        printf("\nNome: %s", lista[i].nome);
        printf("Codigo: %s", lista[i].codigo);
        printf("Semestre: %d\n", lista[i].semestre);
        printf("Professor: %d\n", lista[i].matriculaProfessor);
    }
}

void atualizarDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaProfessores[], int qtdProfessores){

    char codigo[12];
    printf("Digite o codigo da disciplina: ");
    getchar();
    fgets(codigo, 12, stdin);

    int indice = -1;

    for (int i = 0; i < qtdDisciplinas; i++){
        if (strcmp(lista[i].codigo, codigo) == 0){
            indice = i;
            break;
        }
    }

    if (indice == -1){
        printf("Disciplina nao encontrada\n");
        return;
    }

    printf("Novo nome: ");
    fgets(lista[indice].nome, 50, stdin);

    printf("Novo semestre: ");
    scanf("%d", &lista[indice].semestre);

    int idProfessor;
    int existe = 0;

    printf("Nova matricula do professor: ");
    scanf("%d", &idProfessor);

    for (int i = 0; i < qtdProfessores; i++){
        if (listaProfessores[i].matricula == idProfessor && listaProfessores[i].ativo){
            existe = 1;
            break;
        }
    }

    if (!existe){
        printf("Professor nao encontrado\n");
        return;
    }

    lista[indice].matriculaProfessor = idProfessor;

    printf("Disciplina atualizada!\n");
}

void apagarDisciplina(Disciplina lista[], int qtdDisciplinas){

    char codigo[12];
    printf("Digite o codigo da disciplina: ");
    getchar();
    fgets(codigo, 12, stdin);

    int indice = -1;

    for (int i = 0; i < qtdDisciplinas; i++){
        if (strcmp(lista[i].codigo, codigo) == 0){
            indice = i;
            break;
        }
    }

    if (indice == -1){
        printf("Disciplina nao encontrada\n");
        return;
    }

    for (int i = indice; i < qtdDisciplinas - 1; i++){
        lista[i] = lista[i + 1];
    }
    
    printf("Disciplina removida!\n");
    //TENHO QUE REMOVER NA MAIN QTDDISCIPLINA
}

void adicionarAlunoDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaAlunos[], int qtdAlunos){

    char codigo[12];
    printf("Codigo da disciplina: ");
    getchar();
    fgets(codigo, 12, stdin);

    int indice = -1;

    for (int i = 0; i < qtdDisciplinas; i++){
        if (strcmp(lista[i].codigo, codigo) == 0){
            indice = i;
            break;
        }
    }

    if (indice == -1){
        printf("Disciplina nao encontrada\n");
        return;
    }

    int matricula;
    printf("Matricula do aluno: ");
    scanf("%d", &matricula);

    int existe = 0;
    for (int i = 0; i < qtdAlunos; i++){
        if (listaAlunos[i].matricula == matricula && listaAlunos[i].ativo){
            existe = 1;
            break;
        }
    }

    if (!existe){
        printf("Aluno nao encontrado\n");
        return;
    }

    lista[indice].alunos[lista[indice].qtdAlunos] = matricula;
    lista[indice].qtdAlunos++;

    printf("Aluno adicionado!\n");
}

void removerAlunoDisciplina(Disciplina lista[], int qtdDisciplinas){

    char codigo[12];
    printf("Codigo da disciplina: ");
    getchar();
    fgets(codigo, 12, stdin);

    int indice = -1;

    for (int i = 0; i < qtdDisciplinas; i++){
        if (strcmp(lista[i].codigo, codigo) == 0){
            indice = i;
            break;
        }
    }

    if (indice == -1){
        printf("Disciplina nao encontrada\n");
        return;
    }

    int matricula;
    printf("Matricula do aluno: ");
    scanf("%d", &matricula);

    int pos = -1;

    for (int i = 0; i < lista[indice].qtdAlunos; i++){
        if (lista[indice].alunos[i] == matricula){
            pos = i;
            break;
        }
    }

    if (pos == -1){
        printf("Aluno nao esta na disciplina\n");
        return;
    }

    for (int i = pos; i < lista[indice].qtdAlunos - 1; i++){
        lista[indice].alunos[i] = lista[indice].alunos[i + 1];
    }

    lista[indice].qtdAlunos--;

    printf("Aluno removido!\n");
}

void listarUmaDisciplina(Disciplina lista[], int qtdDisciplinas,Dados listaAlunos[], int qtdAlunos){

    char codigo[12];

    printf("Digite o codigo da disciplina: ");
    getchar();
    fgets(codigo, 12, stdin);

    int indice = -1;
    for (int i = 0; i < qtdDisciplinas; i++){
        if (strcmp(lista[i].codigo, codigo) == 0){
            indice = i;
            break;
        }
    }

    if (indice == -1){
        printf("Disciplina nao encontrada\n");
        return;
    }
    printf("\n--- DISCIPLINA ---\n");
    printf("Nome: %s", lista[indice].nome);
    printf("Codigo: %s", lista[indice].codigo);
    printf("Semestre: %d\n", lista[indice].semestre);
    printf("Professor (matricula): %d\n", lista[indice].matriculaProfessor);

    // Mostrar alunos
    printf("\n--- ALUNOS MATRICULADOS ---\n");

    if (lista[indice].qtdAlunos == 0){
        printf("Nenhum aluno matriculado\n");
        return;
    }

    for (int i = 0; i < lista[indice].qtdAlunos; i++){
        int matriculaAluno = lista[indice].alunos[i];

        for (int j = 0; j < qtdAlunos; j++){
            if (listaAlunos[j].matricula == matriculaAluno && listaAlunos[j].ativo){
                printf("\nMatricula: %d", listaAlunos[j].matricula);
                printf("\nNome: %s", listaAlunos[j].nome);
                printf("\nCPF: %s\n", listaAlunos[j].cpf);
                break;
            }
        }
    }
}