#include <stdio.h>

int main()
{
  // Criamos uma variável comum, como uma "caixa" para guardar um número.
  int numero = 79417;

  // O asterisco (*) indica que 'ptr' não é uma caixa para um número, mas sim
  // para um "endereço de um número inteiro".
  int *ptr;

  // O '&' significa "endereço de". Estamos dizendo: "ponteiro ptr, guarde o
  // endereço da variável numero".
  ptr = &numero;

  printf("--- Informacoes Basicas ---\n");
  printf("Valor do ponteiro 'ptr' (ele guarda o endereco): %p\n\n", ptr);

  // Usamos o asterisco (*) de novo, mas agora ele significa "o valor apontado
  // por".
  printf("--- Acessando o valor atraves do ponteiro ---\n");
  printf("Valor apontado por 'ptr': %d\n\n", *ptr);

  // Você pode inclusive modificar o valor original usando o ponteiro!
  printf("--- Modificando o valor atraves do ponteiro ---\n");
  printf("Valor original de 'numero': %d\n", numero);

  *ptr = 90560; // "Vá até o endereço que você aponta e mude o valor para 90560"

  printf("Novo valor de 'numero' apos a modificacao: %d\n", numero);

  free(ptr);

  return 0;
}
