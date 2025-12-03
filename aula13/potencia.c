#include <stdio.h>

// Função recursiva para calcular Potência (base^k)
long int Potencia(int base, int k) {
    // Caso Base: qualquer número elevado a 0 é 1
    if (k == 0) {
        return 1;
    }
    // Passo Recursivo: base * resultado da potência com expoente anterior
    return base * Potencia(base, k - 1);
}

int main() {
    int b, e;
    long int resultado;

    printf("Digite a base: ");
    scanf("%d", &b);

    printf("Digite o expoente (positivo): ");
    scanf("%d", &e);

    if (e < 0) {
        printf("Por favor, digite um expoente nao-negativo.\n");
    } else {
        resultado = Potencia(b, e);
        printf("%d elevado a %d = %ld\n", b, e, resultado);
    }

    return 0;
}