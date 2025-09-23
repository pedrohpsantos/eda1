#include <stdio.h>

int main() {
  // Declaração da variável para armazenar a idade
  int idade;

  // Cabeçalho do programa
  printf("\n=== Verificador de Faixa Etária ===\n\n");

  // Solicita a idade ao usuário
  printf("Por favor, digite sua idade: ");
  scanf("%d", &idade);

  // Validação da entrada
  if (idade < 0 || idade > 150) {
    printf("\nErro: Idade inválida! A idade deve estar entre 0 e 150 anos.\n");
    return 1; // Retorna erro
  }

  // Estrutura condicional para determinar a faixa etária
  printf("\nResultado da verificação:\n");
  if (idade < 13) {
    printf("► Você é uma criança (0-12 anos).\n");
    printf("► Fase de desenvolvimento e descobertas.\n");
  } else if (idade < 18) {
    printf("► Você é um adolescente (13-17 anos).\n");
    printf("► Fase de transformações e aprendizado.\n");
  } else if (idade < 60) {
    printf("► Você é um adulto (18-59 anos).\n");
    printf("► Fase de responsabilidades e realizações.\n");
  } else {
    printf("► Você é um idoso (60+ anos).\n");
    printf("► Fase de experiência e sabedoria.\n");
  }

  printf("\n=== Fim da verificação ===\n");
  return 0;
}
