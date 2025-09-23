#include <stdio.h>

int main() {

  int num, aum;
  double sal;
  scanf("%d", &num);
  scanf("%d", &aum);
  scanf("%lf", &sal);
  sal *= aum;
  printf("NUMBER = %d\n", num);
  printf("SALARY = U$ %.2lf\n", sal);

  return 0;
}
