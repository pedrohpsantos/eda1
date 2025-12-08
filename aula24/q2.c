#include <stdio.h>
#include <string.h>

char letraCorrespondente(int P)
{
    // P=0 corresponde à letra 'a', P=25 corresponde à letra 'z'.
    P = P % 26;
    return 'a' + P;
}

int Q2(char *NomeCompleto, int matricula)
{
    int p = 0, pvez = 0;

    // Calcula a chave usando os dois últimos dígitos da matrícula
    char chave = letraCorrespondente(matricula % 100);

    printf("Chave calculada (letra): '%c'\n", chave); // Debug para você ver qual letra é

    while (NomeCompleto[p] != '\0')
    {
        if (chave == NomeCompleto[p])
            pvez++;
        p++;
    }
    return pvez;
}

int main()
{
    // Parâmetro: Nome completo minúsculo e matrícula
    char nomeCompleto[100];
    int matricula;

    printf("Coloque sua matricula: ");
    scanf("%d", &matricula);

    getchar();

    printf("Digite seu nome completo em letras minusculas:\n");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    nomeCompleto[strcspn(nomeCompleto, "\n")] = 0;

    printf("--- Execucao Q2 ---\n");
    printf("Nome: %s\n", nomeCompleto);
    printf("Matricula: %d\n", matricula);

    int resultado = Q2(nomeCompleto, matricula);

    printf("Resultado (pvez): %d\n", resultado);
    return 0;
}