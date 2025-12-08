#include <stdio.h>
#include <string.h>
#include <math.h>   // Necessário para a função floor
#include <stdlib.h> // Para qsort

// Função auxiliar para ordenar caracteres (para preparar a entrada da Q3)
int compararChar(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int Q3(char *Nome, int tamanho, int matricula)
{
    int inicio = 0, meio, fim = tamanho - 1, pcont = 0;

    // A chave é o caractere na posição (matricula % 10) do vetor ORDENADO
    char chave = Nome[matricula % 10];

    printf("Chave de busca (Nome[%d %% 10]): '%c'\n", matricula, chave);

    while (inicio <= fim)
    { // Correção: OCR leu "<<" mas busca binária é "<="
        pcont++;
        meio = floor((inicio + fim) / 2.0);

        // Debug para acompanhar a busca binária
        // printf("Passo %d: inicio=%d, fim=%d, meio=%d, Nome[meio]='%c'\n", pcont, inicio, fim, meio, Nome[meio]);

        if (chave == Nome[meio])
            break;
        else if (chave < Nome[meio]) // Correção: assumindo lógica padrão se OCR falhou
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return pcont;
}

int main()
{
    // Parâmetros: Nome completo, tamanho, matrícula
    char nomeOrdenado[100];
    int matricula;

    printf("Coloque sua matricula: ");
    scanf("%d", &matricula);

    getchar();

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(nomeOrdenado, sizeof(nomeOrdenado), stdin);
    nomeOrdenado[strcspn(nomeOrdenado, "\n")] = 0;

    int tamanho = strlen(nomeOrdenado);

    // Ordenando o nome antes de passar para Q3, conforme enunciado (espaços vêm primeiro na tabela ASCII)
    qsort(nomeOrdenado, tamanho, sizeof(char), compararChar);

    printf("--- Execucao Q3 ---\n");
    printf("Nome Ordenado: [%s]\n", nomeOrdenado);

    int resultado = Q3(nomeOrdenado, tamanho, matricula);

    printf("Resultado (pcont): %d\n", resultado);
    return 0;
}