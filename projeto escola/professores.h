#ifndef PROFESSORES_H
#define PROFESSORES_H

#include "dados.h"

void inserirProfessor(Dados listaProfessores[],int qtdProfessores);
void listarProfessores(int qtdProfessores, Dados listarProfessores[]);
void atualizaProfessor(int indice,Dados listaProfessores[]);
void listarProfessores_sexo(int qtdProfessores, Dados listaProfessores[],char sexo);
int menuProfessor();

#endif