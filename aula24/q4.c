#include <stdio.h>
#include <string.h>

int Q4(char *vet, int tam)
{
    int i, j, pcont = 0;
    char aux;

    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
            // Se o elemento da esquerda for MENOR que o da direita, troca.
            // Isso joga os maiores para o início (Decrescente).
            if (vet[i] < vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                pcont++;
            }
        }
    }
    return pcont;
}

int main()
{
    // Parâmetro: Seu primeiro nome em minúsculas
    char nome[10];
    printf("Coloque seu primeiro nome em letras minusculas: ");
    scanf("%9s", nome);
    int tamanho = strlen(nome);

    printf("--- Execucao Q4 ---\n");
    printf("Entrada inicial: %s\n", nome);

    int resultado = Q4(nome, tamanho);

    printf("Resultado (R - trocas): %d\n", resultado); // Resposta para item 4.1
    printf("Nome final: %s\n", nome);                  // Resposta para item 4.2

    return 0;
}