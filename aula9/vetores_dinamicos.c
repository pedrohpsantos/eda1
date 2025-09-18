#include <stdio.h>
#include <stdlib.h> // Para malloc, calloc e free

int main() {
    int *v_malloc, *v_calloc;
    int n_elementos = 10;

    //* --- Alocação com MALLOC ---
    // Aloca memória para 'n_elementos' inteiros. O conteúdo é indefinido ("lixo").
    v_malloc = (int*) malloc(n_elementos * sizeof(int));

    //* --- Alocação com CALLOC ---
    // Aloca memória para 'n_elementos' inteiros E inicializa tudo com 0.
    v_calloc = (int*) calloc(n_elementos, sizeof(int));

    //* VERIFICAÇÃO: É uma boa prática sempre checar se a alocação deu certo.
    if (v_malloc == NULL || v_calloc == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1; // Encerra o programa indicando um erro
    }

    printf("Conteudo do vetor alocado com malloc (lixo de memoria):\n");
    for (int i = 0; i < n_elementos; i++) {
        printf("%d ", v_malloc[i]); // Imprime os valores aleatórios
    }
    printf("\n\n");

    printf("Conteudo do vetor alocado com calloc (inicializado com zeros):\n");
    for (int i = 0; i < n_elementos; i++) {
        printf("%d ", v_calloc[i]); // Imprime os zeros
    }
    printf("\n");

    //! Sempre libere a memória que você alocou para evitar "memory leaks" (vazamento de memória).
    free(v_malloc);
    free(v_calloc);

    return 0;
}