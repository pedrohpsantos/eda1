#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int separa(char v[], int p, int r, long int *qtd)
{
    char pivo = v[r];
    char aux;
    int i = p - 1;

    for (int k = p; k <= r - 1; k++)
    {
        if (v[k] <= pivo)
        {
            i++;
            aux = v[i];
            v[i] = v[k];
            v[k] = aux;
            (*qtd)++;
        }
    }

    aux = v[i + 1];
    v[i + 1] = v[r];
    v[r] = aux;
    (*qtd)++;

    return i + 1;
}

void quicksort(char v[], int p, int r, long int *qtd)
{
    if (p >= r)
        return;

    int indice = separa(v, p, r, qtd);
    quicksort(v, p, indice - 1, qtd);
    quicksort(v, indice + 1, r, qtd);
}

int main()
{
    char v[1024];
    long int qt_trocas = 0;
    int n;
    if (fgets(v, sizeof(v), stdin) != NULL)
    {
        v[strcspn(v, "\n")] = '\0'; // Remove a nova linha, se existir
    }
    n = strlen(v); // Obtém o tamanho do vetor de caracteres
    printf("Antes : %s\n", v);
    quicksort(v, 0, n - 1, &qt_trocas);
    printf("Depois: %s\n", v);
    printf("Trocas: %ld\n", qt_trocas);
    return 0;
}