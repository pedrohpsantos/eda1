#include <stdio.h>
#include <string.h>

typedef struct
{
    char nomeAluno[100];
    int matriculaAluno;
} Aluno;

int main()
{

    Aluno aluno;

    strcpy(aluno.nomeAluno, "Pedro Henrique");
    aluno.matriculaAluno = 231025566;

    printf("Dados do aluno\n");
    printf("Nome do aluno: %s\n", aluno.nomeAluno);
    printf("Matricula do aluno: %d\n", aluno.matriculaAluno);

    aluno.matriculaAluno++;
    printf("\nA matricula do proximo aluno sera: %d\n", aluno.matriculaAluno);

    return 0;
}