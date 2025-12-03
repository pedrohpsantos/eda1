#include <stdio.h>
#include <stdlib.h>

// Struct do Nó (Dado inserido diretamente aqui)
typedef struct TNo {
    int Numero;           // Dado direto (sem struct Info)
    struct TNo *Prox;
} TNo;

// Struct da Pilha (Descritor)
typedef struct {
    TNo *Topo;
    int Qtde;
} TPilha;

// --- Funções ---

void Inicializar(TPilha *p) {
    p->Topo = NULL;
    p->Qtde = 0;
}

void Empilhar(TPilha *p, int valor) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (novo == NULL) return;

    novo->Numero = valor;
    novo->Prox = p->Topo; // O novo aponta para o antigo topo
    p->Topo = novo;       // Atualiza o topo
    p->Qtde++;
}

int Desempilhar(TPilha *p) {
    if (p->Topo == NULL) {
        printf("Pilha Vazia!\n");
        return -1;
    }

    TNo *aux = p->Topo;
    int valor = aux->Numero;

    p->Topo = p->Topo->Prox; // O topo desce
    free(aux);
    p->Qtde--;
    
    return valor;
}

void Imprimir(TPilha *p) {
    TNo *aux = p->Topo;
    printf("Pilha: Topo -> ");
    while (aux != NULL) {
        printf("[%d] ", aux->Numero);
        aux = aux->Prox;
    }
    printf("\n");
}

int main() {
    TPilha p;
    Inicializar(&p);

    printf("--- Teste Pilha ---\n");
    Empilhar(&p, 10);
    Empilhar(&p, 20);
    Empilhar(&p, 30);
    Imprimir(&p); // 30 20 10

    printf("Desempilhou: %d\n", Desempilhar(&p));
    Imprimir(&p); // 20 10

    return 0;
}