#include <stdio.h>

void bubbleSort(int vet[], int tam)
{
    int i, j, temp;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++) // Faz trocas até posição i
            if (vet[j] > vet[j + 1])
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
    }
}