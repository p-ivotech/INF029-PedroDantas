# 🏫 Sistema de Gestão Escolar — CRUD em C

Sistema de gerenciamento escolar desenvolvido em C com arquitetura modular. Permite o cadastro e controle de alunos, professores e disciplinas, com validações de dados e relacionamento entre entidades.

## 🖥️ Funcionalidades

- **Alunos:** cadastrar, excluir (soft delete), atualizar e listar (geral ou por sexo)
- **Professores:** cadastrar, excluir (soft delete), atualizar e listar (geral ou por sexo)
- **Disciplinas:** cadastrar, excluir, atualizar, vincular a um professor e matricular/remover alunos
- **Listagens:** visualizar todos os alunos e professores de uma disciplina com seus dados completos
- **Validações:** matrícula única, CPF com verificação de dígitos, data de nascimento com suporte a anos bissextos, sexo (M/F)

## 🛠️ Tecnologias

- **Linguagem:** C (C99)
- **Arquitetura:** modular com separação em headers (`.h`) e implementações (`.c`)
- **Compilador:** GCC

## ▶️ Como compilar e executar

```bash
gcc escola.c aluno.c professores.c disciplina.c utilidades.c -o escola
./escola
```

## 📁 Estrutura do projeto

```
projeto escola/
├── escola.c          # Main e menus
├── aluno.c / .h      # CRUD de alunos
├── professores.c / .h  # CRUD de professores
├── disciplina.c / .h   # CRUD de disciplinas
├── utilidades.c / .h   # Validações e funções auxiliares
└── dados.h           # Definição das structs (Dados, Disciplina, Data)
```

## 🧩 Modelo de dados

```c
typedef struct {
    int ativo;          // Soft delete
    char cpf[14];
    char nome[100];
    char sexo;
    int matricula;
    Data nascimento;
} Dados;  // Usado tanto para Alunos quanto Professores

typedef struct {
    char nome[50];
    char codigo[12];
    int semestre;
    int matriculaProfessor;
    int alunos[50];
    int qtdAlunos;
} Disciplina;
```
