#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necessária para malloc() e free()

// Definição da estrutura usando um apelido (typedef)
typedef struct
{
    char nome[100];
    int id;
} Funcionario;

int main()
{
    // Graças ao typedef, podemos declarar o ponteiro de forma mais limpa.
    Funcionario *ptr_func;

    // A lógica é a mesma, mas usamos o nosso novo tipo "Funcionario"
    ptr_func = (Funcionario *)malloc(sizeof(Funcionario));

    if (ptr_func == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // O operador '->' funciona da mesma forma, independentemente de como a struct foi declarada.
    strcpy(ptr_func->nome, "Carlos Lima");
    ptr_func->id = 1030;

    // Lendo e exibindo os dados usando o ponteiro
    printf("--- Ponteiro com 'typedef struct' ---\n");
    printf("Nome: %s\n", ptr_func->nome);
    printf("ID: %d\n", ptr_func->id);

    // Liberando a memoria
    free(ptr_func);

    return 0;
}