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

// Função: ExcluiCalda (Baseado nos slides 48-57)
TNo *ExcluiCalda(TNo *pLista) {
    if (pLista == NULL) return NULL;

    if (pLista->Prox == NULL) {
        free(pLista);
        return NULL;
    }

    TNo *pAux = pLista;
    // Vai até o penúltimo elemento
    while (pAux->Prox->Prox != NULL) {
        pAux = pAux->Prox;
    }

    free(pAux->Prox); // Libera o último
    pAux->Prox = NULL; // Atualiza o penúltimo para ser o fim

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

    minhaLista = ExcluiCalda(minhaLista); // Remove 30
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 10, 20

    return 0;
}