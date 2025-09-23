#include <stdio.h>

int main() {
  // Declaração das variáveis
  // Variáveis inteiras
  int a = 10; // Primeiro número inteiro
  int b = 5;  // Segundo número inteiro

  // Variáveis de ponto flutuante
  float c = 15.5; // Primeiro número decimal
  float d = 2.5;  // Segundo número decimal

  // === Operações com números inteiros ===
  printf("\n=== Demonstração de Operações com Inteiros ===\n");
  printf("Usando os números: a = %d e b = %d\n\n", a, b);

  // Operações básicas com inteiros
  printf("Adição:      %d + %d = %d\n", a, b, a + b);
  printf("Subtração:   %d - %d = %d\n", a, b, a - b);
  printf("Multiplicação:%d * %d = %d\n", a, b, a * b);
  printf("Divisão:     %d / %d = %d\n", a, b, a / b); // Note: divisão inteira

  // === Operações com números decimais ===
  printf("\n=== Demonstração de Operações com Decimais ===\n");
  printf("Usando os números: c = %.2f e d = %.2f\n\n", c, d);

  // Operações básicas com floats
  printf("Adição:       %.2f + %.2f = %.2f\n", c, d, c + d);
  printf("Subtração:    %.2f - %.2f = %.2f\n", c, d, c - d);
  printf("Multiplicação: %.2f * %.2f = %.2f\n", c, d, c * d);
  printf("Divisão:      %.2f / %.2f = %.2f\n", c, d, c / d);

  return 0;
}
