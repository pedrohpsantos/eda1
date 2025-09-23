#include <stdio.h>

int main() {

  int idade, ano, mes, resto, dia;

  scanf("%d", &idade);

  ano = idade / 365;
  resto = idade % 365;
  mes = resto / 30;
  dia = resto % 30;

  printf("%d ano(s)\n", ano);
  printf("%d mes(es)\n", mes);
  printf("%d dia(s)\n", dia);

  return 0;
}
