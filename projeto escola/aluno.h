#ifndef ALUNO_H
#define ALUNO_H

#include "dados.h"

void inserirAluno(Dados listaAlunos[],int qtdAlunos);
void listarAlunos(int qtdAlunos, Dados listarAlunos[]);
void atualizaAluno(int indice,Dados listaAlunos[]);
void listarAlunos_sexo(int qtdAlunos, Dados listaAlunos[],char sexo);
int menuAluno();

#endif