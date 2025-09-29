#include <stdio.h>

int main()
{

    double sal, nwsal, por, rea;
    scanf("%lf", &sal);

    if (sal <= 400)
    {
        por = 0.15;
        nwsal = sal * por;
        rea = nwsal + sal;
    }
    else if (sal <= 800)
    {
        por = 0.12;
        nwsal = sal * por;
        rea = nwsal + sal;
    }
    else if (sal <= 1200)
    {
        por = 0.1;
        nwsal = sal * por;
        rea = nwsal + sal;
    }
    else if (sal <= 2000)
    {
        por = 0.07;
        nwsal = sal * por;
        rea = nwsal + sal;
    }
    else
    {
        por = 0.04;
        nwsal = sal * por;
        rea = nwsal + sal;
    }
    printf("Novo salario: %.2lf\n", rea);
    printf("Reajuste ganho: %.2lf\n", nwsal);
    printf("Em percentual: %.0lf %%\n", por * 100);

    return 0;
}