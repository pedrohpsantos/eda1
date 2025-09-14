#include <stdio.h>

int main() {
  // Declaração e inicialização das variáveis
  int a = 5;
  int b = 10;

  // Cabeçalho do programa
  printf("\n=== Demonstração de Operadores Lógicos ===\n");
  printf("Comparando: a = %d e b = %d\n\n", a, b);

  // Operadores de comparação
  printf("1. Operadores de Menor e Maior:\n");
  printf("   a < b:  %d (Menor que)\n", a < b);   // Retorna 1 se verdadeiro
  printf("   a > b:  %d (Maior que)\n\n", a > b); // Retorna 0 se falso

  printf("2. Operadores de Menor/Maior ou Igual:\n");
  printf("   a <= b: %d (Menor ou igual)\n", a <= b); // Retorna 1 se verdadeiro
  printf("   a >= b: %d (Maior ou igual)\n\n", a >= b); // Retorna 0 se falso

  printf("3. Operadores de Igualdade:\n");
  printf("   a == b: %d (Igual a)\n", a == b);      // Retorna 1 se igual
  printf("   a != b: %d (Diferente de)\n", a != b); // Retorna 1 se diferente

  printf("\n=== Observações ===\n");
  printf("► 1 significa VERDADEIRO\n");
  printf("► 0 significa FALSO\n");

  return 0;
}