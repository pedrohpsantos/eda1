#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

// Inserção no Início (Circular)
TNo *IncluiCabeca(TNo *pLista, int pValor) {
    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;

    // Caso 1: Lista Vazia
    if (pLista == NULL) {
        pNovoNo->Prox = pNovoNo; // Aponta para si mesmo
        return pNovoNo;
    }

    // Caso 2: Lista com elementos
    TNo *pAux = pLista;
    while (pAux->Prox != pLista) { // Vai até o último nó
        pAux = pAux->Prox;
    }

    pNovoNo->Prox = pLista; // Novo aponta para a antiga cabeça
    pAux->Prox = pNovoNo;   // Último aponta para o novo
    
    return pNovoNo; // Retorna a nova cabeça
}

void ImprimirLista(TNo *pLista) {
    if (pLista == NULL) return;
    TNo *pAux = pLista;
    printf("Lista Circular: ");
    do {
        printf("[%d] -> ", pAux->Numero);
        pAux = pAux->Prox;
    } while (pAux != pLista);
    printf("(volta ao inicio)\n");
}

int main() {
    TNo *lista = NULL;
    printf("=== Teste 1: IncluiCabeca (Circular) ===\n");
    
    lista = IncluiCabeca(lista, 10);
    ImprimirLista(lista);

    lista = IncluiCabeca(lista, 20); // 20 deve ser o primeiro
    ImprimirLista(lista);

    lista = IncluiCabeca(lista, 30); // 30 deve ser o primeiro
    ImprimirLista(lista); // Esperado: 30 -> 20 -> 10 -> (volta)

    return 0;
}