#include <stdio.h>

int Fatorial(int n) {
  if (n == 0)
    return 1; // Caso Base
  else
    return n * Fatorial(n - 1); // Passo Recursivo
}

int main() {
  int x, result;
  printf("Fatorial de: ");
  scanf("%d", &x);
  result = Fatorial(x);
  printf("\nFatorial de %d = %d\n", x, result);
}
