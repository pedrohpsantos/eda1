#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char ch;
  fp = fopen("hello.txt", "r");
  if (fp == NULL) {
    printf("Unable to open file\n");
    exit(0);
  } else {
    while (1) {
      ch = fgetc(fp);
      if (ch == EOF)
        break;
      printf("%c", ch);
    }
    printf("\n");
  }
  fclose(fp);
  return 0;
}
