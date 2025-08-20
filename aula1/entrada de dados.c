#include <stdio.h>

int main()
{
    int idade;
    float altura;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("\nIdade: %d, Altura: %.2f\n", idade, altura);
    return 0;
}
