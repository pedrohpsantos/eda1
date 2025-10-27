/*
 * ============================================================================
 * PROGRAMA: Analise de Complexidade de Algoritmos
 * ============================================================================
 *
 * Este programa compara 5 algoritmos de ordenacao usando dados reais.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ============================================================================
// ESTRUTURA: Representa uma cidade
// ============================================================================
typedef struct
{
    char nome[100];
    char uf[3];
    int populacao;
} Cidade;

// ============================================================================
// ALGORITMOS DE ORDENACAO
// ============================================================================

// ---------- 1. BUBBLE SORT - O(n^2) ----------
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// ---------- 2. SELECTION SORT - O(n^2) ----------
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[menor])
            {
                menor = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[menor];
        arr[menor] = temp;
    }
}

// ---------- 3. INSERTION SORT - O(n^2) ----------
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// ---------- 4. MERGE SORT - O(n log n) ----------
void merge(int arr[], int esq, int meio, int dir)
{
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[esq + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esq;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int esq, int dir)
{
    if (esq < dir)
    {
        int meio = esq + (dir - esq) / 2;
        mergeSort(arr, esq, meio);
        mergeSort(arr, meio + 1, dir);
        merge(arr, esq, meio, dir);
    }
}

// ---------- 5. QUICK SORT - O(n log n) ----------
int particionar(int arr[], int baixo, int alto)
{
    int pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++)
    {
        if (arr[j] <= pivo)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;

    return i + 1;
}

void quickSort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionar(arr, baixo, alto);
        quickSort(arr, baixo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}

// ============================================================================
// FUNCOES AUXILIARES
// ============================================================================

int lerArquivo(Cidade **cidades)
{
    FILE *fp = fopen("estimativa_2021.csv", "r");
    if (!fp)
    {
        printf("Erro: arquivo nao encontrado!\n");
        return -1;
    }

    char linha[500];
    int total = 0;

    fgets(linha, 500, fp);
    while (fgets(linha, 500, fp))
        total++;

    *cidades = malloc(total * sizeof(Cidade));

    rewind(fp);
    fgets(linha, 500, fp);

    int i = 0;
    while (fgets(linha, 500, fp) && i < total)
    {
        char *tok = strtok(linha, ";");

        if (tok)
            strcpy((*cidades)[i].uf, tok);
        tok = strtok(NULL, ";");
        tok = strtok(NULL, ";");
        tok = strtok(NULL, ";");
        if (tok)
            strcpy((*cidades)[i].nome, tok);
        tok = strtok(NULL, ";");
        if (tok)
            (*cidades)[i].populacao = atoi(tok);

        i++;
    }

    fclose(fp);
    return total;
}

void copiarPop(Cidade *cidades, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = cidades[i].populacao;
    }
}

void copiarArr(int *orig, int *dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = orig[i];
    }
}

void mostrarTop10(Cidade *cidades, int *arr, int total)
{
    printf("\n+------------------------------------------------------+\n");
    printf("|         TOP 10 CIDADES - POPULACAO 2010              |\n");
    printf("+------------------------------------------------------+\n\n");

    printf("  %-30s  %-4s  %12s\n", "CIDADE", "UF", "POPULACAO");
    printf("  ------------------------------------------------------\n");

    for (int pos = 0; pos < 10 && pos < total; pos++)
    {
        int pop = arr[total - 1 - pos];

        for (int i = 0; i < total; i++)
        {
            if (cidades[i].populacao == pop)
            {
                printf("  %-30s  %-4s  %12d\n",
                       cidades[i].nome, cidades[i].uf, pop);
                break;
            }
        }
    }
    printf("\n");
}

// ============================================================================
// MAIN
// ============================================================================
int main()
{
    Cidade *cidades = NULL;
    int *pop_orig = NULL;
    int *pop_temp = NULL;

    printf("\n");
    printf("+=========================================================+\n");
    printf("|     ANALISE DE COMPLEXIDADE - 5 ALGORITMOS              |\n");
    printf("+=========================================================+\n\n");

    printf("Carregando dados...\n");
    int total = lerArquivo(&cidades);

    if (total <= 0)
        return 1;

    printf("OK - %d cidades carregadas!\n\n", total);

    pop_orig = malloc(total * sizeof(int));
    pop_temp = malloc(total * sizeof(int));
    copiarPop(cidades, pop_orig, total);

    double tempos[5];
    char *nomes[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort"};

    printf("Testando algoritmos...\n\n");

    // Teste 1: Bubble Sort
    printf("[1/5] Bubble Sort (O(n^2))...");
    fflush(stdout);
    copiarArr(pop_orig, pop_temp, total);
    clock_t inicio = clock();
    bubbleSort(pop_temp, total);
    clock_t fim = clock();
    tempos[0] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %.4f seg\n", tempos[0]);

    // Teste 2: Selection Sort
    printf("[2/5] Selection Sort (O(n^2))...");
    fflush(stdout);
    copiarArr(pop_orig, pop_temp, total);
    inicio = clock();
    selectionSort(pop_temp, total);
    fim = clock();
    tempos[1] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %.4f seg\n", tempos[1]);

    // Teste 3: Insertion Sort
    printf("[3/5] Insertion Sort (O(n^2))...");
    fflush(stdout);
    copiarArr(pop_orig, pop_temp, total);
    inicio = clock();
    insertionSort(pop_temp, total);
    fim = clock();
    tempos[2] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %.4f seg\n", tempos[2]);

    // Teste 4: Merge Sort
    printf("[4/5] Merge Sort (O(n log n))...");
    fflush(stdout);
    copiarArr(pop_orig, pop_temp, total);
    inicio = clock();
    mergeSort(pop_temp, 0, total - 1);
    fim = clock();
    tempos[3] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %.4f seg\n", tempos[3]);

    // Teste 5: Quick Sort
    printf("[5/5] Quick Sort (O(n log n))...");
    fflush(stdout);
    copiarArr(pop_orig, pop_temp, total);
    inicio = clock();
    quickSort(pop_temp, 0, total - 1);
    fim = clock();
    tempos[4] = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf(" %.4f seg\n", tempos[4]);

    mostrarTop10(cidades, pop_temp, total);

    printf("+=========================================================+\n");
    printf("|                    RESUMO FINAL                         |\n");
    printf("+=========================================================+\n\n");

    printf("  Dataset: %d cidades\n\n", total);

    printf("  %-20s  %12s  %12s\n", "ALGORITMO", "TEMPO", "COMPLEXIDADE");
    printf("  ---------------------------------------------------------\n");

    char *complex[] = {"O(n^2)", "O(n^2)", "O(n^2)", "O(n log n)", "O(n log n)"};

    for (int i = 0; i < 5; i++)
    {
        printf("  %-20s  %10.4f s  %12s\n", nomes[i], tempos[i], complex[i]);
    }

    int rapido = 0;
    for (int i = 1; i < 5; i++)
    {
        if (tempos[i] < tempos[rapido])
            rapido = i;
    }

    printf("\n  >> Mais rapido: %s\n\n", nomes[rapido]);

    printf("  Comparacao:\n");
    for (int i = 0; i < 5; i++)
    {
        if (i != rapido)
        {
            double vezes = tempos[i] / tempos[rapido];
            printf("     - %s eh %.0fx mais lento\n", nomes[i], vezes);
        }
    }

    printf("\n");
    printf("+=========================================================+\n");
    printf("|                  ANALISE CONCLUIDA!                     |\n");
    printf("+=========================================================+\n\n");

    free(cidades);
    free(pop_orig);
    free(pop_temp);

    return 0;
}