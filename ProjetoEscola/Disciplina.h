typedef struct dados_professor Professor;
typedef struct dados_aluno Aluno;

typedef struct dados_disciplina{
    
  char nome[50];
  int codigo;
  int semestre;
  int matriculaProfessor;
  int matriculaAluno[100];
  int qtdAlunos;
  struct dados_disciplina *prox;
    
} Disciplina;

void mainDisciplina(Disciplina** inicio, Professor** inicioProfessor, Aluno** inicioaAluno);
void liberarListaDisciplina(Disciplina* inicio);