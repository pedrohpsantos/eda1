#include <stdio.h>

int main()
{
    int a = 10;
    int b = 5;
    float c = 15.5;
    float d = 2.5;

    printf("Operações com inteiros:\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);

    printf("\nOperações com floats:\n");
    printf("%.2f + %.2f = %.2f\n", c, d, c + d);
    printf("%.2f - %.2f = %.2f\n", c, d, c - d);
    printf("%.2f * %.2f = %.2f\n", c, d, c * d);
    printf("%.2f / %.2f = %.2f\n", c, d, c / d);

    return 0;
}