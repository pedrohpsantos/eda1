#include <stdio.h>

void IntercalaVetores(char *v1, char *v2, char *v3)
{

  if (*v1 == '\0')
  {
    while (*v2 != '\0')
    {
      *v3 = *v2;
      v3++;
      v2++;
    }
    *v3 = '\0';
    return;
  }

  else if (*v2 == '\0')
  {
    while (*v1 != '\0')
    {
      *v3 = *v1;
      v3++;
      v1++;
    }
    *v3 = '\0';
    return;
  }

  *v3 = *v1;
  v3++;
  *v3 = *v2;
  v3++;
  return IntercalaVetores(v1 + 1, v2 + 1, v3);
}

int main()
{
  char V1[] = "abc", V2[] = "ABCDE";
  char V3[sizeof(V1) + sizeof(V2) - 1];

  IntercalaVetores(V1, V2, V3);
  printf("Intercalacao: %s\n", V3);
  return 0;
}
