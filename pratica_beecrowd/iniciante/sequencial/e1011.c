#include <math.h>
#include <stdio.h>

int main() {

  double r, circulo, pi = 3.14159;
  scanf("%lf", &r);
  circulo = (4.0 / 3.0) * pi * pow(r, 3);
  printf("VOLUME = %.3lf\n", circulo);

  return 0;
}
