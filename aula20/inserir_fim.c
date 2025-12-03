#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    struct TNo *Ant;
    int Numero;
    struct TNo *Prox;
} TNo;

// Função: IncluiCalda (Baseado nos slides 14-28)
TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = NULL;

    if (pLista == NULL) {
        pNovoNo->Ant = NULL;
        return pNovoNo;
    }

    TNo *pAux = pLista;
    while (pAux->Prox != NULL) {
        pAux = pAux->Prox;
    }

    pAux->Prox = pNovoNo;
    pNovoNo->Ant = pAux;

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

    printf("=== Teste 2: Inclusao na Calda ===\n");
    minhaLista = IncluiCalda(minhaLista, 10);
    ImprimirLista(minhaLista);

    minhaLista = IncluiCalda(minhaLista, 20);
    ImprimirLista(minhaLista);

    minhaLista = IncluiCalda(minhaLista, 30);
    ImprimirLista(minhaLista); // Esperado: 10, 20, 30

    return 0;
}