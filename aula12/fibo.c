#include <stdio.h>

int Fibo(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return Fibo(n - 1) + Fibo(n - 2);
}

int main() {
  int n;
  printf("Quer qual posicao: ");
  scanf("%d", &n);
  printf("Resultado na %d posicao: %d", n, Fibo(n));
  return 0;
}
