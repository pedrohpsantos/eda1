#include <stdio.h>

int main() {

  double n1, n2, n3, n4, ns, media, mediaSub;
  scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
  media = (n1 * 2 + n2 * 3 + n3 * 4 + n4 * 1) / 10;
  printf("Media: %.1lf\n", media);
  if (media > 7) {
    printf("Aluno aprovado.\n");
  } else if (media >= 5 && media <= 6.9) {
    printf("Aluno em exame.\n");
    scanf("%lf", &ns);
    printf("Nota do exame: %.1lf\n", ns);
    mediaSub = (media + ns) / 2;
    if (mediaSub >= 5) {
      printf("Aluno aprovado.\n");
    } else {
      printf("Aluno reprovado.\n");
    }
    printf("Media final: %.1lf\n", mediaSub);
  } else {
    printf("Aluno reprovado.\n");
  }
  return 0;
}
