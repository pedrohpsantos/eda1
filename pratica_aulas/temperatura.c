#include <stdio.h>

int main()
{

    char opc;
    do
    {
        printf("C - Fahrenheit para Celsius, F - Celsius para Fahrenheit e S - Sair: ");
        scanf(" %c", &opc);
        switch (opc)
        {
        case 'C':
            double f;
            printf("Digite o valor em Fahrenheit: ");
            scanf("%lf", &f);
            printf("Temperatura em Celsius: %.1lf\n", (f - 32) / 1.8);
            break;

        case 'F':
            double c;
            printf("Digite o valor em Celsius: ");
            scanf("%lf", &c);
            printf("Temperatura em Fahrenheit: %.1lf\n", (c * 1.8) + 32);
            break;

        case 'S':
            printf("Programa encerrado");
            break;

        default:
            printf("Opcao invalida");
            break;
        }

    } while (opc != 'S');

    return 0;
}