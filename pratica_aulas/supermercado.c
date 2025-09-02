#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirEstoque(const char *produtos[], int estoque[])
{
    printf("---------------------------\n");
    printf("ESTADO ATUAL DO ESTOQUE\n");
    printf("---------------------------\n");
    printf("ID | Produto      | Qtd\n");
    printf("---------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%-2d | %-12s | %d\n", i, produtos[i], estoque[i]);
    }
    printf("---------------------------\n");
}

void comprarProduto(const char *produtos[], int estoque[])
{
    int id, quantidade;

    printf("\nDigite o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    // Validação do ID
    if (id < 0 || id >= 10)
    {
        printf("Erro: ID de produto invalido!\n");
        return;
    }

    printf("Digite a quantidade que deseja comprar de %s: ", produtos[id]);
    scanf("%d", &quantidade);

    // Validação da quantidade
    if (quantidade <= 0)
    {
        printf("Erro: A quantidade deve ser positiva!\n");
        return;
    }

    if (estoque[id] >= quantidade)
    {
        estoque[id] -= quantidade; // Diminui o estoque
        printf("\nCompra realizada com sucesso!\n");
    }
    else
    {
        printf("\nErro: Estoque insuficiente! Temos apenas %d unidade(s) de %s.\n", estoque[id], produtos[id]);
    }
}

void adicionarEstoque(const char *produtos[], int estoque[])
{
    int id, quantidade;

    printf("\nDigite o ID do produto para adicionar ao estoque: ");
    scanf("%d", &id);

    // Validação do ID
    if (id < 0 || id >= 10)
    {
        printf("Erro: ID de produto invalido!\n");
        return;
    }

    printf("Digite a quantidade a ser adicionada ao estoque de %s: ", produtos[id]);
    scanf("%d", &quantidade);

    // Validação da quantidade
    if (quantidade <= 0)
    {
        printf("Erro: A quantidade deve ser positiva!\n");
        return;
    }

    estoque[id] += quantidade; // Aumenta o estoque
    printf("\nEstoque atualizado com sucesso!\n");
}

int main()
{
    // Gerador de numeros aleatorios
    srand(time(NULL));

    // "const char*" para indicar que são strings que não serão alteradas.
    const char *produtos[10] = {"Feijao", "Arroz", "Oleo", "Farinha", "Macarrao", "Biscoito", "Refrigerante", "Abacaxi", "Maça", "Banana"};
    int opc, i, estoque[10];

    // Loop para inicializar o estoque com valores aleatórios de 0 a 100
    printf("Inicializando o estoque com valores aleatórios\n");
    for (i = 0; i < 10; i++)
        estoque[i] = rand() % 101; // Gera um número entre 0 e 100

    do
    {
        // Imprime o estado atual do estoque
        imprimirEstoque(produtos, estoque);

        // Imprime o menu de opções
        printf("\n--- MENU DE OPCOES ---\n");
        printf("1 - Comprar produto\n");
        printf("2 - Adicionar ao estoque\n");
        printf("0 - Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            comprarProduto(produtos, estoque);
            break;
        case 2:
            adicionarEstoque(produtos, estoque);
            break;
        case 0:
            printf("\nSaindo do programa. Obrigado!\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }

        printf("\n");

    } while (opc != 0);

    return 0;
}
