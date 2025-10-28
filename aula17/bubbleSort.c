#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vet[], int tam)
{
    int i, j, temp;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
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
    bubbleSort(vet, n);
    clock_t end = clock();

    printf("Vetor ordenado: ");
    printArray(vet, n);
    printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(vet);
    return 0;
}
