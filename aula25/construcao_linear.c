#include <stdio.h>
#include <stdlib.h>

// Nó adaptado para CHAR conforme o PDF de construção
typedef struct NoChar
{
    char dado;
    struct NoChar *esq;
    struct NoChar *dir;
} NoChar;

NoChar *criarNoChar(char valor)
{
    NoChar *novo = (NoChar *)malloc(sizeof(NoChar));
    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função de Construção baseada no slide 3
// 'str': a string completa (ex: "AB..C..")
// 'idx': ponteiro para controlar a posição atual na leitura da string
NoChar *construirPorString(char *str, int *idx)
{
    // Lê o caractere atual e avança o índice
    char dado = str[*idx];
    (*idx)++;

    // Se acabou a string ou é um marcador de vazio (.), retorna NULL
    if (dado == '\0' || dado == '.')
    {
        return NULL;
    }

    // 1. Cria a Raiz
    NoChar *novo = criarNoChar(dado);

    // 2. Constrói recursivamente a Esquerda
    novo->esq = construirPorString(str, idx);

    // 3. Constrói recursivamente a Direita
    novo->dir = construirPorString(str, idx);

    return novo;
}

// Função auxiliar para imprimir e verificar se funcionou (Pré-ordem)
void imprimirPreOrdem(NoChar *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->dado);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

int main()
{
    // Exemplo do slide 2: "ABG..C.DE.F...."
    // A é raiz. B é esquerda de A. G é esquerda de B...
    char notacao[] = "ABG..C.DE.F....";
    int indice = 0;

    printf("String original: %s\n", notacao);

    NoChar *raiz = construirPorString(notacao, &indice);

    printf("Arvore construida (Pre-ordem): ");
    imprimirPreOrdem(raiz);
    printf("\n");

    return 0;
}