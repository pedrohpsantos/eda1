#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

// Função auxiliar
TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = NULL;
    if (pLista == NULL) return pNovoNo;
    TNo *pAux = pLista;
    while (pAux->Prox != NULL) pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;

    TNo *pAux = pLista;
    pLista = pLista->Prox;
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

    printf("=== Teste 4: Exclusao na Cabeca ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    minhaLista = ExcluiCabeca(minhaLista);
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 20

    return 0;
}