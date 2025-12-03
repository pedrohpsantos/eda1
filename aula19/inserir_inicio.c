#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

TNo *IncluiCabeca(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = pLista;
    pLista = pNovoNo;
    return pLista;
}

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
    ImprimirLista(minhaLista); // Esperado: 20, 10

    return 0;
}