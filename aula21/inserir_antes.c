#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

// Funções auxiliares
TNo *IncluiCalda(TNo *pLista, int pValor) {
    TNo *n = (TNo*)malloc(sizeof(TNo)); n->Numero=pValor;
    if(!pLista){ n->Prox=n; return n; }
    TNo *aux=pLista; while(aux->Prox!=pLista) aux=aux->Prox;
    aux->Prox=n; n->Prox=pLista; return pLista;
}
TNo *IncluiCabeca(TNo *pLista, int pValor) {
    TNo *n = (TNo*)malloc(sizeof(TNo)); n->Numero=pValor;
    if(!pLista){ n->Prox=n; return n; }
    TNo *aux=pLista; while(aux->Prox!=pLista) aux=aux->Prox;
    n->Prox=pLista; aux->Prox=n; return n;
}

// Inserção Antes (Circular)
TNo *IncluiAntes(TNo *pLista, int pChave, int pValor) {
    if (pLista == NULL) return NULL;

    // Caso especial: Chave está na cabeça
    if (pLista->Numero == pChave) {
        return IncluiCabeca(pLista, pValor);
    }

    TNo *pAnt = pLista;
    // Busca: para se encontrar a chave OU se der uma volta completa
    while (pAnt->Prox != pLista && pAnt->Prox->Numero != pChave) {
        pAnt = pAnt->Prox;
    }

    // Se encontrou a chave
    if (pAnt->Prox->Numero == pChave) {
        TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
        pNovoNo->Numero = pValor;
        pNovoNo->Prox = pAnt->Prox;
        pAnt->Prox = pNovoNo;
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
    lista = IncluiCalda(lista, 30);
    
    printf("=== Teste 3: IncluiAntes (Circular) ===\n");
    ImprimirLista(lista);

    // Inserir 20 antes do 30
    lista = IncluiAntes(lista, 30, 20);
    ImprimirLista(lista); // Esperado: 10 -> 20 -> 30

    return 0;
}