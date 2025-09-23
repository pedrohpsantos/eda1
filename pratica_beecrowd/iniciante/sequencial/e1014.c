#include <stdio.h>

int main() {

  double km, l, cons;
  scanf("%lf", &km);
  scanf("%lf", &l);
  cons = km / l;
  printf("%.3lf km/l\n", cons);

  return 0;
}
