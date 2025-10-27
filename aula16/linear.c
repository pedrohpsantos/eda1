#include <stdio.h>

// Encontra o maior elemento do array - O(n)
int encontrarMaximo(int arr[], int tamanho) {
    int max = arr[0];
    
    // Percorre todo o array uma vez
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}

// Soma todos os elementos - O(n)
int somarElementos(int arr[], int tamanho) {
    int soma = 0;
    
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];  // n operações
    }
    
    return soma;
}

// Busca linear - O(n)
int buscaLinear(int arr[], int tamanho, int chave) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == chave) {
            return i;  // Retorna o índice
        }
    }
    return -1;  // Não encontrado
}

int main() {
    int numeros[] = {5, 12, 8, 3, 19, 7};
    int tamanho = 6;
    
    printf("Maior elemento: %d\n", encontrarMaximo(numeros, tamanho));
    printf("Soma dos elementos: %d\n", somarElementos(numeros, tamanho));
    printf("Posicao do 19: %d\n", buscaLinear(numeros, tamanho, 19));
    
    return 0;
}
