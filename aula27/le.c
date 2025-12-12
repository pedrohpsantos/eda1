#include <stdio.h>
#include <stdlib.h>

// --- T1: Definição da estrutura ---
struct Node {  // [Gabarito T1]
    int dado;
    struct Node* proximo;
};

// Função para inserir no final (inserirNaCauda)
// Necessária para montar a lista na ordem: 25 -> 30 -> 35
void inserirNaCauda(struct Node** cabeca, int valor) {
    // --- T3: Utilização da variável para o novo nó ---
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node)); // [Gabarito T3]
    
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    // Se a lista estiver vazia, o novo nó é a cabeça
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    // Percorre até o último nó
    struct Node* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    // O último nó aponta para o novo nó
    atual->proximo = novoNo;
}

void imprimirLista(struct Node* cabeca) {
    struct Node* atual = cabeca;

    // --- T4: Condição do loop ---
    while (atual != NULL) {  // [Gabarito T4]
        printf("%d ", atual->dado);

        // --- T2: Avançar para o próximo nó ---
        atual = atual->proximo; // [Gabarito T2]
    }
    printf("\n");
}

int main() {
    struct Node* minhaLista = NULL;

    // Insere os valores solicitados utilizando a função correta
    inserirNaCauda(&minhaLista, 25);
    inserirNaCauda(&minhaLista, 30);
    inserirNaCauda(&minhaLista, 35);

    // Deve imprimir: 25 30 35
    imprimirLista(minhaLista);

    return 0;
}