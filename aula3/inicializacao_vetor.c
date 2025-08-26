#include <stdio.h>

int main()
{

    // Inicializando todos os elementos com 0
    int vetor[10] = {0};

    // É colocado o 15 na posição 5 do vetor
    vetor[5] = 15;

    // Percorre todo o vetor até o tamanho que definimos
    for (int i = 0; i < 10; i++)
        printf("%d, ", vetor[i]);

    return 0;
}