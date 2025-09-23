#include <stdio.h>

int main() {

  char name[100];
  double sal, vendas;
  scanf("%s", name);
  scanf("%lf", &sal);
  scanf("%lf", &vendas);
  sal += (vendas * 0.15);
  printf("TOTAL = R$ %.2lf\n", sal);

  return 0;
}
