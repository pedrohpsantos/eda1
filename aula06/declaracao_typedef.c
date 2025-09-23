#include <stdio.h>

typedef struct {
  int x;
  int y;
} Ponto;

int main() {
  Ponto p1, *ptr;
  p1.x = 10;
  p1.y = 20;

  // Usando Ponteiros
  ptr = &p1;
  printf("X = %d\n", ptr->x);
  printf("Y = %d\n", ptr->y);
  return 0;
}
