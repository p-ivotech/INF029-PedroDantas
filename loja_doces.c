#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAM 3

typedef struct produto {
    float valor;
    char nome[50];
    char ingredientes[100];
    float peso;
    int quantidade;
    int codigo;
} Produto;

typedef struct dados {
    char nome[50];
    char cpf[12];
    long int telefone;
    int ID;
} Pessoa;

void listarClientes(Pessoa *clientes,int qtdClientes);
void listarVendedores(Pessoa *vendedores,int qtdVendedores);
void listarDoces(Produto *doce,int qtdDoces);
void listarDocesCardapio(Produto *doce,int qtdDoces);

int menuInicial(){
    int opcao;
    printf("\n\t=========MENU=========\t\n");
    printf("\tEscolha uma da opcoes abaixo:\t\n");
    printf("\t1. Cardapio\t\n");
    printf("\t2. Cadastro Geral\t\n");
    printf("\t3. Gerar Pedido\t\n");
    printf("\t4. Relatorios\t\n");
    printf("\t0. Sair\t\n");
    scanf("%d",&opcao);
    return opcao;
}

int validarOpcaoMenu(int opcao){
    if (opcao < 0 || opcao > 4){
        printf("\nOpcao Invalida!! Digite uma opcao correta.");
        return 1;
    } else {
        return 0;
    }
}

int menuCadastros(){
    int opcao;
    printf("\n\t=========CADASTRO GERAL=========\t\n");
    printf("\t1. Cadastro dos Doces do Cardapio\t\n");
    printf("\t2. Cadastro dos Vendedores\t\n");
    printf("\t3. Cadastro dos Clientes\t\n");
    printf("\t0. Sair\t\n");
    scanf("%d",&opcao);
    return opcao;
}

int menuRelatorio(){
    int opcao;
    printf("\n\t=========RELATORIOS=========\t\n");
    printf("\t1. Listar Clientes\t\n");
    printf("\t2. Listar Vendedores\t\n");
    printf("\t3. Listar Doces\t\n");
    printf("\t0. Sair\t\n");
    scanf("%d",&opcao);
    return opcao;
}

int validarOpcaoCadastro(int opcao){
    if (opcao < 0 || opcao > 3){
        printf("\nOpcao Invalida!! Digite uma opcao correta.");
        return 1;
    } else {
        return 0;
    }
}

int validarOpcaoRelatorios(int opcao){
    if (opcao < 0 || opcao > 3){
        printf("\nOpcao Invalida!! Digite uma opcao correta.");
        return 1;
    } else {
        return 0;
    }
}

int validarOpcaoAtualizacao(int opcao){
    if (opcao < 0 || opcao > 5){
        printf("\nOpcao Invalida!! Digite uma opcao correta.");
        return 1;
    } else {
        return 0;
    }
}

int menuAtualizacao(){
    int opcao;
    printf("\n\t=========ATUALIZACAO=========\t\n");
    printf("\tEscolha uma da opcoes abaixo:\t\n");
    printf("\t1. Nome\t\n");
    printf("\t2. Ingredientes\t\n");
    printf("\t3. Valor\t\n");
    printf("\t4. Peso\t\n");
    printf("\t5. Saldo\t\n");
    printf("\t0. Sair\t\n");
    scanf("%d",&opcao);
    return opcao;
}

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

void cadastroVendedores (Pessoa *vendedores,int qtdVendedores){
    Pessoa *novo = vendedores; 
    novo[qtdVendedores].ID = qtdVendedores + 1;
    printf("\nDigite o nome do vendedor: ");
    fgets(novo[qtdVendedores].nome,50,stdin);
    printf("\nDigite o CPF do vendedor: ");
    fgets(novo[qtdVendedores].cpf,12,stdin);
    printf("\nDigite o telefone do vendedor: ");
    scanf("%ld",&novo[qtdVendedores].telefone);
}

void cadastroDoces (Produto *doce,int qtdDoces){
    Produto *novo = doce;
    getchar();
    printf("\nDigite o nome do doce: ");
    fgets(novo[qtdDoces].nome,50,stdin);
    printf("\nDigite os ingredientes presentes na receita: ");
    fgets(novo[qtdDoces].ingredientes,100,stdin);
    printf("\nDigite o valor do doce: ");
    scanf("%f",&novo[qtdDoces].valor);
    printf("\nDigite o peso em gramas (g): ");
    scanf("%f",&novo[qtdDoces].peso);
    printf("\nInclusão Saldo Inicial: ");
    scanf("%d",&novo[qtdDoces].quantidade);
    novo[qtdDoces].codigo = qtdDoces + 1;
}

void inicializar (Pessoa *clientes){
    for(int i=0;i<TAM;i++){
        clientes[i].cpf == NULL;
        clientes[i].nome == NULL;
        clientes[i].ID = 1;
        clientes[i].telefone = 000000000;
    }
}

void inicializarDoce (Produto *doce){
    for(int i=0;i<TAM;i++){
        doce[i].ingredientes == NULL;
        doce[i].nome == NULL;
        doce[i].peso = 0;
        doce[i].quantidade = 0;
        doce[i].valor = 0;
        doce[i].codigo = 0;
    }
}

