#include <stdio.h>
#include <stdlib.h>

// Struct do Nó
typedef struct TNo {
    int Numero;           // Dado direto
    struct TNo *Prox;
} TNo;

// Struct da Fila (Descritor)
typedef struct {
    TNo *Inicio;
    TNo *Fim;
    int Qtde;
} TFila;

// --- Funções ---

void Inicializar(TFila *f) {
    f->Inicio = NULL;
    f->Fim = NULL;
    f->Qtde = 0;
}

void Enfileirar(TFila *f, int valor) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (novo == NULL) return;

    novo->Numero = valor;
    novo->Prox = NULL; // Será o último, então aponta para NULL

    if (f->Fim != NULL) {
        f->Fim->Prox = novo; // O antigo último aponta para o novo
    } else {
        f->Inicio = novo;    // Se estava vazia, o novo também é o início
    }

    f->Fim = novo; // Atualiza o ponteiro de fim
    f->Qtde++;
}

int Desenfileirar(TFila *f) {
    if (f->Inicio == NULL) {
        printf("Fila Vazia!\n");
        return -1;
    }

    TNo *aux = f->Inicio;
    int valor = aux->Numero;

    f->Inicio = f->Inicio->Prox; // O início avança
    
    if (f->Inicio == NULL) {
        f->Fim = NULL; // Se esvaziou, atualiza o fim
    }

    free(aux);
    f->Qtde--;
    
    return valor;
}

void Imprimir(TFila *f) {
    TNo *aux = f->Inicio;
    printf("Fila: Inicio -> ");
    while (aux != NULL) {
        printf("[%d] ", aux->Numero);
        aux = aux->Prox;
    }
    printf("<- Fim\n");
}

int main() {
    TFila f;
    Inicializar(&f);

    printf("--- Teste Fila ---\n");
    Enfileirar(&f, 10);
    Enfileirar(&f, 20);
    Enfileirar(&f, 30);
    Imprimir(&f); // 10 20 30

    printf("Saiu: %d\n", Desenfileirar(&f));
    Imprimir(&f); // 20 30

    return 0;
}