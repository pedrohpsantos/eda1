#include <stdio.h>

int main()
{

  // Inicializando a matriz 3D
  int matriz3d[2][3][4] = {{{0}}};

  // Adicionando elementos na matriz 3D
  matriz3d[0][1][2] = 1;
  matriz3d[1][2][3] = 2;
  matriz3d[1][0][0] = 3;

  // Percorre toda a matriz e mostra os elementos
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 4; k++)
      {
        printf("%d ", matriz3d[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
