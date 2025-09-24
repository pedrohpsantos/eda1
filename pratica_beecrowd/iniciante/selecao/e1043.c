#include <stdio.h>

int main() {

  double a, b, c, peri, area;
  scanf("%lf %lf %lf", &a, &b, &c);

  if (a + b > c && a + c > b && b + c > a) {
    peri = a + b + c;
    printf("Perimetro = %.1lf\n", peri);
  } else {
    area = ((a + b) * c) / 2;
    printf("Area = %.1lf\n", area);
  }
  return 0;
}
