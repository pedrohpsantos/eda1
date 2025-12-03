#include <stdio.h>

typedef struct No
{
    int valor;
    struct No *esquerdo;
    struct No *direito;
} No;

No* criarNovoNo(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL){
        printf("Erro de alocação\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->direito = NULL;
    novoNo->esquerdo = NULL;
    return novoNo;
}