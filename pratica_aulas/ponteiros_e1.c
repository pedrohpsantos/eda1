#include <stdio.h>

int main()
{
    int num, *ptr;
    num = 123;
    ptr = &num;
    printf("Valor da variavel: %d\n", num);
    printf("Endereço da variavel: %p\n\n", &num);

    printf("Valor do ponteiro (endereço armazenado): %p\n", ptr);
    printf("Endereço do ponteiro: %p\n", &ptr);
    printf("Conteudo apontado pelo ponteiro: %d\n", *ptr);
    return 0;
}