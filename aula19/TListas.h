// TListas.h

#ifndef TLISTAS_H
#define TLISTAS_H

#include <stdio.h>
#include <stdlib.h>

// Definição do tipo nó para lista encadeada
typedef struct No {
    int Numero;
    struct No *Prox;
} No;

// Definição do tipo descritor para lista encadeada
typedef struct {
    No *Inicio;
    No *Final;
    int Qtde;
} Descritor;

#endif