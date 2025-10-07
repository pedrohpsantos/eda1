#include <stdio.h>

int main() {

  double sal, imp;
  scanf("%lf", &sal);
  if (sal <= 2000) {
    imp = 0.0;
  } else if (sal <= 3000) {
    imp = (sal - 2000) * 0.08;
  } else if (sal <= 4500) {
    imp = (1000 * 0.08) + (sal - 3000) * 0.18;
  } else {
    imp = (1000 * 0.08) + (1500 * 0.18) + (sal - 4500) * 0.28;
  }

  if (imp == 0.0) {
    printf("Isento\n");
  } else {
    printf("R$ %.2lf\n", imp);
  }

  return 0;
}
