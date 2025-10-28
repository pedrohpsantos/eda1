#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int p, int q, int r, int v[])
{
    int *w;
    w = (int *)malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;
    while (i < q && j < r)
    {
        if (v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[])
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
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
    mergesort(0, n, vet);
    clock_t end = clock();

    printf("Vetor ordenado: ");
    printArray(vet, n);
    printf("Tempo: %.6f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(vet);
    return 0;
}
