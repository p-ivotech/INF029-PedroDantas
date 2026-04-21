#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "utilidades.h"
#include "professores.h"
#include "dados.h"


void inserirProfessor(Dados listaProfessores[],int qtdProfessores){
    limparBuffer();
    int matricula;
    while (1){
        printf("\nDigite a matricula do Professor: ");
        scanf("%d", &matricula);
        if (validaMatricula(qtdProfessores, listaProfessores,matricula) == -1){
            printf("Matricula ja existe! Tente novamente.\n");
        } else {
            break;
        }
    }
    listaProfessores[qtdProfessores].matricula = matricula;
    limparBuffer();
    printf("\nDigite o nome do Professor: ");
    fgets(listaProfessores[qtdProfessores].nome,100,stdin);
    
    while (1) {
        printf("\nDigite o CPF do Professor: ");
        fgets(listaProfessores[qtdProfessores].cpf,12,stdin);
        if (validaNumerosCPF(qtdProfessores,listaProfessores) == 1 || validaCPF(qtdProfessores,listaProfessores) == 1) {
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
        listaProfessores[qtdProfessores].sexo = sexo;
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
        listaProfessores[qtdProfessores].nascimento.dia = dia;
        listaProfessores[qtdProfessores].nascimento.mes = mes;
        listaProfessores[qtdProfessores].nascimento.ano = ano;
        break;
    } else {
        printf("Data incorreta!");
    }
    }
    listaProfessores[qtdProfessores].ativo = 1;
}

void atualizaProfessor(int indice,Dados listaProfessores[]){
    limparBuffer();
    int matricula;
    while (1){
        printf("\nDigite a matricula do Professor: ");
        scanf("%d", &matricula);
        if (validaMatricula(indice, listaProfessores,matricula) == -1){
            printf("Matricula ja existe! Tente novamente.\n");
        } else {
            break;
        }
    }
    listaProfessores[indice].matricula = matricula;
    limparBuffer();
    printf("\nDigite o novo nome do Professor: ");
    fgets(listaProfessores[indice].nome,100,stdin);
    while (1) {
        printf("\nDigite o CPF do Professor: ");
        fgets(listaProfessores[indice].cpf,12,stdin);
        if (validaNumerosCPF(indice,listaProfessores) == 1 || validaCPF(indice,listaProfessores) == 1) {
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
        listaProfessores[indice].sexo = sexo;
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
        listaProfessores[indice].nascimento.dia = dia;
        listaProfessores[indice].nascimento.mes = mes;
        listaProfessores[indice].nascimento.ano = ano;
        break;
    } else {
        printf("Data incorreta!");
    }
    }
}

int menuProfessor(){
    int opcaoProfessor;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Inserir Professor");
    printf("\n2 - Excluir Professor");
    printf("\n3 - Atualizar Professor");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcaoProfessor);
    return opcaoProfessor;
}

void listarProfessores(int qtdProfessores, Dados listaProfessores[]){
    if (qtdProfessores == 0){
        printf("Nao existem Professores cadastrados\n");
    } else {
        printf("Listando os Professores...");
        for(int i = 0;i < qtdProfessores;i++){
            if(listaProfessores[i].ativo == 1){
                printf("\nMATRICULA: %d",listaProfessores[i].matricula);
                printf("\nNome: %s",listaProfessores[i].nome);
                printf("\nCPF: %s\n",listaProfessores[i].cpf);
                printf("\nData de Nascimento: %d / %d / %d\n",listaProfessores[i].nascimento.dia,listaProfessores[i].nascimento.mes,listaProfessores[i].nascimento.ano);
            }
        }
    }
}

void listarProfessores_sexo(int qtdProfessores, Dados listaProfessores[],char sexo){
    int existe = 0;
    if (qtdProfessores == 0){
        printf("Nao existem Professores cadastrados\n");
    } else {
        printf("\nListando os Professores...\n");
        for(int i = 0;i < qtdProfessores;i++){
            if(listaProfessores[i].ativo == 1 && listaProfessores[i].sexo == sexo){
                printf("\nMATRICULA: %d",listaProfessores[i].matricula);
                printf("\nNome: %s",listaProfessores[i].nome);
                printf("\nCPF: %s\n",listaProfessores[i].cpf);
                printf("\nData de Nascimento: %d / %d / %d\n",listaProfessores[i].nascimento.dia,listaProfessores[i].nascimento.mes,listaProfessores[i].nascimento.ano);
            existe = 1;
            }
        }
    }

    if (existe != 1){
        printf("\nNao existem Professores cadastrados para esse sexo\n");
    }
}