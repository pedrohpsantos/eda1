#include <stdio.h>

int main()
{

    // Inicializando a matriz com todos os elementos com 0
    int matriz[3][4] = {{0}};

    // Adicionando elementos na diagonal
    matriz[0][0] = 1;
    matriz[1][1] = 2;
    matriz[2][2] = 3;

    // Percorre toda a matriz e mostra os elementos
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}