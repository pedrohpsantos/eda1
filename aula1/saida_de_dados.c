#include <stdio.h>

int main() {
  // Declaração e inicialização das variáveis
  int num = 5;        // Número inteiro
  float pi = 3.14159; // Número com ponto flutuante
  char letra = 'A';   // Caractere único

  // Cabeçalho do programa
  printf("\n=== Demonstração de Saída de Dados em C ===\n\n");

  // Exemplos de saída com diferentes tipos de dados
  printf("1. Número Inteiro:\n");
  printf("   Valor: %d\n", num);
  printf("   Formato hexadecimal: %X\n", num);
  printf("   Formato octal: %o\n\n", num);

  printf("2. Número com Ponto Flutuante:\n");
  printf("   Valor normal: %f\n", pi);
  printf("   Com 2 casas decimais: %.2f\n", pi);
  printf("   Notação científica: %e\n\n", pi);

  printf("3. Caractere:\n");
  printf("   Caractere: %c\n", letra);
  printf("   Valor ASCII: %d\n", letra);

  // Exemplo de formatação com múltiplas variáveis
  printf("\n4. Combinando diferentes tipos:\n");
  printf("   Número %d, PI = %.2f e Letra '%c'\n", num, pi, letra);

  printf("\n=== Fim da Demonstração ===\n");

  return 0;
}