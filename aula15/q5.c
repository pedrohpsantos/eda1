#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long Q5(char *NC, int R)
{
    long r;
    FILE *A = fopen("Saida.txt", "w");
    for (int i = 0; i < R; i++)
        fprintf(A, "[%s]", NC);
    fclose(A);
    A = fopen("Saida.txt", "r");
    fseek(A, 0, SEEK_END);
    r = ftell(A); // Posição do ponteiro.
    fclose(A);
    remove("Saida.txt");
    return r;
}

int main()
{
    char NC[100];
    char matricula[16];
    int R, len;

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(NC, sizeof(NC), stdin);
    NC[strcspn(NC, "\n")] = 0;

    printf("Digite sua matricula:\n");
    scanf("%s", matricula);

    len = strlen(matricula);
    R = (matricula[len - 1] - '0') + 5;

    long resultado = Q5(NC, R);
    printf("Resposta: %ld\n", resultado);

    return 0;
}