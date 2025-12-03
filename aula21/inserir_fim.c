#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

// Inserção no Fim (Circular)
TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;

    if (pLista == NULL) {
        pNovoNo->Prox = pNovoNo;
        return pNovoNo;
    }

    TNo *pAux = pLista;
    while (pAux->Prox != pLista) { // Encontra o último
        pAux = pAux->Prox;
    }

    pAux->Prox = pNovoNo;   // Antigo último aponta para o novo
    pNovoNo->Prox = pLista; // Novo aponta para o início (fecha o ciclo)

    return pLista; // O início da lista não mudou
}

void ImprimirLista(TNo *pLista) {
    if (pLista == NULL) return;
    TNo *pAux = pLista;
    printf("Lista Circular: ");
    do {
        printf("[%d] -> ", pAux->Numero);
        pAux = pAux->Prox;
    } while (pAux != pLista);
    printf("(volta)\n");
}

int main() {
    TNo *lista = NULL;
    printf("=== Teste 2: IncluiCalda (Circular) ===\n");

    lista = IncluiCalda(lista, 10);
    ImprimirLista(lista);

    lista = IncluiCalda(lista, 20);
    ImprimirLista(lista); // Esperado: 10 -> 20 -> (volta)

    return 0;
}