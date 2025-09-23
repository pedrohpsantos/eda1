#include <math.h>
#include <stdio.h>

int main() {
  double x1, x2, y1, y2, px, py, media;
  scanf("%lf %lf", &x1, &y1);
  scanf("%lf %lf", &x2, &y2);
  px = x2 - x1;
  py = y2 - y1;
  media = sqrt(pow(px, 2) + pow(py, 2));
  printf("%.4lf\n", media);
  return 0;
}
