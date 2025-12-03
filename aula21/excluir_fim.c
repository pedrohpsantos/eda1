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

// Exclusão na Calda (Circular)
TNo *ExcluiCalda(TNo *pLista) {
    if (pLista == NULL) return NULL;

    // Caso: Apenas 1 elemento
    if (pLista->Prox == pLista) {
        free(pLista);
        return NULL;
    }

    TNo *pAux = pLista;
    // Vai até o penúltimo (cujo próximo é o último, que aponta pro início)
    while (pAux->Prox->Prox != pLista) {
        pAux = pAux->Prox;
    }

    // pAux é o penúltimo. pAux->Prox é o último.
    free(pAux->Prox);
    pAux->Prox = pLista; // Penúltimo vira último e aponta para o início

    return pLista;
}

void ImprimirLista(TNo *pLista) {
    if(!pLista) return;
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

    printf("=== Teste 5: ExcluiCalda (Circular) ===\n");
    ImprimirLista(lista);

    lista = ExcluiCalda(lista); // Remove 30
    ImprimirLista(lista); // Esperado: 10 -> 20

    return 0;
}