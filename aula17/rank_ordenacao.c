#include <stdio.h>
#include "ordenacoes.h"

int main()
{
    FILE *fp = fopen("estimativa_2021.csv", "r");
    if (!fp)
    {
        printf("Erro\n");
        return 1;
    }
    
    return 0;
}