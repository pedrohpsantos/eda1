#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    struct TNo *Ant;
    int Numero;
    struct TNo *Prox;
} TNo;

// Função auxiliar para criar lista inicial
TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = NULL;
    if (pLista == NULL) { pNovoNo->Ant = NULL; return pNovoNo; }
    TNo *pAux = pLista;
    while (pAux->Prox != NULL) pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    pNovoNo->Ant = pAux;
    return pLista;
}

// Função: ExcluiCabeca (Baseado nos slides 43-47)
TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;

    TNo *pAux = pLista;
    pLista = pLista->Prox;

    if (pLista != NULL) {
        pLista->Ant = NULL;
    }

    free(pAux);
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
    minhaLista = IncluiCalda(minhaLista, 10);
    minhaLista = IncluiCalda(minhaLista, 20);
    minhaLista = IncluiCalda(minhaLista, 30);

    printf("=== Teste 4: Exclusao na Cabeca ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    minhaLista = ExcluiCabeca(minhaLista); // Remove 10
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 20, 30

    return 0;
}