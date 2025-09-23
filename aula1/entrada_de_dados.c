#include <stdio.h>

int main() {
  // Declaração das variáveis para armazenar os dados
  int idade;     // Armazena a idade como número inteiro
  float altura;  // Armazena a altura como número decimal
  char nome[50]; // Armazena até 49 caracteres + terminador nulo

  // Título do programa
  printf("\n=== Demonstração de Entrada de Dados ===\n\n");

  // Lendo uma string (texto)
  printf("Digite seu nome: ");
  scanf("%s", nome); // Não precisa & para strings

  // Lendo um número inteiro
  printf("Digite sua idade: ");
  scanf("%d", &idade); // Note o & antes da variável

  // Lendo um número decimal
  printf("Digite sua altura (em metros): ");
  scanf("%f", &altura); // Note o & antes da variável

  // Mostrando os dados lidos
  printf("\n=== Dados Inseridos ===\n");
  printf("Nome: %s\n", nome);
  printf("Idade: %d anos\n", idade);
  printf("Altura: %.2f metros\n", altura);

  return 0;
}
