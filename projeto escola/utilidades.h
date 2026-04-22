#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdbool.h>
#include "dados.h"

bool valida_opcaoAluno(int opcao);
bool valida_opcaoProfessor(int opcao);
bool valida_opcaoInicial(int opcao);
bool valida_opcaoLista(int opcao);
bool valida_opcaoDisciplina(int opcao);
int validaMatricula(int qtdAlunos,Dados listaAlunos[],int matriculaNova);
int validaSexo(char sexo);
int validaDiaMesANo(int dia, int mes, int ano);
int validaData(int dia, int mes, int ano);
int validaBissexto(int ano);
int validaCPF(char cpf[]);
int CPFexistente(int qtdAlunos, Dados listaAlunos[], char cpf[]);
void limparBuffer();

#endif