#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Q8(char *Nome, char *NC)
{
    int total = 0;
    char caractere, *ptr;
    while (*Nome != '\0')
    {
        caractere = *Nome;
        ptr = (char *)NC;
        while (*ptr != '\0')
        {
            if (*ptr == caractere)
                total++;
            ptr++;
        }
        Nome++;
    }
    return total;
}

int main()
{
    char Nome[50];
    char NC[100];

    printf("Digite seu primeiro nome em letras minusculas:\n");
    scanf("%s", Nome);

    getchar();

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(NC, sizeof(NC), stdin);
    NC[strcspn(NC, "\n")] = 0;

    int resultado = Q8(Nome, NC);
    printf("Resposta: %d\n", resultado);

    return 0;
}