#include <stdio.h>

// Busca binária iterativa - O(log n)
// IMPORTANTE: O array deve estar ordenado!
int buscaBinaria(int arr[], int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        // Elemento encontrado
        if (arr[meio] == chave) {
            return meio;
        }
        
        // Se a chave é menor, busca na metade esquerda
        if (arr[meio] > chave) {
            fim = meio - 1;
        }
        // Se a chave é maior, busca na metade direita
        else {
            inicio = meio + 1;
        }
    }
    
    return -1;  // Não encontrado
}

// Busca binária recursiva - O(log n)
int buscaBinariaRecursiva(int arr[], int inicio, int fim, int chave) {
    if (inicio > fim) {
        return -1;  // Não encontrado
    }
    
    int meio = inicio + (fim - inicio) / 2;
    
    if (arr[meio] == chave) {
        return meio;
    }
    
    if (arr[meio] > chave) {
        return buscaBinariaRecursiva(arr, inicio, meio - 1, chave);
    }
    
    return buscaBinariaRecursiva(arr, meio + 1, fim, chave);
}

int main() {
    // Array ORDENADO
    int numeros[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int tamanho = 11;
    
    printf("Busca iterativa por 23: posicao %d\n", 
           buscaBinaria(numeros, tamanho, 23));
    
    printf("Busca recursiva por 45: posicao %d\n", 
           buscaBinariaRecursiva(numeros, 0, tamanho - 1, 45));
    
    return 0;
}
