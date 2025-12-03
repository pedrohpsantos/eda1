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

// Função necessária para o caso da chave ser a cabeça
TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;
    TNo *pAux = pLista;
    pLista = pLista->Prox;
    free(pAux);
    return pLista;
}

TNo *ExcluiChave(TNo *pLista, int pChave) {
    if (pLista == NULL) return NULL;

    // Se a chave está no primeiro nó
    if (pLista->Numero == pChave) {
        return ExcluiCabeca(pLista);
    }

    TNo *pAnt = pLista;
    // Procura o nó anterior ao que contém a chave
    while (pAnt->Prox != NULL && pAnt->Prox->Numero != pChave) {
        pAnt = pAnt->Prox;
    }

    // Se encontrou a chave (não chegou no fim da lista)
    if (pAnt->Prox != NULL) {
        TNo *pPost = pAnt->Prox->Prox; // Guarda o nó seguinte
        free(pAnt->Prox);              // Libera o nó da chave
        pAnt->Prox = pPost;            // Liga o anterior ao seguinte
    }

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

    printf("=== Teste 6: Exclusao de Chave ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    minhaLista = ExcluiChave(minhaLista, 20);
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 10, 30

    return 0;
}