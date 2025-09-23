#include <stdio.h>

int main() {
  // Demonstração dos tipos básicos de dados em C

  // 1. Tipos de caracteres
  char caractere = 'A';      // Armazena um único caractere (-128 a 127)
  unsigned char uchar = 200; // Caractere sem sinal (0 a 255)

  // 2. Tipos inteiros
  int inteiro = 42;         // Número inteiro com sinal
  unsigned int uint = 1000; // Número inteiro sem sinal (sempre positivo)

  // 3. Tipos de ponto flutuante
  float pontoFlutuante = 3.14; // Número decimal com precisão simples
  double duplo = 12345.6789;   // Número decimal com precisão dupla

  // Imprimindo os valores com descrições detalhadas
  printf("\n=== Demonstração de Tipos de Dados em C ===\n\n");

  // Exibindo tipos de caracteres
  printf("=== Tipos de Caracteres ===\n");
  printf("char (caractere): %c (valor ASCII: %d)\n", caractere, caractere);
  printf("unsigned char: %u\n\n", uchar);

  // Exibindo tipos inteiros
  printf("=== Tipos Inteiros ===\n");
  printf("int (inteiro): %d\n", inteiro);
  printf("unsigned int: %u\n\n", uint);

  // Exibindo tipos de ponto flutuante
  printf("=== Tipos de Ponto Flutuante ===\n");
  printf("float (6 casas decimais): %.6f\n", pontoFlutuante);
  printf("double (10 casas decimais): %.10lf\n", duplo);

  return 0;
}
