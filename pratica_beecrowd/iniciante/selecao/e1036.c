#include <math.h>
#include <stdio.h>

int main() {

  double a, b, c, delta, r1, r2;
  scanf("%lf %lf %lf", &a, &b, &c);

  delta = pow(b, 2) - 4 * a * c;

  if (delta < 0 || a == 0) {
    printf("Impossivel calcular\n");
  } else {
    r1 = (-b + sqrt(delta)) / (2 * a);
    r2 = (-b - sqrt(delta)) / (2 * a);
    printf("R1 = %.5lf\n", r1);
    printf("R2 = %.5lf\n", r2);
  }

  return 0;
}
