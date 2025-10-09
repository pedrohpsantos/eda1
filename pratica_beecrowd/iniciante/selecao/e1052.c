#include <stdio.h>

int main() {
  const char *meses[] = {"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};
  int n;
  scanf("%d", &n);
  if (n <= 12 && n >= 1) {
    printf("%s\n", meses[n - 1]);
  }

  return 0;
}
