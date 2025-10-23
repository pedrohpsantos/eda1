#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Q1(int valor)
{
    int *ptr, *pnumeros, pn = valor % 10, pp, psoma = 0;
    if (pn < 2)
        pn = 7 - pn;
    pnumeros = (int *)malloc(pn * sizeof(int));
    ptr = pnumeros;
    for (pp = 0; pp < pn; pp++)
    {
        *ptr = valor % 10;
        valor = valor / 10;
        ptr++;
    }
    for (pp = 0; pp < pn; pp++)
    {
        if ((pnumeros[pp] % 2) != 0)
            psoma = psoma + pnumeros[pp];
    }
    return (psoma);
}

int main()
{
    int mat;
    printf("Coloque sua matricula: ");
    scanf("%d", &mat);
    printf("Resposta: %d\n", Q1(mat));
    return 0;
}