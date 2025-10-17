#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Escola.h"
#include "Disciplina.h"
#include "Professor.h"

int inserirProfessor(Professor** inicioProfessor);
int atualizarProfessor(Professor** inicioProfessor);
int excluirProfessor(Professor** inicioProfessor, Disciplina** inicioDisciplina);
void listarProfessores(Professor** inicioProfessor);
void listarProfessoresPorNome(Professor** inicioProfessor);
void listarProfessoresPorSexo(Professor** inicioProfessor);
void listarProfessoresPorData(Professor** inicioProfessor);
int compararDatas(Data* data1, Data* data2);
int menuProfessor();


int geraMatriculaProfessor(){
	static int num = 0;
	num++;
	return num;
}

int menuListarProfessor(){
	int opcao;

	printf("#### Listagem ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o módulo de professor\n");
	printf("1 - Listar Professores\n");
	printf("2 - Listar Professores por Sexo\n");
	printf("3 - Listar Professores Ordenados por Nome\n");
	printf("4 - Listar Professores Ordenados por Data de Nascimento\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainListarProfessor(Professor** inicioListaProfessor){
	int opcao;
	int sair = FALSE;

	while (!sair){
		opcao = menuListarProfessor();
		
		switch(opcao){
			case 0:{
			sair = TRUE;
			break;
			}
			case 1:{
				listarProfessores(inicioListaProfessor);
				break;
			}
			case 2:{
				listarProfessoresPorSexo(inicioListaProfessor);
				break;
			}
			case 3:{
				listarProfessoresPorNome(inicioListaProfessor);
				break;
			}
			case 4:{
				listarProfessoresPorData(inicioListaProfessor);
				break;
			}
			default:{
				printf("opcao inválida\n");
			}
		}
	}
}

int menuProfessor(){
	int opcao;

	printf("#### Módulo de Professor ####\n");
	printf("#### Digite a opção: ####\n");
	printf("0 - Voltar para o menu geral\n");
	printf("1 - Inserir Professor\n");
	printf("2 - Atualizar Professor\n");
	printf("3 - Excluir Professor\n");
	printf("4 - Listar Professor\n");
	scanf("%d",&opcao);

	return opcao;
}

void mainProfessor(Professor** inicioListaProfessor, Disciplina** inicioListaDisciplina){
	int opcao, retorno;
	int sair = FALSE;

	while (!sair){
	    opcao = menuProfessor();
	    
	    switch(opcao){
	      case 0:{
	        sair = TRUE;
	        break;
	      }
	      case 1:{
	      	retorno = inserirProfessor(inicioListaProfessor);

	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Professor cadastrado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case ERRO_CADASTRO_SEXO:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
	      			case ERRO_DATA_INVALIDA:{
	      				printf("Data Inválida.\n");
	      				break;
	      			}
					case ERRO_CPF_INVALIDO:{
    					printf("CPF invalido. Digite novamente um CPF valido.\n");
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
			retorno = atualizarProfessor(inicioListaProfessor);
	      	if(retorno == SUCESSO_CADASTRO){ 
	      		printf("Professor atualizado com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case ERRO_CADASTRO_SEXO:{
	      				printf("Sexo Inválido. Digite 'm' ou 'M' para Masculino ou 'f' ou 'F' para Feminino.\n");
	      				break;
	      			}
	      			case ERRO_DATA_INVALIDA:{
	      				printf("Data Inválida.\n");
	      				break;
	      			}
	      			case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o professor com a matrícula digitado.\n");
	      				break;
	      			}
					case ERRO_CPF_INVALIDO:{
    					printf("CPF invalido. Digite novamente um CPF valido.\n");
    					break;
					}
	      			default:{
	      				printf("Erro desconhecido.\n");
	      			}
	      		}
	      	}  
	      	break;
		  }
	      case 3:{
	      	retorno = excluirProfessor(inicioListaProfessor, inicioListaDisciplina);
	      	if(retorno == SUCESSO_EXCLUSAO){ 
	      		printf("Professor excluido com sucesso\n");
	      	}else{
	      		switch(retorno){
	      			case LISTA_VAZIA:{
	      				printf("Lista Vazia.\n");
	      				break;
	      			}
					case PROFESSOR_MATRICULADO:{
	      				printf("O professor com a matrícula digitada está cadastrado em uma disiciplina.\n");
	      				break;
	      			}
					case NAO_ENCONTRADO:{
	      				printf("Não foi encontrado o professor com a matricula digitada.\n");
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
			mainListarProfessor(inicioListaProfessor);
			break;
	  	  }
		  default:{
	      	printf("opcao inválida\n");
	      }
		}
	}
}

int validarCadastroProfessor(Professor* professor){
	int retorno = SUCESSO_CADASTRO;
	
	printf("Digite o nome: ");
    fgets(professor->nome, 50, stdin);
    size_t ln = strlen(professor->nome) - 1;
    if(professor->nome[ln] == '\n')
        professor->nome[ln] = '\0';
    
    printf("Digite o sexo: ");
    scanf("%c", &professor->sexo);
    
    professor->sexo = toupper(professor->sexo);
    if(professor->sexo != 'M' && professor->sexo != 'F') {
        retorno = ERRO_CADASTRO_SEXO;
    }else{
	    printf("Digite a data de nascimento: ");
	    scanf("%s", professor->data_nascimento.dataCompleta);
	    getchar();

	    int dataValida = validar_data(professor->data_nascimento.dataCompleta, &professor->data_nascimento);
	    if(dataValida == FALSE){
	        retorno = ERRO_DATA_INVALIDA;
	    }else{
		    printf("Digite o CPF: ");
		    fgets(professor->cpf, 15, stdin); 
		    ln = strlen(professor->cpf) - 1; 
		    if(professor->cpf[ln] == '\n')
		        professor->cpf[ln] = '\0';
				if (!validarCPF(professor->cpf)) {
					printf("CPF inválido!\n");
					free(professor);
					return ERRO_CPF_INVALIDO;
	    	}
    	}
    }
	return retorno;
}

void inserirProfessorNaLista(Professor** inicioProfessor, Professor* novoProfessor){
    Professor *atual;
    
    if(*inicioProfessor == NULL)
        *inicioProfessor = novoProfessor;
    else{
        atual = *inicioProfessor;

        while(atual->prox != NULL)
            atual = atual->prox;
        
        atual->prox = novoProfessor;
    }
    
    novoProfessor->prox = NULL;
}

int inserirProfessor(Professor** inicioProfessor){
    Professor* novoProfessor = (Professor *)malloc(sizeof(Professor));
    
    printf("\n### Cadastro de Professor ###\n");
    getchar();

	int retorno = validarCadastroProfessor(novoProfessor);

    if(retorno == SUCESSO_CADASTRO){
    	novoProfessor->matricula = geraMatriculaProfessor();
    	inserirProfessorNaLista(inicioProfessor, novoProfessor);
    	return SUCESSO_CADASTRO;
    }else{
    	free(novoProfessor);
    	return retorno;
    }
}

int atualizarProfessorNaLista(Professor** inicioProfessor, int matricula){
	if(*inicioProfessor == NULL)
		return LISTA_VAZIA;

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
		printf("\n### Atualização de Professor ###\n");

		Professor tmp;

		int retorno = validarCadastroProfessor(&tmp);	

		if(retorno == SUCESSO_CADASTRO){
			strcpy(atual->nome, tmp.nome);
        	atual->sexo = tmp.sexo;
        	strcpy(atual->data_nascimento.dataCompleta, tmp.data_nascimento.dataCompleta);
        	strcpy(atual->cpf, tmp.cpf);
		}

		return retorno;
	}else
		return NAO_ENCONTRADO;
}

int atualizarProfessor(Professor** inicioProfessor){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return atualizarProfessorNaLista(inicioProfessor, matricula);
}

int excluirProfessorNaLista(Professor** inicioProfessor, Disciplina** inicioDisciplina, int matricula){
	if(*inicioProfessor == NULL)
		return LISTA_VAZIA;

	Disciplina* atualDisciplina = *inicioDisciplina;
	int achou = FALSE;

	while(atualDisciplina != NULL){
		if(atualDisciplina->matriculaProfessor == matricula){
			achou = TRUE;
			break;
		}
		atualDisciplina = atualDisciplina->prox;
	}

	if(!achou){
		Professor* anterior = *inicioProfessor;
		Professor* atual = *inicioProfessor;
		Professor* proximo = atual->prox;
		int achou = FALSE;

		while(atual != NULL){
			if(atual->matricula == matricula){
				achou = TRUE;
				break;
			}
			anterior = atual;
			atual = proximo;
			if(atual != NULL)
				proximo = atual->prox;
		}

		if(achou){
			if(atual == *inicioProfessor)
				*inicioProfessor = proximo;
			else
				anterior->prox = atual->prox;
			free(atual);
			return SUCESSO_EXCLUSAO;
		}else
			return NAO_ENCONTRADO;
	}else{
		return PROFESSOR_MATRICULADO;
	}
}

int excluirProfessor(Professor** inicioProfessor, Disciplina** inicioDisciplina){
	int matricula;
	printf("Digite a matrícula: ");    
    scanf("%d", &matricula);
    getchar();

	return excluirProfessorNaLista(inicioProfessor, inicioDisciplina, matricula);
}

void listarProfessores(Professor** inicioProfessor){
    Professor* professorAtual = *inicioProfessor;
    if(*inicioProfessor == NULL){
        printf("Lista Vazia\n");
    }else{
    	printf("\n### Professores Cadastrados ####\n");
        do{
            printf("-----\n");
            printf("Matrícula: %d\n", professorAtual->matricula);
            printf("Nome: %s\n", professorAtual->nome);
            printf("Sexo: %c\n", professorAtual->sexo);
            printf("Data Nascimento: %s\n", professorAtual->data_nascimento.dataCompleta);
            printf("CPF: %s\n", professorAtual->cpf);
            
            professorAtual = professorAtual->prox;
        }while (professorAtual != NULL);
    }    
    printf("-----\n\n");

}

void listarProfessoresPorSexo(Professor** inicioProfessor){
    if(*inicioProfessor == NULL){
        printf("Lista Vazia\n");
        return;
    }

    char sexoFiltro;
    printf("Digite o sexo para filtrar (M/F): ");
    scanf(" %c", &sexoFiltro);
    sexoFiltro = toupper(sexoFiltro);

    if(sexoFiltro != 'M' && sexoFiltro != 'F'){
        printf("Sexo inválido! Digite 'M' ou 'F'.\n");
        return;
    }

    int contador = 0;
    Professor* atual = *inicioProfessor;
	while(atual != NULL){
		if (atual->sexo == sexoFiltro){
			contador++;
		}
		atual = atual->prox;
	}

	if(contador == 0){
		printf("Nenhum professor encontrado para o sexo informado.\n");
		return;
	}


    Professor** vetor = (Professor**) malloc(contador * sizeof(Professor*));
    atual = *inicioProfessor;
    int i = 0;

	while(atual != NULL){
		if (atual->sexo == sexoFiltro) {
			vetor[i] = atual;
			i++;
		}
		atual = atual->prox;
	}


	for(int x = 0; x < contador - 1; x++){
		for(int y = x + 1; y < contador; y++){
			if(strcasecmp(vetor[x]->nome, vetor[y]->nome) > 0){
				Professor* temp = vetor[x];
				vetor[x] = vetor[y];
				vetor[y] = temp;
			}
		}
	}

    printf("\n### Professores Cadastrados do Sexo %s (Ordem Alfabética) ###\n", sexoFiltro == 'M' 
			? "Masculino" : "Feminino");

	for(int j = 0; j < contador; j++){
		printf("-----\n");
		printf("Matrícula: %d\n", vetor[j]->matricula);
		printf("Nome: %s\n", vetor[j]->nome);
		printf("Sexo: %c\n", vetor[j]->sexo);
		printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
		printf("CPF: %s\n", vetor[j]->cpf);
	}
    printf("-----\n\n");

	free(vetor);
}

void listarProfessoresPorNome(Professor** inicioProfessor) {
    if (*inicioProfessor == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    int contador = 0;
    Professor* atual = *inicioProfessor;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }


    Professor** vetor = (Professor**) malloc(contador * sizeof(Professor*));
    atual = *inicioProfessor;
    int i = 0;
    while (atual != NULL) {
        vetor[i] = atual;
        i++;
        atual = atual->prox;
    }

    for (int x = 0; x < contador - 1; x++) {
        for (int y = x + 1; y < contador; y++) {
            if (strcasecmp(vetor[x]->nome, vetor[y]->nome) > 0) {
                Professor* temp = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = temp;
            }
        }
    }

    printf("\n### Professores Cadastrados (Ordem Alfabética) ###\n");
    for (int j = 0; j < contador; j++) {
		printf("-----\n");
        printf("Matrícula: %d\n", vetor[j]->matricula);
        printf("Nome: %s\n", vetor[j]->nome);
        printf("Sexo: %c\n", vetor[j]->sexo);
        printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
        printf("CPF: %s\n", vetor[j]->cpf);
    }
	printf("-----\n\n");

    free(vetor);
}

void listarProfessoresPorData(Professor** inicioProfessor){
	if(*inicioProfessor == NULL){
		printf("Lista Vazia\n");
		return;
	}

	int contador = 0;
	Professor* atual = *inicioProfessor;
	while(atual != NULL){
		contador++;
		atual = atual->prox;
	}

	Professor** vetor = (Professor**) malloc(contador * sizeof(Professor*));
	atual = *inicioProfessor;
	int i = 0;

	while(atual != NULL){
		vetor[i] = atual;
		i++;
		atual = atual->prox;
	}

	for(int x = 0; x < contador - 1; x++){
		for(int y = x + 1; y < contador; y++){
			if(compararDatas(&vetor[x]->data_nascimento, &vetor[y]->data_nascimento) > 0){
				Professor* temp = vetor[x];
				vetor[x] = vetor[y];
				vetor[y] = temp;
			}
		}
	}

	printf("\n### Professores Cadastrados (em Ordem de Data de Nascimento) ###\n");
	for(int j = 0; j < contador; j++){
		printf("-----\n");
		printf("Matrícula: %d\n", vetor[j]->matricula);
		printf("Nome: %s\n", vetor[j]->nome);
		printf("Sexo: %c\n", vetor[j]->sexo);
		printf("Data Nascimento: %s\n", vetor[j]->data_nascimento.dataCompleta);
		printf("CPF: %s\n", vetor[j]->cpf);
	}
	printf("-----\n\n");
		
	free(vetor);
}

int compararDatas(Data* data1, Data* data2){
	if(data1->ano != data2->ano){
		return data1->ano - data2->ano;
	}else if (data1->mes != data2->mes){
		return data1->mes - data2->mes;
	}else{
		return data1->dia - data2->dia;
	}
}

void liberarListaProfessor(Professor* inicioProfessor){
	Professor* atual = inicioProfessor;
	Professor* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}