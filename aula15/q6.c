#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef TPRODUTO_H
#define TPRODUTO_H

typedef struct
{
   int codigo;
   float preco;
} TProduto;
#endif

void atualizaPreco(TProduto prod)
{
   prod.preco = prod.preco + 8;
}

int Q6(TProduto *prod)
{
   atualizaPreco(*prod);
   return prod->preco;
}

int main()
{
   TProduto p1;
   printf("Digite o codigo e o preco do produto (ambos sua matricula):\n");
   scanf("%d %f", &p1.codigo, &p1.preco);
   printf("Resposta: %d\n", Q6(&p1));
   return 0;
}