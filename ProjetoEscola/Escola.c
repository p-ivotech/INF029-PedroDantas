#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "Escola.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

void listarAniversariantes(Aluno** inicioAluno, Professor** inicioProfessor);
void listarNomes(Aluno** inicioAluno, Professor** inicioProfessor);

int menuGeral(){
	int opcao;

	printf("#### Digite a opção: ####\n");
	printf("0 - Sair\n");
	printf("1 - Gerenciar Aluno\n");
	printf("2 - Gerenciar Professor\n");
	printf("3 - Gerenciar Disciplina\n");
	printf("4 - Buscar Nome\n");
	printf("5 - Listar Aniversariantes do Mês\n");

	scanf("%d",&opcao);

	return opcao;
}

void finalizarEscola(Aluno* inicioAluno, Professor* inicioProfessor, Disciplina* inicioDisciplina){
	liberarListaAluno(inicioAluno); 
	liberarListaProfessor(inicioProfessor);
	liberarListaDisciplina(inicioDisciplina);
}

int main(){
	Aluno aluno; 
	Aluno* inicioListaAluno = NULL; 

	Disciplina disciplina; 
	Disciplina* inicioListaDisciplina = NULL;

	Professor professor; 
	Professor* inicioListaProfessor = NULL;

	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuGeral();
	    
	    switch(opcao){
	      case 0:{
	        printf("Finalizando Escola\n");
	        finalizarEscola(inicioListaAluno, inicioListaProfessor, inicioListaDisciplina);
	        sair = TRUE;
	        break;
	      }
	      case 1: {
	      	mainAluno(&inicioListaAluno, &inicioListaDisciplina);
	      	break;
	      }
	      case 2: {
	      	mainProfessor(&inicioListaProfessor, &inicioListaDisciplina);
	      	break;
	      }
		  case 3: {
			mainDisciplina(&inicioListaDisciplina, &inicioListaProfessor, &inicioListaAluno);
	      	break;
		  }
		  case 4: {
			listarNomes(&inicioListaAluno, &inicioListaProfessor);
			break;
		  }
		  case 5: {
			listarAniversariantes(&inicioListaAluno, &inicioListaProfessor);
			break;
		  }
		  default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}

char *toLower(char *str, size_t len) {
  char *str_l = calloc(len + 1, sizeof(char));

  for (size_t i = 0; i < len; ++i) {
    str_l[i] = tolower((unsigned char)str[i]);
  }
  return str_l;
}

void strToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void listarNomes(Aluno** inicioAluno, Professor** inicioProfessor){
	char letras[50];
	printf("Digite no mínimo três letras: ");    
    scanf("%s", letras);
    getchar();
	strToLower(letras);

	Aluno* atualAluno = *inicioAluno;
	Professor* atualProfessor = *inicioProfessor;
	int achou = FALSE;

	if(*inicioAluno == NULL && *inicioProfessor == NULL){
        printf("Listas Vazias\n");
	}else{
		int contadorAluno = 0;

		while(atualAluno != NULL){
			char nomeAlunoMinusc[50];
			strcpy(nomeAlunoMinusc, atualAluno->nome);
			strToLower(nomeAlunoMinusc);

			if(strstr(nomeAlunoMinusc, letras) != NULL){
				contadorAluno++;
			}
			atualAluno = atualAluno->prox;
		}

		atualAluno = *inicioAluno;

		if(contadorAluno == 0){
			printf("\n### Alunos ####\n");
			printf("-----\n");
			printf("Não foi encontrado nenhum aluno com as letras digitadas.\n\n");
		}else{
			achou = TRUE;
			
			printf("\n### Alunos ####\n");
			while(atualAluno != NULL){
				char nomeAlunoMinusc[50];
				strcpy(nomeAlunoMinusc, atualAluno->nome);
				strToLower(nomeAlunoMinusc);

				if(strstr(nomeAlunoMinusc, letras) != NULL){
					printf("-----\n");
					printf("Matrícula: %d\n", atualAluno->matricula);
					printf("Nome: %s\n", atualAluno->nome);
					printf("Sexo: %c\n", atualAluno->sexo);
					printf("Data Nascimento: %s\n", atualAluno->data_nascimento.dataCompleta);
					printf("CPF: %s\n", atualAluno->cpf);
				}
				atualAluno = atualAluno->prox;
			}
			printf("-----\n\n");
		}

		int contadorProfessor = 0;

		while(atualProfessor != NULL){
			char nomeProfMinusc[50];
			strcpy(nomeProfMinusc, atualProfessor->nome);
			strToLower(nomeProfMinusc);

			if(strstr(nomeProfMinusc, letras) != NULL){
				contadorProfessor++;
			}
			atualProfessor = atualProfessor->prox;
		}

		atualProfessor = *inicioProfessor;

		if(contadorProfessor == 0){
			printf("\n### Professores ####\n");
			printf("-----\n");
			printf("Não foi encontrado nenhum aluno com as letras digitadas.\n\n");
		}else{
			achou = TRUE;
			
			printf("\n### Professores ####\n");
			while(atualProfessor != NULL){
				char nomeProfMinusc[50];
				strcpy(nomeProfMinusc, atualProfessor->nome);
				strToLower(nomeProfMinusc);

				if(strstr(nomeProfMinusc, letras) != NULL){
					printf("-----\n");
					printf("Matrícula: %d\n", atualProfessor->matricula);
					printf("Nome: %s\n", atualProfessor->nome);
					printf("Sexo: %c\n", atualProfessor->sexo);
					printf("Data Nascimento: %s\n", atualProfessor->data_nascimento.dataCompleta);
					printf("CPF: %s\n", atualProfessor->cpf);
				}
				atualProfessor = atualProfessor->prox;
			}
			printf("-----\n\n");
		}

		if(!achou){
			printf("Não foi encontrado nenhum nome com as letras digitadas.\n");
		}
	}
}

void listarAniversariantes(Aluno** inicioAluno, Professor** inicioProfessor){
	time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);

    int mesAtual = dataAtual.tm_mon + 1;

	Aluno* atualAluno = *inicioAluno;
	Professor* atualProfessor = *inicioProfessor;
	int achou = FALSE;
	if(*inicioAluno == NULL && *inicioProfessor == NULL){
        printf("Listas Vazias\n");
	}else{
		printf("\n### Aniversariantes do Mês ####\n");
		while(atualAluno != NULL){
			if(atualAluno->data_nascimento.mes == mesAtual){
				achou = TRUE;
				
				printf("-----\n");
				printf("Aluno: %s\n", atualAluno->nome);
				printf("Matrícula: %d\n", atualAluno->matricula);
				printf("Data Nascimento: %s\n", atualAluno->data_nascimento.dataCompleta);
			}
			atualAluno = atualAluno->prox;
		}

		while(atualProfessor != NULL){
			if(atualProfessor->data_nascimento.mes == mesAtual){
				achou = TRUE;
				
				printf("-----\n");
				printf("Professor: %s\n", atualProfessor->nome);
				printf("Matrícula: %d\n", atualProfessor->matricula);
				printf("Data Nascimento: %s\n", atualProfessor->data_nascimento.dataCompleta);
			}
			atualProfessor = atualProfessor->prox;
		}
		printf("-----\n\n");

		if(!achou){
			printf("Não tem nenhum aniversariante esse mês\n");
		}
	}
}