#include <stdio.h>
#include <stdlib.h>

// Estrutura dos registros do dataset de pessoas
typedef struct
{
    char name[100];
    int age;
} TPessoa;

// Estrutura do nó da árvore ABP:
// Esta ABP tem agees menores à left da raíz e agees maiores à right da root.
typedef struct TABPNo
{
    int age;
    int index; // Posição no dataset de pessoas
    struct TABPNo *left;
    struct TABPNo *right;
} TABPNo;

TPessoa Data[100]; // Defini um tamanho arbitráio (ex: 100) para o vetor global
int dataCount;

// Protótipo da função AlocaNo (necessário declarar antes de usar no Fill)
TABPNo *AlocaNo(TABPNo *root, int age, int index);

// Função Fill: Gera uma ABP a partir de um um dataset (conjunto de registros do tipo TPessoa).
// dataCount é uma variável global do sistema. Armazena o total de nós da ABP.
TABPNo *Fill(TPessoa dataset[], int qtRegistros)
{
    TABPNo *root = NULL;
    dataCount = 0;
    for (int i = 0; i < qtRegistros; i++)
    {
        Data[i] = dataset[i];
        root = AlocaNo(root, Data[i].age, i);
        dataCount++;
    }
    return root;
}

// Exercicio 1
TABPNo *AlocaNo(TABPNo *root, int age, int index)
{
    // 1. Caso Base: Encontrou um espaço vazio. Cria o nó aqui.
    if (root == NULL)
    {
        TABPNo *novoNo = (TABPNo *)malloc(sizeof(TABPNo));
        if (novoNo != NULL) // Boa prática: checar se o malloc funcionou
        {
            novoNo->age = age;
            novoNo->index = index;
            novoNo->left = NULL;
            novoNo->right = NULL;
        }
        return novoNo;
    }

    // 2. Recursão: Navega para encontrar o local correto
    if (age < root->age)
    {
        // Se é menor, insere na sub-árvore da esquerda
        // E atualiza o ponteiro left com o resultado (caso ele mude)
        root->left = AlocaNo(root->left, age, index);
    }
    else
    {
        // Se é maior ou igual, insere na direita
        root->right = AlocaNo(root->right, age, index);
    }

    // Retorna a raiz atual para manter a estrutura conectada
    return root;
}

// Exercicio 2
void PrintRelatorio(TABPNo *root)
{
    if (root != NULL)
    {
        // 1. Visita tudo que é menor (Esquerda) primeiro
        PrintRelatorio(root->left);

        // 2. Processa o nó atual (Raiz)
        // Acessamos o vetor global Data usando o index guardado no nó
        printf("Idade: %d, Nome: %s\n", root->age, Data[root->index].name);

        // 3. Visita tudo que é maior (Direita) depois
        PrintRelatorio(root->right);
    }
}

// Exercicio 3
TABPNo *Busca(TABPNo *root, int age)
{
    // Caso base: árvore vazia ou encontrou o age
    if (root == NULL || root->age == age)
    {
        return root;
    }

    // Se age buscado é menor, procura na left
    if (age < root->age)
    {
        return Busca(root->left, age);
    }

    // Caso contrário, procura na right
    return Busca(root->right, age);
}

// Exercicio 4
int DesalocaABP(TABPNo *root)
{
    if (!root)
        return 0; // if(!root) é o mesmo que if(root == NULL)

    // Primeiro resolvemos os filhos e guardamos a soma deles
    int nosFilhos = DesalocaABP(root->left) + DesalocaABP(root->right);

    free(root); // Apagamos o nó atual

    return nosFilhos + 1; // Retornamos a soma dos filhos + 1 (o nó atual)
}

int main()
{
    TABPNo *No;
    TABPNo *root = NULL;
    int Idade, QtNosDesalocados;
    char FonteDados;
    // Definição de qual fonte de dados será testada. Veja nos exemplos de entrada de dados:
    scanf(" %c", &FonteDados);
    // Aloca vários nós contendo idade e posição do dataset (veja tipo TABPNo) à árvore ABP :
    TPessoa dadosTemporarios[1];
    root = Fill(dadosTemporarios, 0);

    scanf("%d", &Idade);                  // Idade usada no teste de busca. Veja nos exemplos de entrada de dados.
    PrintRelatorio(root);                 // Imprime um relatório por ordem de Idade. Veja nos exemplos de saída.
    No = Busca(root, Idade);              // Função de busca de uma idade na ABP
    QtNosDesalocados = DesalocaABP(root); // Função para desalocar ABP e retornar a qt de nós desalocados

    return 0;
}