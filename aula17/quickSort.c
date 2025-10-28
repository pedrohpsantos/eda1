#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separa(int v[], int p, int r)
{
    int c = v[r];
    int t, j = p;
    for (int k = p; k < r; ++k)
        if (v[k] <= c)
        {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j;
        }
    t = v[j], v[j] = v[r], v[r] = t;
    return j;
}

void quicksort(int v[], int p, int r)
{
    if (p < r)
    {
        int j = separa(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
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
    quicksort(vet, 0, n - 1);
    clock_t end = clock();

    printf("Vetor ordenado: ");
    printArray(vet, n);
    printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(vet);
    return 0;
}
