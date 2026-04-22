#ifndef DADOS_H
#define DADOS_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int ativo;
    char cpf[14];
    char nome[100];
    char sexo;
    int matricula;
    Data nascimento;
} Dados;

typedef struct{
    char nome[50];
    char codigo[12];
    int semestre;
    int matriculaProfessor;
    int alunos[50];
    int qtdAlunos;
} Disciplina;

#endif