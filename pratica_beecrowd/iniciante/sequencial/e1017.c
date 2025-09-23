#include <stdio.h>

int main() {

  double vm, h, comb;
  scanf("%lf", &h);
  scanf("%lf", &vm);
  comb = (h * vm) / 12;
  printf("%.3lf\n", comb);

  return 0;
}
