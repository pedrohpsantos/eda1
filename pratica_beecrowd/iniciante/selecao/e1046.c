#include <stdio.h>

int main()
{
    int hi, hf, t;
    scanf("%d %d", &hi, &hf);
    if (hi < hf)
    {
        t = hf - hi;
    }
    else
    {
        t = 24 - hi + hf;
    }
    printf("O JOGO DUROU %d HORA(S)\n", t);
    return 0;
}