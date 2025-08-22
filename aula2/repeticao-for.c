#include <stdio.h>

int main() {
    int i;

    // 1. Demonstração de contagem crescente (1 até 5)
    printf("\n=== Contagem Ascendente (1-5) ===\n");
    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 2. Demonstração de contagem decrescente (10 até 1)
    printf("=== Contagem Descendente (10-1) ===\n");
    for (i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 3. Demonstração de números pares (2 até 10)
    printf("=== Números Pares (2-10) ===\n");
    for (i = 2; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}