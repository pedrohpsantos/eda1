#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *Q3(int *M, char *NC)
{
    int n;
    char *code = (char *)malloc(9 * sizeof(char));
    for (int i = 0; i < 9; i++)
    {
        code[8 - i] = NC[M[i]];
        if (code[8 - i] == ' ')
            code[8 - i] = '-';
    }
    return code;
}

int main()
{
    char matricula[12], nome[100];
    int M[9];
    printf("Digite sua matricula: ");
    scanf("%s", matricula);

    for (int i = 0; i < 9; i++)
    {
        M[i] = matricula[i] - '0';
    }

    getchar();

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    char *codigo = Q3(M, nome);
    printf("Resposta: %s\n", codigo);
    free(codigo);
    return 0;
}