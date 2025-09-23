#include <math.h>
#include <stdio.h>

int main() {

  double area;
  double pi = 3.14159;
  double raio;
  scanf("%lf", &raio);
  area = pi * pow(raio, 2);
  printf("A=%.4lf\n", area);

  return 0;
}
