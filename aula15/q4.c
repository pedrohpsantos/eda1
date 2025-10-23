#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Verifica(char c)
{
    return (c >= 'a' && c <= 'z');
}

int Q4(char *NC, char L, int pos)
{
    if (NC[0] == '\0' || pos < 0 || pos >= strlen(NC) - 1)
    {
        return -1;
    }
    if (NC[pos] == L && Verifica(NC[pos + 1]))
    {
        return pos;
    }
    return Q4(NC, L, pos + 1);
}

int main()
{
    char NC[100];
    char L;
    int pos = 0;

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(NC, sizeof(NC), stdin);
    NC[strcspn(NC, "\n")] = 0;

    printf("Digite a ultima letra do ultimo sobrenome em letras minusculas:\n");
    scanf(" %c", &L);

    int resultado = Q4(NC, L, pos);
    printf("Resposta: %d\n", resultado);

    return 0;
}