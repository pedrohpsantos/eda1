// ListasFuncoes.c
#include "TListas.h"

// Função para inserir um novo nó no início da lista
void insereInicio(Descritor *desc, int num) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Memória insuficiente.\n");
        return;
    }

    novo->Numero = num;
    novo->Prox = desc->Inicio;
    desc->Inicio = novo;

    if (desc->Qtde == 0) {
        desc->Final = novo;
    }

    desc->Qtde++;
}