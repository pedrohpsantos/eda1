#include <stdio.h>

// Função recursiva para calcular o MDC
int MDC(int a, int b) {
    // Caso Base: se b for 0, o MDC é a
    if (b == 0) {
        return a;
    }
    // Passo Recursivo: chama a função com b e o resto de a por b
    return MDC(b, a % b);
}

int main() {
    int num1, num2, resultado;

    printf("Digite dois numeros inteiros para calcular o MDC: ");
    scanf("%d %d", &num1, &num2);

    resultado = MDC(num1, num2);

    printf("MDC de %d e %d = %d\n", num1, num2, resultado);

    return 0;
}