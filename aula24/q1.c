#include <stdio.h>
#include <string.h>

int Q1(char *Nome, int qtde)
{
    int pc = 0;

    // Condição de parada da recursão
    if (*Nome == '\0')
        return qtde * 2;

    // Loop para contar caracteres até o fim da string atual
    while (Nome[pc] != '\0')
        pc++;

    // Chamada recursiva avançando o ponteiro Nome em 1 caractere
    return Q1(Nome + 1, qtde + pc);
}

int main()
{
    // Parâmetro: Seu último sobrenome e 0
    char sobrenome[10];
    printf("Coloque seu ultimo nome em letras minusculas: ");
    scanf("%9s", sobrenome);

    printf("--- Execucao Q1 ---\n");
    printf("Entrada: %s\n", sobrenome);

    int resultado = Q1(sobrenome, 0);

    printf("Resultado retornado: %d\n", resultado);
    return 0;
}