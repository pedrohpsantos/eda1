// main.c
#include "TListas.h"
#include "ListasFuncoes.c"

int main() {
    Descritor lista;
    lista.Inicio = NULL;
    lista.Final = NULL;
    lista.Qtde = 0;

    // Adicionando elementos na lista
    insereInicio(&lista, 10);
    insereInicio(&lista, 20);
    insereInicio(&lista, 30);

    // Imprimindo os elementos da lista
    No *temp = lista.Inicio;
    while (temp != NULL) {
        printf("%d ", temp->Numero);
        temp = temp->Prox;
    }
    printf("\n");

    return 0;
}