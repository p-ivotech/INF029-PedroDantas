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
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#ifndef PEDRODANTAS20251160046_H
#define PEDRODANTAS20251160046_H

typedef struct DQ {
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, 1 se válido
} DataQuebrada;

typedef struct Qtd {
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

int somar(int x, int y);
int fatorial(int x);

int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
int q7(char matriz[8][10], char palavra[5]);

DataQuebrada quebraData(char data[]);

#endif // PEDRODANTAS20251160046_H
