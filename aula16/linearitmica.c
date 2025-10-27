#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para mesclar dois subarrays
void merge(int arr[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;
    
    // Arrays temporários
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    // Copia dados para os arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];
    
    // Mescla os arrays temporários de volta
    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Merge Sort - O(n log n)
void mergeSort(int arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Ordena primeira e segunda metade
        mergeSort(arr, esquerda, meio);
        mergeSort(arr, meio + 1, direita);
        
        // Mescla as metades ordenadas
        merge(arr, esquerda, meio, direita);
    }
}

// Imprime o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numeros[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = 7;
    
    printf("Array original: ");
    imprimirArray(numeros, tamanho);
    
    mergeSort(numeros, 0, tamanho - 1);
    
    printf("Apos Merge Sort: ");
    imprimirArray(numeros, tamanho);
    
    return 0;
}
