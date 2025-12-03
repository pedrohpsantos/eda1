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

TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;
    if (pLista->Prox == pLista) { free(pLista); return NULL; }
    TNo *ult = pLista; while (ult->Prox != pLista) ult = ult->Prox;
    TNo *tmp = pLista; pLista = pLista->Prox; ult->Prox = pLista;
    free(tmp); return pLista;
}

// Exclusão por Chave (Circular)
TNo *ExcluiChave(TNo *pLista, int pChave) {
    if (pLista == NULL) return NULL;

    // Caso especial: Chave na cabeça
    if (pLista->Numero == pChave) {
        return ExcluiCabeca(pLista);
    }

    TNo *pAnt = pLista;
    // Busca: para se encontrar ou se der uma volta
    while (pAnt->Prox != pLista && pAnt->Prox->Numero != pChave) {
        pAnt = pAnt->Prox;
    }

    // Se achou a chave
    if (pAnt->Prox->Numero == pChave) {
        TNo *pRemover = pAnt->Prox;
        pAnt->Prox = pRemover->Prox; // "Pula" o nó removido
        free(pRemover);
    }

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

    printf("=== Teste 6: ExcluiChave (Circular) ===\n");
    ImprimirLista(lista);

    lista = ExcluiChave(lista, 20); // Remove o elemento do meio
    ImprimirLista(lista); // Esperado: 10 -> 30

    return 0;
}