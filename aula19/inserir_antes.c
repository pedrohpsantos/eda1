#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int Numero;
    struct TNo *Prox;
} TNo;

// Função auxiliar para criar lista
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

TNo *IncluiAntes(TNo *pLista, int pChave, int pValor) {
    TNo *pNovoNo, *pAux;
    
    // Caso especial: Se a chave está na cabeça ou a lista é vazia
    if (pLista == NULL || pLista->Numero == pChave) {
        pNovoNo = (TNo *) malloc(sizeof(TNo));
        pNovoNo->Numero = pValor;
        pNovoNo->Prox = pLista;
        return pNovoNo;
    }

    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    
    pAux = pLista;
    // Procura o nó ANTERIOR ao da chave
    while (pAux->Prox != NULL && pAux->Prox->Numero != pChave) {
        pAux = pAux->Prox;
    }

    // Se encontrou (ou chegou ao fim), insere
    pNovoNo->Prox = pAux->Prox;
    pAux->Prox = pNovoNo;

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
    minhaLista = IncluiCalda(minhaLista, 30);
    
    printf("=== Teste 3: Inclusao Antes de Chave ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    // Inserir 20 antes do 30
    minhaLista = IncluiAntes(minhaLista, 30, 20);
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 10, 20, 30

    return 0;
}