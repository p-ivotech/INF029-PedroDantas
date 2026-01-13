// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Ivo Alves da Silva Dantas
//  email: pedroivodantas@gmail.com 
//  Matrícula: 20251160046
//  Semestre: 2º semestre

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 13/01/2025

// #################################################


#ifndef trabalho2_H
#define trabalho2_H

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
