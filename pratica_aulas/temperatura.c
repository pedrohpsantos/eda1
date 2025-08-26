#include <stdio.h>

int main()
{

    char opc;
    printf("C - Fahrenheit para Celsius, F - Celsius para Fahrenheit e S - Sair");
    scanf("%c", &opc);
    switch (opc)
    {
    case 'C':

        break;

    case 'F':

        break;

    case 'S':
        printf("Programa encerrado");
        break;

    default:
        printf("Opcao invalida");
        break;
    }

    return 0;
}