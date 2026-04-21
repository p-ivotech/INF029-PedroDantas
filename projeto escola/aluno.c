#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "utilidades.h"
#include "aluno.h"
#include "dados.h"


void inserirAluno(Dados listaAlunos[],int qtdAlunos){
    limparBuffer();
    int matricula;
    while (1){
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &matricula);
        if (validaMatricula(qtdAlunos, listaAlunos,matricula) == -1){
            printf("Matricula ja existe! Tente novamente.\n");
        } else {
            break;
        }
    }
    listaAlunos[qtdAlunos].matricula = matricula;
    limparBuffer();
    printf("\nDigite o nome do aluno: ");
    fgets(listaAlunos[qtdAlunos].nome,100,stdin);
    
    while (1) {
        printf("\nDigite o CPF do aluno: ");
        fgets(listaAlunos[qtdAlunos].cpf,12,stdin);
        if (validaNumerosCPF(qtdAlunos,listaAlunos) == 1 || validaCPF(qtdAlunos,listaAlunos) == 1) {
            printf("\nCPF inválido");
        } else {
            break;
        }
    }

    
        //validação do cpf
    getchar();
    char sexo;

    while (1){
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);

        sexo = toupper(sexo);
        if (validaSexo(sexo)){
        listaAlunos[qtdAlunos].sexo = sexo;
        break;
        } else {
        printf("Valor invalido! Digite M ou F.\n");
        }
    }

    int dia, mes, ano;
    while (1){
    printf("\nDigite o novo dia de nascimento: ");
    scanf("%d",&dia);
    printf("\nDigite o novo mes de nascimento: ");
    scanf("%d",&mes);
    printf("\nDigite o novo ano de nascimento: ");
    scanf("%d",&ano);
    if (validaDiaMesANo(dia,mes,ano)==0 && validaData(dia,mes,ano)==0){
        listaAlunos[qtdAlunos].nascimento.dia = dia;
        listaAlunos[qtdAlunos].nascimento.mes = mes;
        listaAlunos[qtdAlunos].nascimento.ano = ano;
        break;
    } else {
        printf("Data incorreta!");
    }
    }
    listaAlunos[qtdAlunos].ativo = 1;
}

void atualizaAluno(int indice,Dados listaAlunos[]){
    limparBuffer();
    int matricula;
    while (1){
        printf("\nDigite a matricula do aluno: ");
        scanf("%d", &matricula);
        if (validaMatricula(indice, listaAlunos,matricula) == -1){
            printf("Matricula ja existe! Tente novamente.\n");
        } else {
            break;
        }
    }
    listaAlunos[indice].matricula = matricula;
    limparBuffer();
    printf("\nDigite o novo nome do aluno: ");
    fgets(listaAlunos[indice].nome,100,stdin);
    while (1) {
        printf("\nDigite o CPF do aluno: ");
        fgets(listaAlunos[indice].cpf,12,stdin);
        if (validaNumerosCPF(indice,listaAlunos) == 1 || validaCPF(indice,listaAlunos) == 1) {
            printf("\nCPF inválido");
        } else {
            break;
        }
    }
        //validação do cpf
    getchar();
    char sexo;

    while (1){
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);

        sexo = toupper(sexo);
        if (validaSexo(sexo)){
        listaAlunos[indice].sexo = sexo;
        break;
        } else {
        printf("Valor invalido! Digite M ou F.\n");
        }
    }
    int dia, mes, ano;
    while (1){
    printf("\nDigite o novo dia de nascimento: ");
    scanf("%d",&dia);
    printf("\nDigite o novo mes de nascimento: ");
    scanf("%d",&mes);
    printf("\nDigite o novo ano de nascimento: ");
    scanf("%d",&ano);
    if (validaDiaMesANo(dia,mes,ano)==0 && validaData(dia,mes,ano)==0){
        listaAlunos[indice].nascimento.dia = dia;
        listaAlunos[indice].nascimento.mes = mes;
        listaAlunos[indice].nascimento.ano = ano;
        break;
    } else {
        printf("Data incorreta!");
    }
    }
}

int menuAluno(){
    int opcaoAluno;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Inserir aluno");
    printf("\n2 - Excluir aluno");
    printf("\n3 - Atualizar aluno");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcaoAluno);
    return opcaoAluno;
}

void listarAlunos(int qtdAlunos, Dados listaAlunos[]){
    if (qtdAlunos == 0){
        printf("Nao existem alunos cadastrados\n");
    } else {
        printf("Listando os alunos...");
        for(int i = 0;i < qtdAlunos;i++){
            if(listaAlunos[i].ativo == 1){
                printf("\nMATRICULA: %d",listaAlunos[i].matricula);
                printf("\nNome: %s",listaAlunos[i].nome);
                printf("\nCPF: %s\n",listaAlunos[i].cpf);
                printf("\nData de Nascimento: %d / %d / %d\n",listaAlunos[i].nascimento.dia,listaAlunos[i].nascimento.mes,listaAlunos[i].nascimento.ano);
            }
        }
    }
}

void listarAlunos_sexo(int qtdAlunos, Dados listaAlunos[],char sexo){
    int existe = 0;
    if (qtdAlunos == 0){
        printf("Nao existem alunos cadastrados\n");
    } else {
        printf("\nListando os alunos...\n");
        for(int i = 0;i < qtdAlunos;i++){
            if(listaAlunos[i].ativo == 1 && listaAlunos[i].sexo == sexo){
                printf("\nMATRICULA: %d",listaAlunos[i].matricula);
                printf("\nNome: %s",listaAlunos[i].nome);
                printf("\nCPF: %s\n",listaAlunos[i].cpf);
                printf("\nData de Nascimento: %d / %d / %d\n",listaAlunos[i].nascimento.dia,listaAlunos[i].nascimento.mes,listaAlunos[i].nascimento.ano);
            existe = 1;
            }
        }
    }

    if (existe != 1){
        printf("\nNao existem alunos cadastrados para esse sexo\n");
    }
}