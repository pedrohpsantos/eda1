#include <stdio.h>

int main()
{

  FILE *fp;
  char ch;
  char arquivo[1000];

  printf("Digite o nome do arquivo a ser lido: \n");
  scanf("%s", arquivo);
  fp = fopen(arquivo,
             "r"); // "r" método read ; exite o "w" write e "a" adiciona texto
                   // na ultima linha.

  if (fp == NULL)
  {
    printf("Não é possível acessar o arquivo %s \n ", arquivo);
  }

  while (1)
  {
    ch = fgetc(fp);
    if (ch == EOF) // EOF corresponde ao último caractere do arquivo antes dele
                   // ser fechado
      break;
    printf("%c", ch);
  }
  fclose(fp); // ! Feche o ponteiro para não corromper o arquivo
  return 0;
}
