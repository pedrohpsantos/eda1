#include <stdio.h>

void swap(float *ptr1, float *ptr2) {
  float temp = *ptr1; // Armazena o valor de ptr1 na variavel temporaria
  *ptr1 = *ptr2;      // Atribui o valor de prt2 a ptr1
  *ptr2 = temp;       // Atribui o valor temporario a ptr2
}

int main() {
  float a = 3.14;
  float b = 2.71;
  printf("--- Valores originais ---\n");
  printf("A = %.2f\n", a);
  printf("B = %.2f\n\n", b);

  // Chama a função swap
  swap(&a, &b);
  printf("--- Posicoes alteradas ---\n");
  printf("A = %.2f\n", a);
  printf("B = %.2f\n", b);

  return 0;
}
