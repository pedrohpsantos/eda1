#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 50

typedef struct {
  int id;
  char nome[50];
  float preco;
  int quantidade;
} Produto;

void listarProdutos(Produto *vetor, int qtd) {
  if (qtd == 0) {
    printf("\nNenhum produto cadastrado.\n");
    return;
  }
  printf("\n=== Lista de Produtos ===\n");
  float totalGeral = 0.0;
  for (int i = 0; i < qtd; i++) {
    float totalItem = vetor[i].preco * vetor[i].quantidade;
    totalGeral += totalItem;
    printf("ID: %d | %s | Qtd: %d | R$ %.2f un. | Total: R$ %.2f\n", 
           vetor[i].id, vetor[i].nome, vetor[i].quantidade, vetor[i].preco, totalItem);
  }
  printf("-------------------------\n");
  printf("Valor Total em Estoque: R$ %.2f\n", totalGeral);
}

int main() {
  Produto estoque[MAX_PRODUTOS];
  int qtdAtual = 0;
  int opcao;

  do {
    printf("\n--- SUPERMERCADO ---\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Listar Produtos\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      if (qtdAtual < MAX_PRODUTOS) {
        printf("\nDigite o ID: ");
        scanf("%d", &estoque[qtdAtual].id);
        
        printf("Digite o Nome: ");
        scanf("%s", estoque[qtdAtual].nome); // Leitura simples sem espacos
        
        printf("Digite o Preco: ");
        scanf("%f", &estoque[qtdAtual].preco);
        
        printf("Digite a Quantidade: ");
        scanf("%d", &estoque[qtdAtual].quantidade);
        
        qtdAtual++;
        printf("Produto cadastrado com sucesso!\n");
      } else {
        printf("Estoque cheio!\n");
      }
      break;

    case 2:
      listarProdutos(estoque, qtdAtual);
      break;

    case 3:
      printf("Encerrando sistema...\n");
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 3);

  return 0;
}