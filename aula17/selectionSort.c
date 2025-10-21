#include <stdio.h>

int smallerIndex(int vet[], int tam, int ini)
{
    int min = ini, j;
    for (j = ini + 1; j < tam; j++)
    {
        if (vet[min] > vet[j])
            min = j;
    }
    return min;
}

void selectionSort(int vet[], int tam)
{
    int i, min, aux;
    for (i = 0; i < tam; i++)
    {
        // Acha posicao do menor elemento a partir de i:
        min = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}