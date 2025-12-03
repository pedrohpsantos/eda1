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

// Necessário para remover a cabeça caso a chave seja o primeiro item
TNo *ExcluiCabeca(TNo *pLista) {
    if (pLista == NULL) return NULL;
    TNo *pAux = pLista;
    pLista = pLista->Prox;
    if (pLista != NULL) pLista->Ant = NULL;
    free(pAux);
    return pLista;
}

// Função: ExcluiChave (Baseado nos slides 58-69)
TNo *ExcluiChave(TNo *pLista, int pChave) {
    TNo *pAux = pLista;

    // Busca o nó com o valor da chave
    while (pAux != NULL && pAux->Numero != pChave) {
        pAux = pAux->Prox;
    }

    if (pAux == NULL) return pLista; // Chave não encontrada

    // Se a chave for o primeiro elemento, usa a função de excluir cabeça
    if (pAux == pLista) {
        return ExcluiCabeca(pLista);
    }

    // Ajusta os ponteiros dos vizinhos ("costura" a lista)
    pAux->Ant->Prox = pAux->Prox;
    if (pAux->Prox != NULL) {
        pAux->Prox->Ant = pAux->Ant;
    }

    free(pAux);
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
    minhaLista = IncluiCalda(minhaLista, 20); // Alvo
    minhaLista = IncluiCalda(minhaLista, 30);

    printf("=== Teste 6: Exclusao por Chave ===\n");
    printf("Antes: "); ImprimirLista(minhaLista);

    minhaLista = ExcluiChave(minhaLista, 20); // Remove o elemento do meio
    printf("Depois: "); ImprimirLista(minhaLista); // Esperado: 10, 30

    return 0;
}