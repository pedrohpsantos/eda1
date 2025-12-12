#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int chave;
    struct Node *esquerda, *direita;
};

struct Node *novoNo(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->chave = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

struct Node *inserir(struct Node *raiz, int chave)
{
    // Se a árvore estiver vazia, retorna um novo nó
    if (raiz == NULL)
    {
        struct Node *novoNo = (struct Node *)malloc(sizeof(struct Node));

        // --- T1: Preenchendo o valor do nó ---
        novoNo->chave = chave; // [Gabarito T1]

        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        return novoNo;
    }

    // Caso contrário, percorre a árvore
    if (chave < raiz->chave)
        // --- T2: Recursão Esquerda ---
        raiz->esquerda = inserir(raiz->esquerda, chave); // [Gabarito T2]
    else if (chave > raiz->chave)
        // --- T3: Recursão Direita ---
        raiz->direita = inserir(raiz->direita, chave); // [Gabarito T3]

    // --- T4: Retorna o ponteiro do nó (raiz) inalterado ---
    return raiz; // [Gabarito T4]
}

struct Node *buscar(struct Node *raiz, int chave)
{
    // Caso base: raiz é null ou a chave está na raiz
    if (raiz == NULL || raiz->chave == chave)
        return raiz;

    // --- T5: Lógica de decisão para busca ---
    if (chave < raiz->chave) // [Gabarito T5]
        return buscar(raiz->esquerda, chave);

    return buscar(raiz->direita, chave);
}

int main()
{
    struct Node *raiz = NULL;

    // Inserindo dados para testar
    raiz = inserir(raiz, 100);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 150); // O valor que queremos encontrar

    int chaveBuscada = 150;
    struct Node *resultado = NULL;

    // --- T6: Chamada da função de busca ---
    resultado = buscar(raiz, chaveBuscada); // [Gabarito T6]

    if (resultado != NULL)
        printf("Chave encontrada: %d\n", resultado->chave);
    else
        printf("Chave nao encontrada\n");

    return 0;
}