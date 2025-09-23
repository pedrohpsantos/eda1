#include <stdio.h>

int main() {
  int cod, quan;
  double preco;
  scanf("%d %d", &cod, &quan);
  switch (cod) {
  case 1:
    preco = quan * 4;
    break;

  case 2:
    preco = quan * 4.5;
    break;

  case 3:
    preco = quan * 5;
    break;

  case 4:
    preco = quan * 2;
    break;

  case 5:
    preco = quan * 1.5;
    break;
  }
  printf("Total: R$ %.2lf\n", preco);
  return 0;
}
