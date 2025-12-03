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

TNo *ExcluiCalda(TNo *pLista) {
    if (pLista == NULL) return NULL;
    
    if (pLista->Prox == NULL) {
        free(pLista);
        return NULL;
    }

    TNo *pAux = pLista;
    // Vai até o penúltimo
    while (pAux->Prox->Prox != NULL) {
        pAux = pAux->Prox;
    }

    free(pAux->Prox);
    pAux->Prox = NULL;

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

    printf("=== Teste 5: Exclusao na Calda ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    minhaLista = ExcluiCalda(minhaLista);
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 10, 20

    return 0;
}