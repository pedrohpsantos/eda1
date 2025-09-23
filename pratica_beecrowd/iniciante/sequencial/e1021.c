#include <stdio.h>

int main() {

  double valor_decimal;
  int notas, moedas, resto;
  scanf("%lf", &valor_decimal);

  notas = (int)valor_decimal;
  moedas = (int)((valor_decimal - notas) * 100);

  printf("NOTAS:\n");

  printf("%d nota(s) de R$ 100.00\n", notas / 100);
  resto = notas % 100;

  printf("%d nota(s) de R$ 50.00\n", resto / 50);
  resto %= 50;

  printf("%d nota(s) de R$ 20.00\n", resto / 20);
  resto %= 20;

  printf("%d nota(s) de R$ 10.00\n", resto / 10);
  resto %= 10;

  printf("%d nota(s) de R$ 5.00\n", resto / 5);
  resto %= 5;

  printf("%d nota(s) de R$ 2.00\n", resto / 2);
  resto %= 2;

  printf("MOEDAS:\n");

  printf("%d moeda(s) de R$ 1.00\n", resto);

  printf("%d moeda(s) de R$ 0.50\n", moedas / 50);
  resto = moedas % 50;

  printf("%d moeda(s) de R$ 0.25\n", resto / 25);
  resto %= 25;

  printf("%d moeda(s) de R$ 0.10\n", resto / 10);
  resto %= 10;

  printf("%d moeda(s) de R$ 0.05\n", resto / 5);
  resto %= 5;

  printf("%d moeda(s) de R$ 0.01\n", resto);

  return 0;
}