int main(){

    int qtdClientes = 0; //quantitativo de clientes
    Pessoa *clientes = malloc(TAM * sizeof(Pessoa));
    inicializar(clientes);

    int qtdVendedores = 0; //quantitativo de clientes
    Pessoa *vendedores = malloc(TAM * sizeof(Pessoa));
    inicializar(vendedores);

    int qtdDoces = 0; //quantitativo de clientes
    Produto *doce = malloc(TAM * sizeof(Produto));
    inicializarDoce(doce);

    int opcaoMenu = -1;
    while(opcaoMenu != 0){
        int opcaoMenu = menuInicial();
        if (validarOpcaoMenu(opcaoMenu) != 0){
            opcaoMenu = menuInicial();
        }
        switch(opcaoMenu){ 
            case 0:
                printf("Saindo...");
                return 0;
            break;
            case 1:
                listarDocesCardapio(doce,qtdDoces);
            break;
            case 2:
                int opcaoCadastro = menuCadastros(); //fazer validação da opcao do Cadastro
                if(validarOpcaoCadastro(opcaoCadastro) != 0){
                    opcaoCadastro = menuCadastros();
                }
                    switch(opcaoCadastro){ 
                        case 0:
                            printf("Saindo do Cadastro...");
                        break;
                        case 1:
                            cadastroDoces(doce,qtdDoces);
                            qtdDoces++;
                        break;
                        case 2:
                            getchar();
                            cadastroVendedores(vendedores,qtdVendedores);
                            qtdVendedores++;
                        break;
                        case 3:
                            getchar();
                            cadastroClientes(clientes,qtdClientes);
                            qtdClientes++;
                        break;
                    }
            break;
            case 3:
                printf("Gerar pedido");
            break;
            case 4:
                int opcaoRelatorio = menuRelatorio();
                if(validarOpcaoRelatorios(opcaoRelatorio) != 0){
                    opcaoRelatorio = menuRelatorio();
                }
                switch(opcaoRelatorio){ 
                        case 0:
                            printf("Saindo do Cadastro...");
                        break;
                        case 1:
                            printf("Listando...");
                            listarClientes(clientes,qtdClientes);
                        break;
                        case 2:
                            printf("Listando...");
                            listarVendedores(vendedores,qtdVendedores);
                        break;
                        case 3:
                            printf("Listando...");
                            listarDoces(doce,qtdDoces);
                }
            break;
        }
    }
return 0;
}

void listarClientes(Pessoa *clientes,int qtdClientes){
    for(int i = 0; i<qtdClientes;i++){
    printf("\t===\tCLIENTE %d\t===\t",i+1);
    printf("\nID: %d\n",clientes[i].ID);
    printf("Nome: %s\n",clientes[i].nome);
    printf("CPF: %s\n",clientes[i].cpf);
    printf("Telefone: %ld\n",clientes[i].telefone);
    }
}

void listarVendedores(Pessoa *vendedores,int qtdVendedores){
    for(int i = 0; i<qtdVendedores;i++){
    printf("\t===\tCLIENTE %d\t===\t",i+1);
    printf("\nID: %d\n",vendedores[i].ID);
    printf("Nome: %s\n",vendedores[i].nome);
    printf("CPF: %s\n",vendedores[i].cpf);
    printf("Telefone: %ld\n",vendedores[i].telefone);
    }
}

void listarDoces(Produto *doce,int qtdDoces){
    for(int i=0;i<qtdDoces;i++){
        printf("\t===\tCARDAPIO %d\t===\t",i+1);
        printf("\nCodigo: %f",doce[i].codigo);
        printf("\nDoce: %s",doce[i].nome);
        printf("\nIngredientes: %s",doce[i].ingredientes);
        printf("\nPeso: %f",doce[i].peso);
        printf("\nValor: %f",doce[i].valor);
        printf("\nQuantidade Disponivel: %d\n",doce[i].quantidade);
    }
}

void listarDocesCardapio(Produto *doce,int qtdDoces){
    for(int i=0;i<qtdDoces;i++){
        if (doce[i].quantidade > 0){
        printf("\t===CARDAPIO %d\t===\t",i+1);
        printf("\nCodigo: %f",doce[i].codigo);
        printf("\nDoce: %s",doce[i].nome);
        printf("\nIngredientes: %s",doce[i].ingredientes);
        printf("\nPeso: %f",doce[i].peso);
        printf("\nValor: %f",doce[i].valor);
        printf("\nQuantidade Disponivel: %d\n",doce[i].quantidade);
        }
    }
}

void atualizarDoce(Produto *doce, int qtdDoces){
    int codigo;
    printf("Digite o codigo do produto que deseja atualizar: ");
    scanf("%d",&codigo);

        for (int i = 0;i < qtdDoces;i++){
            if(codigo = doce[qtdDoces].codigo){
                int opcaoAtualizar = -2;
                while(opcaoAtualizar != 0){
                int opcaoAtualizar = menuAtualizacao(); //fazer validação da opcao do Cadastro
                if(validarOpcaoAtualizacao(opcaoAtualizar) != 0){
                    opcaoAtualizar = menuAtualizacao();
                }
                switch(opcaoAtualizar){
                    case 0:
                        printf("\nVoltando... ");
                        opcaoAtualizar = -2;
                    break;
                    case 1:
                        printf("\nDigite o novo nome do doce: ");
                        fgets(doce[qtdDoces].nome,50,stdin);
                    break;
                    case 2:
                        printf("\nDigite os novos ingredientes do doce: ");
                        fgets(doce[qtdDoces].ingredientes,100,stdin);
                    break;
                    case 3:
                        printf("\nDigite o novo valor do doce: ");
                        scanf("%f",&doce[qtdDoces].valor);
                    break;
                    case 4:
                        printf("\nDigite o novo peso em gramas (g): ");
                        scanf("%f",&doce[qtdDoces].peso);
                    break;
                    case 5:
                        printf("\nInclusão Saldo Inicial: ");
                        scanf("%d",&doce[qtdDoces].quantidade);
                    break;
                }
            }
            } else {
                printf("Doce nao cadastrado!! Digite um codigo valido");
            }
        }
}
