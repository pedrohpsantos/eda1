#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int list[], int n)
{
    int i, j;
    int next;
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next < list[j]; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int *vet = (int *)malloc(n * sizeof(int));

    printf("Gerando vetor aleatorio...\n");
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 1000;
    }

    printf("Vetor original: ");
    printArray(vet, n);

    clock_t start = clock();
    insertionSort(vet, n);
    clock_t end = clock();

    printf("Vetor ordenado: ");
    printArray(vet, n);
    printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(vet);
    return 0;
}
