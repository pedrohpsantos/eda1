#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  TTemperaturas dados;
  int i, j;

  // 1. Leitura das quantidades
  printf("Digite a quantidade de cidades (medidas): ");
  scanf("%d", &dados.qtde_medidas);

  printf("Digite a quantidade de dias de leitura: ");
  scanf("%d", &dados.qtde_dias);

  // 2. Alocação dinâmica do vetor de TMedidas (Cidades)
  dados.medidas = (TMedidas *)malloc(dados.qtde_medidas * sizeof(TMedidas));
  if (dados.medidas == NULL) {
    printf("Erro de alocacao de memoria para medidas.\n");
    return 1;
  }

  // 3. Loop para ler os dados de cada cidade
  for (i = 0; i < dados.qtde_medidas; i++) {
    printf("\n--- Cidade %d ---\n", i + 1);
    printf("Nome da cidade: ");
    scanf("%s", dados.medidas[i].cidade); // Lê string sem espaços

    // Alocação dinâmica do vetor de float (Temperaturas) para esta cidade
    dados.medidas[i].temperatura = (float *)malloc(dados.qtde_dias * sizeof(float));
    if (dados.medidas[i].temperatura == NULL) {
      printf("Erro de alocacao de memoria para temperaturas.\n");
      return 1;
    }

    // Leitura das temperaturas
    for (j = 0; j < dados.qtde_dias; j++) {
      printf("Temperatura dia %d: ", j + 1);
      scanf("%f", &dados.medidas[i].temperatura[j]);
    }
  }

  // 4. Exibição dos dados
  printf("\n=== Relatorio de Temperaturas ===\n");
  for (i = 0; i < dados.qtde_medidas; i++) {
    printf("Cidade: %s -> [ ", dados.medidas[i].cidade);
    for (j = 0; j < dados.qtde_dias; j++) {
      printf("%.1f ", dados.medidas[i].temperatura[j]);
    }
    printf("]\n");
  }

  // 5. Liberação da memória (Free)
  // Primeiro libera os vetores internos (temperaturas)
  for (i = 0; i < dados.qtde_medidas; i++) {
    free(dados.medidas[i].temperatura);
  }
  // Depois libera o vetor principal (cidades)
  free(dados.medidas);

  return 0;
}