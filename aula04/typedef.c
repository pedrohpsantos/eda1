#include <stdio.h>
#include <string.h>

// Modelo de estrutura com um "apelido" (typedef)
typedef struct {
  char nomeAluno[100];
  int matriculaAluno;
} Aluno;

int main() {
  // Inicializando uma variável do tipo "Aluno" (Apelido da estrutura)
  Aluno aluno;

  // Adicionando valores na variável
  strcpy(aluno.nomeAluno, "Pedro Henrique");
  aluno.matriculaAluno = 231025566;

  // Imprimindo os valores
  printf("Dados do aluno\n");
  printf("Nome do aluno: %s\n", aluno.nomeAluno);
  printf("Matricula do aluno: %d\n", aluno.matriculaAluno);

  // Incrementando e imprimindo a variável
  aluno.matriculaAluno++;
  printf("\nA matricula do proximo aluno sera: %d\n", aluno.matriculaAluno);

  return 0;
}
