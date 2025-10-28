#include <stdio.h>

// Acessa um elemento específico do array - O(1)
int acessarElemento(int arr[], int indice)
{
    return arr[indice]; // Operação única
}

// Operação aritmética simples - O(1)
int soma(int a, int b)
{
    return a + b; // Uma única operação
}

int main()
{
    int numeros[] = {10, 20, 30, 40, 50};

    printf("Elemento na posicao 2: %d\n", acessarElemento(numeros, 2));
    printf("Soma: %d\n", soma(15, 25));

    return 0;
}
