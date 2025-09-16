#include <stdio.h>

int main() {

  FILE *fp;
  char ch;
  int charactere = 0, spaces = 0, tabs = 0, newlines = 0;
  fp = fopen("lorem.txt", "r");
  while (1) {
    ch = fgetc(fp);
    if (ch == EOF)
      break;
    if (ch == '\n') {
      newlines++;
    } else if (ch == ' ') {
      spaces++;
    } else if (ch == '\t') {
      tabs++;
    } else {
      charactere++;
    }
  }
  fclose(fp);
  printf("Quantidade de caracteres: %d\n", charactere);
  printf("Quantidade de espaços: %d\n", spaces);
  printf("Quantidade de novas linhas: %d\n", newlines);
  printf("Quantidade de tabulação: %d\n", tabs);
  return 0;
}