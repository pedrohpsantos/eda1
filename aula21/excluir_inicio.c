#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *n = (TNo*)malloc(sizeof(TNo)); n->Numero=pValor;
    if(!pLista){ n->Prox=n; return n; }
    TNo *aux=pLista; while(aux->Prox!=pLista) aux=aux->Prox;
    aux->Prox=n; n->Prox=pLista; return pLista;
}

// Exclusão na Cabeça (Circular)
TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;

    // Caso: Apenas 1 elemento
    if (pLista->Prox == pLista) {
        free(pLista);
        return NULL;
    }

    TNo *pUltimo = pLista;
    while (pUltimo->Prox != pLista) { // Encontra o último
        pUltimo = pUltimo->Prox;
    }

    TNo *pTemp = pLista;
    pLista = pLista->Prox; // Nova cabeça avança
    pUltimo->Prox = pLista; // Último aponta para nova cabeça

    free(pTemp);
    return pLista;
}

void ImprimirLista(TNo *pLista) {
    if(!pLista) { printf("Lista Vazia\n"); return; }
    TNo *aux = pLista;
    printf("Lista: ");
    do { printf("%d -> ", aux->Numero); aux = aux->Prox; } while(aux != pLista);
    printf("(volta)\n");
}

int main() {
    TNo *lista = NULL;
    lista = IncluiCalda(lista, 10);
    lista = IncluiCalda(lista, 20);
    lista = IncluiCalda(lista, 30);

    printf("=== Teste 4: ExcluiCabeca (Circular) ===\n");
    ImprimirLista(lista);

    lista = ExcluiCabeca(lista); // Remove 10
    ImprimirLista(lista); // Esperado: 20 -> 30

    return 0;
}