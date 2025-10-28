#include <stdio.h>

// Bubble Sort - O(n²)
void bubbleSort(int arr[], int tamanho)
{
    int trocou;

    // Loop externo: n iterações
    for (int i = 0; i < tamanho - 1; i++)
    {
        trocou = 0;

        // Loop interno: (n-i-1) iterações
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Troca os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }

        // Otimização: se não houve troca, já está ordenado
        if (trocou == 0)
        {
            break;
        }
    }
}

// Selection Sort - O(n²)
void selectionSort(int arr[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        int indiceMenor = i;

        // Encontra o menor elemento no restante do array
        for (int j = i + 1; j < tamanho; j++)
        {
            if (arr[j] < arr[indiceMenor])
            {
                indiceMenor = j;
            }
        }

        // Troca o menor elemento encontrado com o primeiro
        if (indiceMenor != i)
        {
            int temp = arr[i];
            arr[i] = arr[indiceMenor];
            arr[indiceMenor] = temp;
        }
    }
}

// Imprime o array
void imprimirArray(int arr[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int numeros1[] = {64, 34, 25, 12, 22, 11, 90};
    int numeros2[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = 7;

    printf("Array original: ");
    imprimirArray(numeros1, tamanho);

    bubbleSort(numeros1, tamanho);
    printf("Apos Bubble Sort: ");
    imprimirArray(numeros1, tamanho);

    selectionSort(numeros2, tamanho);
    printf("Apos Selection Sort: ");
    imprimirArray(numeros2, tamanho);

    return 0;
}
