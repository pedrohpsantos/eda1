#include <stdio.h>
#include <stdlib.h>

// Tipo topo
typedef struct no
{
    char caracter;
    struct no *proximo;
} No;

// Função forma_par
int forma_par(char f, char d)
{
    switch (f)
    {
    case ')':
        if (d == '(')
            return 1;
        else
            return 0;
        break;

    case ']':
        if (d == '[')
            return 1;
        else
            return 0;

    case '}':
        if (d == '{')
            return 1;
        else
            return 0;

    default:
        break;
    }
}

// Questão 1
No *Empilha(No *topo, char valor)
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->caracter = valor;
    novoNo->proximo = topo;
    return novoNo;
}

// Questão 2
No *Desempilha(No *topo)
{
    No *removeNo = topo;
    topo = topo->proximo;
    free(removeNo);
    return topo;
}

// Questão 3
int identifica_formacao(char expressao[])
{
    No *topo = NULL;
    for (int i = 0; expressao[i] != '\0'; i++)
    {
        char atual = expressao[i];
        if (atual == '(' || atual == '[' || atual == '{')
            topo = Empilha(topo, atual);
        else if (atual == ')' || atual == ']' || atual == '}')
        {
            if (topo == NULL)
                return 0;
            if (!forma_par(atual, topo->caracter))
                return 0;
            topo = Desempilha(topo);
        }
    }
    return (topo == NULL);
}

// Função Main
int main()
{
    char exp[50];
    int retorno;
    scanf("%49[^\n]", exp);
    retorno = identifica_formacao(exp);
    if (retorno == 1)
        printf("BALANCEADA\n");
    else
        printf("DESBALANCEADA\n");
    return 0;
}