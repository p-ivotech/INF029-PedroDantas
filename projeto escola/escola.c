#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include "utilidades.h"
#include "aluno.h"
#include "professores.h"
#include "disciplina.h"
#include "escola.h"
#include "dados.h"

#define TAM 2

int menuListatem(){
    int opcaoLista;
    printf("\n-----Menu de Listagem-----\n");
    printf("\n1 - Lista de Alunos");
    printf("\n2 - Lista de Alunos por Sexo");
    printf("\n3 - Lista de Professores");
    printf("\n4 - Lista de Professores por Sexo");
    printf("\n5 - Lista de Disciplinas");
    printf("\n6 - Listar uma Disciplina e seus dados");
    printf("\n0 - Voltar");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opcaoLista);
    return opcaoLista;
}

int menuInicial(){
    int opcao;
    printf("\n--------MENU--------\n");
    printf("\n0 - Sair\n");
    printf("\n1 - Cadastrar aluno");
    printf("\n2 - Cadastrar professor");
    printf("\n3 - Cadastrar disciplina");
    printf("\n4 - Pesquisar Listas");
    printf("\nEscolha um opcao:\n");
    scanf("%d",&opcao);
    return opcao;
}

int main(){

    Dados listaAlunos[TAM];
    Dados listaProfessores[TAM];
    Disciplina listaDisciplinas[TAM];

    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;
    int sair = 0;
    int opcao;

    while (!sair){
        opcao = menuInicial();
        if (!valida_opcaoInicial(opcao)){
            printf("OPCAO INVALIDA\n");
        }
        switch (opcao){

            case 0:{
                sair = 1;
                break;
            }

            case 1:{
                int sairAluno = 0;

                while (!sairAluno){
                    int opcaoAluno = menuAluno();
                    if (!valida_opcaoAluno(opcaoAluno)){
                        printf("OPCAO INVALIDA\n");
                    }
                    switch(opcaoAluno){

                        case 0:{
                            sairAluno = 1;
                            break;
                        }

                        case 1:{
                            if (qtdAlunos < TAM){
                                inserirAluno(listaAlunos,qtdAlunos);
                                    qtdAlunos++;
                                } else {
                                printf("Lista de Alunos Completa\n");
                            }
                            break;
                        }
                        case 2:{
                            if (qtdAlunos == 0){
                                printf("Sem alunos cadastrados!");
                            } else {
                                listarAlunos(qtdAlunos,listaAlunos);

                                int matricula;
                                printf("Digite a matricula do aluno que deseja excluir: ");
                                scanf("%d",&matricula);

                                if (matricula < 0){
                                    printf("Matricula invalida");
                                }

                                int indice = -1;
                                for (int i = 0; i < qtdAlunos; i++){
                                    if(matricula == listaAlunos[i].matricula && listaAlunos[i].ativo == 1){
                                        indice = i;
                                    }
                                }
                                if (indice == -1){
                                    printf("Matricula nao encontrada");
                                } else {
                                    listaAlunos[indice].ativo = 0;
                                }
                            }
                            break;
                        }

                        case 3:{
                            listarAlunos(qtdAlunos,listaAlunos);

                            int matricula;
                            printf("Digite a matricula do aluno que deseja atualizar: ");
                            scanf("%d",&matricula);

                            if (matricula < 0){
                                printf("Matricula invalida");
                            }

                            int indice = -1;
                            for (int i = 0; i < qtdAlunos; i++){
                                if(matricula == listaAlunos[i].matricula){
                                    indice = i;
                                }
                            }

                            if (indice == -1){
                                printf("Matricula nao encontrada");
                            } else {
                                atualizaAluno(indice,listaAlunos);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 2:{
                int sairProfessor = 0;

                while (!sairProfessor){
                    int opcaoProfessor = menuProfessor();
                    if (!valida_opcaoProfessor(opcaoProfessor)){
                        printf("OPCAO INVALIDA\n");
                    }
                    switch(opcaoProfessor){

                        case 0:{
                            sairProfessor = 1;
                            break;
                        }

                        case 1:{
                            if (qtdProfessores < TAM){
                                inserirProfessor(listaProfessores,qtdProfessores);
                                qtdProfessores++;
                                } else {
                                printf("Lista de Professores Completa\n");
                            }
                            break;
                        }
                        case 2:{
                            if (qtdProfessores == 0){
                                printf("Sem Professores cadastrados!");
                            } else {
                                listarProfessores(qtdProfessores,listaProfessores);

                                int matricula;
                                printf("Digite a matricula do Professor que deseja excluir: ");
                                scanf("%d",&matricula);

                                if (matricula < 0){
                                    printf("Matricula invalida");
                                }

                                int indice = -1;
                                for (int i = 0; i < qtdProfessores; i++){
                                    if(matricula == listaProfessores[i].matricula && listaProfessores[i].ativo == 1){
                                        indice = i;
                                    }
                                }
                                if (indice == -1){
                                    printf("Matricula nao encontrada");
                                } else {
                                    listaProfessores[indice].ativo = 0;
                                }
                            }
                            break;
                        }

                        case 3:{
                            listarProfessores(qtdProfessores,listaProfessores);

                            int matricula;
                            printf("Digite a matricula do Professor que deseja atualizar: ");
                            scanf("%d",&matricula);

                            if (matricula < 0){
                                printf("Matricula invalida");
                            }

                            int indice = -1;
                            for (int i = 0; i < qtdProfessores; i++){
                                if(matricula == listaProfessores[i].matricula){
                                    indice = i;
                                }
                            }

                            if (indice == -1){
                                printf("Matricula nao encontrada");
                            } else {
                                atualizaProfessor(indice,listaProfessores);
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 3:{ 
                
                int sairDisciplina = 0;

                while (!sairDisciplina){
                    int opcaoDisciplina = menuDisciplina();
                    if (!valida_opcaoDisciplina(opcaoDisciplina)){
                        printf("OPCAO INVALIDA\n");
                    }
                    switch(opcaoDisciplina){

                        case 0:{
                            sairDisciplina = 1;
                        break;
                        }
                        case 1:{//inserir disciplina
                            inserirDisciplina(listaDisciplinas,qtdDisciplinas,listaProfessores,qtdProfessores);
                            qtdDisciplinas++;
                        break;
                        }
                        case 2:{
                            apagarDisciplina(listaDisciplinas,qtdDisciplinas);
                            qtdDisciplinas--;
                        break;
                        }
                        case 3:{
                            atualizarDisciplina(listaDisciplinas,qtdDisciplinas,listaProfessores, qtdProfessores);
                        break;
                        }
                        case 4:{
                            adicionarAlunoDisciplina(listaDisciplinas,qtdDisciplinas,listaAlunos,qtdAlunos);
                        break;
                        }
                        case 5:{
                            removerAlunoDisciplina(listaDisciplinas,qtdDisciplinas);
                        break;
                        }
                    }
                }
            break;
            }
            case 4:{
                int sairLista = 0;
                while (!sairLista){
                    int opcaoLista = menuListatem();
                    if (!valida_opcaoLista(opcaoLista)){
                        printf("OPCAO INVALIDA\n");
                    }
                    switch(opcaoLista){

                        case 0:{
                            sairLista = 1;
                            break;
                        }

                        case 1:{
                            listarAlunos(qtdAlunos,listaAlunos);
                            break;
                        }

                        case 2:{
                            char sexo;
                            sexo = toupper(sexo);
                            printf("Por qual sexo deseja filtrar? (M/F)");
                            scanf(" %c",&sexo);
                            listarAlunos_sexo(qtdAlunos,listaAlunos,sexo);
                        break;
                        }
                        case 3:{
                            listarProfessores(qtdProfessores,listaProfessores);
                        break;
                        }
                        case 4:{
                            char sexo;
                            sexo = toupper(sexo);
                            printf("Por qual sexo deseja filtrar? (M/F)");
                            scanf(" %c",&sexo);
                            listarProfessores_sexo(qtdProfessores,listaProfessores,sexo);
                        break;
                        }
                        case 5:{
                        listarDisciplinas(listaDisciplinas,qtdDisciplinas);
                        break;
                        }
                        case 6:{
                        listarUmaDisciplina(listaDisciplinas,qtdDisciplinas,listaAlunos,qtdAlunos);
                        break;
                        }
                    }
                }
                break;
            }
        }
    }

    return 0;
}