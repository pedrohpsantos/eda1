#include <stdio.h>
#include <stdlib.h>

int MaiorAB(int a, int b) {
  int aux = (a + b + abs(a - b)) / 2;
  return aux;
}

int main() {

  int a, b, c, maior, aux;
  scanf("%d %d %d", &a, &b, &c);
  aux = MaiorAB(a, b);
  maior = MaiorAB(aux, c);
  printf("%d eh o maior\n", maior);

  return 0;
}
