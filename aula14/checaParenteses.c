#include <stdio.h>

int ChecaParenteses(char *expr, int count)
{
  if (*expr == '\0')
  {
    if (count == 0)
      return 0;

    if (count < 0)
      return -1;

    if (count > 0)
      return 1;
  }

  if (*expr == '(')
    count--;

  if (*expr == ')')
    count++;

  return ChecaParenteses(expr + 1, count);
}

int main()
{
  char *expression1 = "((1 + 2) * (3 + 4))";
  char *expression2 = "((1 + 2) * (3 + 4)";
  char *expression3 = "((1 + 2)) * (3 + 4))";
  printf("Resultado para expressão 1: %d\n",
         ChecaParenteses(expression1, 0)); // Deve retornar 0
  printf("Resultado para expressão 2: %d\n",
         ChecaParenteses(expression2, 0)); // Deve retornar -1
  printf("Resultado para expressão 3: %d\n",
         ChecaParenteses(expression3, 0)); // Deve retornar 1
  return 0;
}
