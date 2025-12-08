#include <stdio.h>
#include <string.h>

int Q5(char vetor[], int tamanho)
{
    int pqtde = 0, j, i;
    char chave;

    for (i = 1; i < tamanho; i++)
    {
        chave = vetor[i];
        j = i - 1;

        // Move elementos enquanto forem menores que a chave (Decrescente)
        while (j >= 0 && vetor[j] < chave)
        {
            vetor[j + 1] = vetor[j];
            j--;
            pqtde++; // Conta quantas movimentações (shifts) ocorreram
        }
        vetor[j + 1] = chave;
    }
    return pqtde;
}

int main()
{
    // Parâmetro: Seu último sobrenome em minúsculas
    char sobrenome[10];
    printf("Coloque seu ultimo nome em letras minusculas: ");
    scanf("%9s", sobrenome);
    int tamanho = strlen(sobrenome);

    printf("--- Execucao Q5 ---\n");
    printf("Entrada inicial: %s\n", sobrenome);

    int resultado = Q5(sobrenome, tamanho);

    printf("Resultado (R - movimentacoes): %d\n", resultado); // Resposta para item 5.1
    printf("Nome final: %s\n", sobrenome);                    // Resposta para item 5.2

    return 0;
}