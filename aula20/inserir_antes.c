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

// Função: IncluiDepois (Baseado nos slides 29-42)
TNo *IncluiDepois(TNo *pLista, int pChave, int pValor) {
    TNo *pAux = pLista;
    while (pAux != NULL && pAux->Numero != pChave) {
        pAux = pAux->Prox;
    }

    if (pAux == NULL) return pLista; // Chave não encontrada

    TNo *pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;

    pNovoNo->Prox = pAux->Prox;
    pNovoNo->Ant = pAux;

    if (pAux->Prox != NULL) {
        pAux->Prox->Ant = pNovoNo;
    }
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
    // Preparando lista inicial: 10 -> 20 -> 30
    minhaLista = IncluiCalda(minhaLista, 10);
    minhaLista = IncluiCalda(minhaLista, 20);
    minhaLista = IncluiCalda(minhaLista, 30);
    
    printf("=== Teste 3: Inclusao Apos Chave ===\n");
    printf("Original: "); ImprimirLista(minhaLista);

    // Inserir 99 depois do 20
    minhaLista = IncluiDepois(minhaLista, 20, 99);
    printf("Apos inserir 99 depois de 20: "); 
    ImprimirLista(minhaLista); // Esperado: 10, 20, 99, 30

    return 0;
}