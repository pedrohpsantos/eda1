#include <stdio.h>
#include <string.h>

// Modelo de estrutura
struct Produto
{
    char nome[100]; 
    int codigo;
    double preco;
};

int main()
{
    // Declaramos uma variável "meu_produto" do tipo "struct Produto"
    struct Produto meu_produto;

    // Adicionando valores na variável
    strcpy(meu_produto.nome, "Livro");
    meu_produto.codigo = 789234;
    meu_produto.preco = 5.00;

    // Imprimindo os valores na variável
    printf("Nome do Produto: %s\n", meu_produto.nome);
    printf("Codigo do produto: %d\n", meu_produto.codigo);
    printf("Preco: R$ %.2lf\n", meu_produto.preco);
}
