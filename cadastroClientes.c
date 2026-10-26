#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 3


typedef struct dados {
    char nome[50];
    char cpf[12];
    long int telefone;
    int ID;
} Pessoa;

void cadastroClientes (Pessoa *clientes,int qtdClientes){
    Pessoa *novo = clientes; 
    novo[qtdClientes].ID = qtdClientes + 1;
    printf("\nDigite o nome do cliente: ");
    fgets(novo[qtdClientes].nome,50,stdin);
    printf("\nDigite o CPF do cliente: ");
    fgets(novo[qtdClientes].cpf,12,stdin);
    printf("\nDigite o telefone do Cliente: ");
    scanf("%ld",&novo[qtdClientes].telefone);
}

void inicializar (Pessoa *clientes){
    for(int i=0;i<TAM;i++){
        clientes[i].cpf == NULL;
        clientes[i].nome == NULL;
        clientes[i].ID = 1;
        clientes[i].telefone = 000000000;
    }
}

int main(){
    //teste referente a criação das pessoas da loja (cliente e vendedor)

    int qtdClientes = 0;     
    Pessoa *clientes = malloc(TAM * sizeof(Pessoa));
    inicializar(clientes);
    cadastroClientes(clientes,qtdClientes);
    qtdClientes++;
    printf("%d\n",clientes[0].ID);
    printf("%s\n",clientes[0].nome);
    printf("%s\n",clientes[0].cpf);
    printf("%ld\n",clientes[0].telefone);

return 0;
}