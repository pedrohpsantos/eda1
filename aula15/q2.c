#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Q2(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] < str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main()
{
    char nome[10];
    printf("Coloque seu primeiro nome em letras minusculas: ");
    scanf("%9s", nome);
    Q2(nome);
    printf("Resposta: %s\n", nome);
    return 0;
}