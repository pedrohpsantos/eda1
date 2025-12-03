#include <stdio.h>
#include <stdlib.h>

// Definição do Nó
typedef struct TNo {
    struct TNo *Ant;
    int Numero;
    struct TNo *Prox;
} TNo;

// Função: IncluiCabeca (Baseado nos slides 6-13)
TNo *IncluiCabeca(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Ant = NULL;
    pNovoNo->Prox = pLista;

    if (pLista != NULL) {
        pLista->Ant = pNovoNo;
    }
    
    return pNovoNo; // Retorna o novo nó como a nova cabeça
}

// Função auxiliar para imprimir
void ImprimirLista(TNo *pLista) {
    printf("Lista: ");
    while (pLista != NULL) {
        printf("[%d] ", pLista->Numero);
        pLista = pLista->Prox;
    }
    printf("\n");
}

int main() {
    TNo *minhaLista = NULL;

    printf("=== Teste 1: Inclusao na Cabeca ===\n");
    minhaLista = IncluiCabeca(minhaLista, 10);
    ImprimirLista(minhaLista);

    minhaLista = IncluiCabeca(minhaLista, 20);
    ImprimirLista(minhaLista);

    minhaLista = IncluiCabeca(minhaLista, 30);
    ImprimirLista(minhaLista); // Esperado: 30, 20, 10

    return 0;
}