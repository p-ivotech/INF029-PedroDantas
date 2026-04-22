#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "aluno.h"
#include "professores.h"

bool valida_opcaoInicial(int opcao){
    return (opcao >= 0 && opcao <= 4);
}

bool valida_opcaoAluno(int opcao){
    return (opcao >= 0 && opcao <= 3);
}

bool valida_opcaoProfessor(int opcao){
    return (opcao >= 0 && opcao <= 3);
}

bool valida_opcaoLista(int opcao){
    return (opcao >= 0 && opcao <=6);
}

bool valida_opcaoDisciplina(int opcao){
    return (opcao >= 0 && opcao <=5);
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validaMatricula(int qtdAlunos,Dados listaAlunos[],int matriculaNova){
    for (int i = 0;i < qtdAlunos;i++){
        if(listaAlunos[i].matricula == matriculaNova){
            return -1;
        }
    }
    return 0;
}

int validaSexo(char sexo){
    if (sexo == 'M' || sexo == 'F'){
        return 1;
    } else {
        return 0;
    }
}

int validaDiaMesANo(int dia, int mes, int ano){
    if (dia <= 0){
        return -1;
    }

    if (mes < 1 || mes > 12){
        return -2;
    }

    if (ano < 0){
        return -3;
    }
    return 0;
}

int validaBissexto(int ano){
    if (ano%4 == 0 && ano%100 != 0){
        return 0;
    } else if (ano%4 == 0 && ano%100 == 0 && ano%400 == 0){
        return 0;
    } else {
        return -1;
    }
}

int validaData(int dia, int mes, int ano){
    switch(mes){
        case 1:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 2:{
            if (validaBissexto(ano) == 0){
                if (dia > 29){
                    return -1;
                } else {
                    return 0;
                }
            } else if (dia > 28){
                return -1;
            } else {
                return 0;
            }
        }
        case 3:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 4:{
            if (dia > 30){
                return -1;
            }
            return 0;
        }
        case 5:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 6:{
            if (dia > 30){
                return -1;
            }
            return 0;
        }
        case 7:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 8:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 9:{
            if (dia > 30){
                return -1;
            }
            return 0;
        }
        case 10:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
        case 11:{
            if (dia > 30){
                return -1;
            }
            return 0;
        }
        case 12:{
            if (dia > 31){
                return -1;
            }
            return 0;
        }
    break;
    }
return 0;
}

int validaCPF(char cpf[]) {
    
    if (strlen(cpf) != 11) {
        return 1;
    }

    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return 1;
        }
    }

    int iguais = 1;
    for (int i = 1; i < 11; i++) {
        if (cpf[i] != cpf[0]) {
            iguais = 0;
            break;
        }
    }
    if (iguais) {
        return 1;
    }


    int dig[11];
    for (int i = 0; i < 11; i++) {
        dig[i] = cpf[i] - '0';
    }

    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += dig[i] * (10 - i);
    }

    int resto = soma % 11;
    int dv1 = (resto < 2) ? 0 : (11 - resto);

    if (dig[9] != dv1) {
        return 1;
    }

    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += dig[i] * (11 - i);
    }

    resto = soma % 11;
    int dv2 = (resto < 2) ? 0 : (11 - resto);

    if (dig[10] != dv2) {
        return 1;
    }

    return 0;
}

int CPFexistente(int qtdAlunos, Dados listaAlunos[], char cpf[]){
    for (int i = 0; i < qtdAlunos; i++) {
        if (listaAlunos[i].ativo == 1 &&
            strcmp(listaAlunos[i].cpf, cpf) == 0) {
            return 1;
        }
    }
return 0;
}
