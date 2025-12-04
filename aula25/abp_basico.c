#include <stdio.h>
#include <stdlib.h>

// Definição do Nó
typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

// Função auxiliar para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Inserção Recursiva
// Complexidade: O(h) onde h é a altura
No* inserir(No* raiz, int valor) {
    // 1. Se a árvore for vazia, cria o nó aqui
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // 2. Se valor for menor, vai para esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // 3. Se valor for maior, vai para direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    
    // Retorna a raiz (importante para manter a ligação recursiva)
    return raiz;
}

// Pesquisa Recursiva
No* buscar(No* raiz, int valor) {
    // Caso base: árvore vazia ou encontrou o valor
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    // Se valor buscado é menor, procura na esquerda
    if (valor < raiz->valor) {
        return buscar(raiz->esquerda, valor);
    }
    
    // Caso contrário, procura na direita
    return buscar(raiz->direita, valor);
}

void main_exemplo1() {
    No* raiz = NULL;
    
    // Inserindo dados: 5, 3, 7 (Exemplo simples)
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);

    // Testando busca
    No* resultado = buscar(raiz, 7);
    if (resultado != NULL) printf("Valor %d encontrado!\n", resultado->valor);
    else printf("Valor nao encontrado.\n");
}