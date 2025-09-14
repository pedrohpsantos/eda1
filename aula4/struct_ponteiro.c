#include <stdio.h>
#include <stdlib.h> // Necessária para malloc() e free()
#include <string.h>

struct Funcionario {
  char nome[100];
  int id;
};

int main() {
  // Declaramos um ponteiro que irá apontar para uma variável do tipo "struct
  // Funcionario"
  struct Funcionario *ptr_func;

  // Usamos malloc() para reservar na memória o espaço exato que uma "struct
  // Funcionario" precisa.
  ptr_func = (struct Funcionario *)malloc(sizeof(struct Funcionario));

  if (ptr_func == NULL) {
    printf("Erro ao alocar memoria!\n");
    return 1; // Termina o programa com um código de erro.
  }

  strcpy(ptr_func->nome, "Ana Souza");
  ptr_func->id = 1020;

  // Lendo e exibindo os dados usando o ponteiro
  printf("--- Ponteiro com 'struct' ---\n");
  printf("Nome: %s\n", ptr_func->nome);
  printf("ID: %d\n", ptr_func->id);

  // Sempre que usamos malloc(), devemos usar free() no final para liberar a
  // memória que foi alocada, evitando "vazamentos de memória".
  free(ptr_func);

  return 0;
}