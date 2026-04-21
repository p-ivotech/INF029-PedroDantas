#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "dados.h"

void inserirDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaProfessores[], int qtdProfessores);
void listarDisciplinas(Disciplina lista[], int qtdDisciplinas);
void atualizarDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaProfessores[], int qtdProfessores);
void apagarDisciplina(Disciplina lista[], int qtdDisciplinas);
void adicionarAlunoDisciplina(Disciplina lista[], int qtdDisciplinas, Dados listaAlunos[], int qtdAlunos);
void removerAlunoDisciplina(Disciplina lista[], int qtdDisciplinas);
void listarUmaDisciplina(Disciplina lista[], int qtdDisciplinas,Dados listaAlunos[], int qtdAlunos);
int menuDisciplina();

#endif