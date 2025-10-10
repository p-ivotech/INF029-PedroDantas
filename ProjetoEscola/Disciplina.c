#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

int inserirDisciplina(Disciplina** inicioDisciplina, Professor** inicioListaProfessor);
int atualizarDisciplina(Disciplina** inicioDisciplina, Professor** inicioListaProfessor);
int excluirDisciplina(Disciplina** inicioDisciplina);
void listarDisciplinas(Disciplina** inicioDisciplina);
int matricularAluno(Disciplina** inicioDisciplina, Aluno** inicioListaAluno);
int menuDisciplina();

int geraCodigo(){
	static int num = 0;
	num++;
	return num;
}

int validarCadastroDisciplina(Disciplina* disciplina, Professor** inicioProfessor){
	int retorno = SUCESSO_CADASTRO;
	
	printf("Digite o nome: ");
    fgets(disciplina->nome, 50, stdin);
    size_t ln = strlen(disciplina->nome) - 1;
    if(disciplina->nome[ln] == '\n')
        disciplina->nome[ln] = '\0';

    printf("Digite o semestre: ");
    scanf("%d", &disciplina->semestre);
	getchar();

    if(disciplina->semestre <= 0){
        retorno = ERRO_CADASTRO_SEMESTRE;
    }else{
		int matricula;
		printf("Digite a matrícula do professor: ");    
		scanf("%d", &matricula);
		getchar();

		Professor* atual = *inicioProfessor;
		int achou = FALSE;

		while(atual != NULL){
			if(atual->matricula == matricula){
				achou = TRUE;
				break;
			}
			atual = atual->prox;
		}

		if(achou){
			strcpy(disciplina->professor, atual->nome);
		}else
			return ERRO_CADASTRO_PROFESSOR;
    }
	return retorno;
}

