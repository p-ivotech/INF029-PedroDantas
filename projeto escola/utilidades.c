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
}

int validaNumerosCPF(int qtdAlunos,Dados listaAlunos[]){
    if (strlen(listaAlunos[qtdAlunos].cpf) != 11){
        return 1;
    }
    for (int i = 0; i < 11;i++){
        if(listaAlunos[qtdAlunos].cpf[i] < '0' || listaAlunos[qtdAlunos].cpf[i] > '9'){
            return 1;
        }
    }

    for (int i = 0; i < qtdAlunos;i++){
        if(listaAlunos[i].cpf[i] == listaAlunos[i+1].cpf[i]){
            return 1;
        }
    }

    return 0;
}

int validaCPF(int qtdAlunos,Dados listaAlunos[]){
    
    int dig[11]; 
    for (int i = 0; i < 11;i++){
        dig[i] = listaAlunos[qtdAlunos].cpf[i] - '0';
    }
    
    for (int i = 0; i < 11;i++){
        if(dig[i] == dig[i+1]){
            return 1;
        }
    }
    
    int resultado[8];
    int soma = 0;
    for(int i = 0; i < 9;i++){
        int j = 10 - i;
        for (int k = i; k < 9;k++){
            resultado[k] = dig[i] * j;
        }
    soma = resultado[i] + soma;
    }
    
    int verificador1 = soma%11;
    
    
    if (verificador1 <= 1){
        if(dig[9] != 0){
            return 1;
        }
    }
    
    if (verificador1 > 2){
        if (dig[9] != (11-(verificador1))){
            return 1;
        }
    }
    
    int resultado2[9];
    int soma2 = 0;
    for(int i = 0; i < 10;i++){
        int j = 11 - i;
        for (int k = i; k < 10;k++){
            resultado2[k] = dig[i] * j;
        }
    soma2 = resultado2[i] + soma2;
    }
    
    int verificador2 = soma2%11;
    
    if (verificador2 <= 1){
        if(dig[10] != 0){
            return 1;
        }
    } 
    
    if (verificador2 >= 2){
        if (dig[10] != (11-(verificador2))){
            return 1;
        }
    }
    
    
    return 0;
    
}