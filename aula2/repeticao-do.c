#include <stdio.h>

int main()
{
    int i;

    // 1. Contagem ascendente de 1 até 5
    printf("\n=== Contagem Ascendente (1-5) ===\n");
    i = 1;
    do
    {
        printf("%d ", i++);
    } while (i <= 5);
    printf("\n");

    // 2. Contagem descendente de 10 até 1
    printf("\n=== Contagem Descendente (10-1) ===\n");
    i = 10;
    do
    {
        printf("%d ", i--);
    } while (i >= 1);
    printf("\n");

    // 3. Números pares de 2 até 10
    printf("\n=== Números Pares (2-10) ===\n");
    i = 2;
    do
    {
        printf("%d ", i);
        i += 2; // Incrementa de 2 em 2 para obter números pares
    } while (i <= 10);
    printf("\n");

    return 0;
}