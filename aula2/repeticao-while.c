#include <stdio.h>

int main() {
    int i;

    // 1. Demonstração de contagem crescente (1 até 5)
    printf("\n=== Contagem Ascendente (1-5) ===\n");
    i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i++;
    }
    printf("\n\n");

    // 2. Demonstração de contagem decrescente (10 até 1)
    printf("=== Contagem Descendente (10-1) ===\n");
    i = 10;
    while (i >= 1) {
        printf("%d ", i);
        i--;
    }
    printf("\n\n");

    // 3. Demonstração de números pares (2 até 10)
    printf("=== Números Pares (2-10) ===\n");
    i = 2;
    while (i <= 10) {
        printf("%d ", i);
        i += 2;  // Incrementa de 2 em 2 para obter números pares
    }
    printf("\n");

    return 0;
}