int menuDisciplina(){
	int opcao;

	printf("#### Módulo de Disciplina ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Disciplina\n");
	printf("2 - Atualizar Disciplina\n");
	printf("3 - Excluir Disciplina\n");
	printf("4 - Listar Disciplina\n");
	printf("5 - Matricular Aluno\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainDisciplina(Disciplina** inicioListaDisciplina, Professor** inicioListaProfessor, Aluno** inicioListaAluno){
	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuDisciplina();
	    
	    switch(opcao){
	      case 0:{
	        sair = TRUE;
	        break;
	      }
	      case 1:{
	      	retorno = inserirDisciplina(inicioListaDisciplina, inicioListaProfessor);

	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Disciplina cadastrada com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_SEMESTRE:{
	      				printf("Semestre Inválido. Deve ser maior que 0.\n");
	      				break;
	      			}
                    case ERRO_CADASTRO_PROFESSOR:{
	      				printf("Professor não cadastrado.\n");
	      				break;
	      			}
                    default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
		  case 2: {
			retorno = atualizarDisciplina(inicioListaDisciplina, inicioListaProfessor);
	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Disciplina atualizada com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case ERRO_CADASTRO_SEMESTRE:{
	      				printf("Semestre Inválido. Deve ser maior que 0.\n");
	      				break;
	      			}
                    case ERRO_CADASTRO_PROFESSOR:{
	      				printf("Professor não cadastrado.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a disciplina com o código digitado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
		  }
	      case 3: {
	      	retorno = excluirDisciplina(inicioListaDisciplina);
	      	if(retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Disciplina excluida com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a disciplina com o código digitado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
	      case 4: {
	      	listarDisciplinas(inicioListaDisciplina);
	      	break;	
	      }
		  case 5: {
	      	retorno = matricularAluno(inicioListaDisciplina, inicioListaAluno);
	      	if(retorno == SUCESSO_MATRICULA){ 
	      		printf("Aluno matriculado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrada a disciplina com o código digitado.\n");
	      				break;
	      			}
					case ERRO_CADASTRO_ALUNO:{
	      				printf("Aluno não cadastrado.\n");
	      				break;
	      			}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
	      }
          default:{
	      	printf("opcao inválida\n");
	      }
	  	}
	}
}

void inserirDisciplinaNaLista(Disciplina** inicioDisciplina, Disciplina* novaDisciplina){
    Disciplina *atual;
    
    if(*inicioDisciplina == NULL)
        *inicioDisciplina = novaDisciplina;
    else{
        atual = *inicioDisciplina;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novaDisciplina;
    }
    
    novaDisciplina->prox = NULL;
}

int inserirDisciplina(Disciplina** inicioDisciplina, Professor** inicioListaProfessor){
    Disciplina* novaDisciplina = (Disciplina *)malloc(sizeof(Disciplina));
    
    printf("\n### Cadastro de Disciplina ###\n");
    getchar();

	int retorno = validarCadastroDisciplina(novaDisciplina, inicioListaProfessor);
	
    if(retorno == SUCESSO_CADASTRO){
    	novaDisciplina->codigo = geraCodigo();
		novaDisciplina->qtdAlunos = 0;
    	inserirDisciplinaNaLista(inicioDisciplina, novaDisciplina);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novaDisciplina);
    	return retorno;
    }
}

int atualizarDisciplinaNaLista(Disciplina** inicioDisciplina, int codigo, Professor** inicioListaProfessor){
	if(*inicioDisciplina == NULL)
		return LISTA_VAZIA;

	Disciplina* atual = *inicioDisciplina;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->codigo == codigo){
			achou = TRUE;
			break;
		}
		atual = atual->prox;
	}

	if(achou){
		printf("\n### Atualização de Disciplina ###\n");

		Disciplina tmp;

		int retorno = validarCadastroDisciplina(&tmp, inicioListaProfessor);	

		if(retorno == SUCESSO_CADASTRO){
			strcpy(atual->nome, tmp.nome);
        	atual->semestre = tmp.semestre;
        	strcpy(atual->professor, tmp.professor);
		}

		return retorno;
	}else
		return NAO_ENCONTRADO;
}

int atualizarDisciplina(Disciplina** inicioDisciplina, Professor** inicioListaProfessor){
	int codigo;
	printf("Digite o código: ");    
    scanf("%d", &codigo);
    getchar();

	return atualizarDisciplinaNaLista(inicioDisciplina, codigo, inicioListaProfessor);
}

int excluirDisciplinaNaLista(Disciplina** inicioDisciplina, int codigo){
	if(*inicioDisciplina == NULL)
		return LISTA_VAZIA;

	Disciplina* anterior = *inicioDisciplina;
	Disciplina* atual = *inicioDisciplina;
	Disciplina* proximo = atual->prox;
	int achou = FALSE;

	while(atual != NULL){
		if(atual->codigo == codigo){
			achou = TRUE;
			break;
		}
		anterior = atual;
		atual = proximo;
		if(atual != NULL)
			proximo = atual->prox;
	}

	if(achou){
		if(atual == *inicioDisciplina)
			*inicioDisciplina = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);
		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;
}

int excluirDisciplina(Disciplina** inicioDisciplina){
	int codigo;
	printf("Digite o código: ");    
    scanf("%d", &codigo);
    getchar();

	return excluirDisciplinaNaLista(inicioDisciplina, codigo);
}


void listarDisciplinas(Disciplina** inicioDisciplina){
    int i;
    Disciplina* DisciplinaAtual = *inicioDisciplina;
    if(*inicioDisciplina == NULL){
        printf("Lista Vazia\n");
    }else{
    	printf("\n### Disciplinas Cadastradas ####\n");
        do{
            printf("-----\n");
            printf("Código: %d\n", DisciplinaAtual->codigo);
            printf("Nome: %s\n", DisciplinaAtual->nome);
            printf("Semestre: %d\n", DisciplinaAtual->semestre);
            printf("Professor: %s\n", DisciplinaAtual->professor);

			printf("\n### Alunos Matriculados ####\n");
			for(int i = 0; i < DisciplinaAtual->qtdAlunos; i++){
				printf("Aluno: %s\n", DisciplinaAtual->aluno[i]);
			}

            DisciplinaAtual = DisciplinaAtual->prox;
        }while (DisciplinaAtual != NULL);
    }    
    printf("-----\n\n");
}

void liberarListaDisciplina(Disciplina* inicioDisciplina){
	Disciplina* atual = inicioDisciplina;
	Disciplina* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}

int matricularAlunoNaLista(Disciplina** inicioDisciplina, int codigo, Aluno** inicioAluno){
	if(*inicioDisciplina == NULL)
		return LISTA_VAZIA;

	Disciplina* atualDisciplina = *inicioDisciplina;
	int achou = FALSE;

	while(atualDisciplina != NULL){
		if(atualDisciplina->codigo == codigo){
			achou = TRUE;
			break;
		}
		atualDisciplina = atualDisciplina->prox;
	}

	if(achou){
		Aluno* atualAluno = *inicioAluno;
		int achou = FALSE;

		int matricula;
		printf("Digite a matrícula do aluno: ");    
		scanf("%d", &matricula);
		getchar();

		while(atualAluno != NULL){
			if(atualAluno->matricula == matricula){
				achou = TRUE;
				break;
			}
			atualAluno = atualAluno->prox;
		}

		if(achou){
			strcpy(atualDisciplina->aluno[atualDisciplina->qtdAlunos], atualAluno->nome);
			atualDisciplina->qtdAlunos++;

			return SUCESSO_MATRICULA;
		}else{
			return ERRO_CADASTRO_ALUNO;
		}
	}else{
		return NAO_ENCONTRADO;
	}
}

int matricularAluno(Disciplina** inicioDisciplina, Aluno** inicioAluno){
	int codigo;
	printf("Digite o código da disciplina: ");    
    scanf("%d", &codigo);
    getchar();

	return matricularAlunoNaLista(inicioDisciplina, codigo, inicioAluno);
}