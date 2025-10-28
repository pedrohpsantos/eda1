#include <stdio.h>
#include <stdlib.h>

long int somaVet(int *a, int qtde)
{
  if (qtde == 0)
    return 0;
  else
    return a[qtde - 1] + somaVet(a, qtde - 1);
}

int main()
{
  int n, *v;
  printf("Qual o tamanho do vetor: ");
  scanf("%d", &n);
  v = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++)
  {
    printf("Numero na posição %d do vetor: ", i + 1);
    scanf("%d", &v[i]);
  }
  long int resultado = somaVet(v, n);
  printf("Soma dos vetores: %ld", resultado);
  return 0;
}
