#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        min = smallerIndex(vet, tam, i);
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int *vet = (int*)malloc(n * sizeof(int));
    
    printf("Gerando vetor aleatorio...\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        vet[i] = rand() % 1000;
    }
    
    printf("Vetor original: ");
    printArray(vet, n);
    
    clock_t start = clock();
    selectionSort(vet, n);
    clock_t end = clock();
    
    printf("Vetor ordenado: ");
    printArray(vet, n);
    printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    free(vet);
    return 0;
}
