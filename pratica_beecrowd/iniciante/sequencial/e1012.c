#include <math.h>
#include <stdio.h>

int main() {

  double a, b, c;
  double tri, cir, tra, qua, ret, pi = 3.14159;
  scanf("%lf %lf %lf", &a, &b, &c);
  tri = (a * c) / 2;
  cir = pi * pow(c, 2);
  tra = (a + b) * c / 2;
  qua = pow(b, 2);
  ret = a * b;
  printf("TRIANGULO: %.3lf\n", tri);
  printf("CIRCULO: %.3lf\n", cir);
  printf("TRAPEZIO: %.3lf\n", tra);
  printf("QUADRADO: %.3lf\n", qua);
  printf("RETANGULO: %.3lf\n", ret);

  return 0;
}
