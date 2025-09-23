#include <stdio.h>

int main() {

  int valor, divisao, resto;
  scanf("%d", &valor);
  printf("%d\n", valor);

  divisao = valor / 100;
  resto = valor % 100;
  valor = resto;
  printf("%d nota(s) de R$ 100,00\n", divisao);

  divisao = valor / 50;
  resto = valor % 50;
  valor = resto;
  printf("%d nota(s) de R$ 50,00\n", divisao);

  divisao = valor / 20;
  resto = valor % 20;
  valor = resto;
  printf("%d nota(s) de R$ 20,00\n", divisao);

  divisao = valor / 10;
  resto = valor % 10;
  valor = resto;
  printf("%d nota(s) de R$ 10,00\n", divisao);

  divisao = valor / 5;
  resto = valor % 5;
  valor = resto;
  printf("%d nota(s) de R$ 5,00\n", divisao);

  divisao = valor / 2;
  resto = valor % 2;
  valor = resto;
  printf("%d nota(s) de R$ 2,00\n", divisao);

  divisao = valor / 1;
  resto = valor % 1;
  printf("%d nota(s) de R$ 1,00\n", divisao);

  return 0;
}
