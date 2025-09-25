#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>

void alocaEstoque(TEstoque *pEstoque) {
  int quantidadeParaAlocar;
  scanf("%d", &quantidadeParaAlocar);

  pEstoque->qtdeProdutos = quantidadeParaAlocar;

  pEstoque->produtos =
      (TProduto *)calloc(quantidadeParaAlocar, sizeof(TProduto));
}

void incluirProdutos(TEstoque *pEstoque) {
  int contador = pEstoque->qtdeProdutos;
  for (int i = 0; i < contador; i++) {
    scanf("%d", &pEstoque->produtos[i].id);
    scanf("%d", &pEstoque->produtos[i].quantidade);
    scanf("%f", &pEstoque->produtos[i].preco);
  }
}

void listarProdutos(TEstoque *pEstoque) {
  int contador = pEstoque->qtdeProdutos;
  for (int i = 0; i < contador; i++) {
    int pId = pEstoque->produtos[i].id;
    int pQ = pEstoque->produtos[i].quantidade;
    float pP = pEstoque->produtos[i].preco;

    printf("ID: %d, Qt: %d, Preço: %.2f\n", pId, pQ, pP);
  }
}

void desalocaEstoque(TEstoque *pEstoque) {
  free(pEstoque->produtos);
  pEstoque->produtos = NULL;
  pEstoque->qtdeProdutos = 0;
  printf("Memória liberada com sucesso\n");
}

int main() {
  TEstoque Estoque;
  alocaEstoque(&Estoque);
  incluirProdutos(&Estoque);
  listarProdutos(&Estoque);
  desalocaEstoque(&Estoque);
  return 0;
}
