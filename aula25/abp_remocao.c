#include <stdio.h>
#include <stdlib.h>

// (Reutilizando a struct No do exemplo anterior)
typedef struct No
{
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Função auxiliar: Encontrar o menor valor de uma subárvore (para o caso de 2 filhos)
No *encontrarMinimo(No *no)
{
    No *atual = no;
    // O menor valor em uma ABP é sempre o nó mais à esquerda
    while (atual && atual->esquerda != NULL)
    {
        atual = atual->esquerda;
    }
    return atual;
}

// Função de Remoção
No *remover(No *raiz, int valor)
{
    if (raiz == NULL)
        return raiz;

    // 1. Navegar até encontrar o nó
    if (valor < raiz->valor)
    {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = remover(raiz->direita, valor);
    }
    else
    {
        // Encontramos o nó a ser removido!

        // CASO 1 e 2: Nó com um filho ou nenhum
        if (raiz->esquerda == NULL)
        {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // CASO 3: Nó com dois filhos
        // Estratégia: Pegar o menor elemento da subárvore direita (sucessor)
        No *temp = encontrarMinimo(raiz->direita);

        // Copia o valor do sucessor para o nó atual
        raiz->valor = temp->valor;

        // Remove o sucessor da subárvore direita (pois ele foi "movido" para cá)
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}