#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Necessário para strtok e strdup

// Definição da estrutura do Nó da Árvore
typedef struct No
{
    int chaveComposta;   // Soma: Idade + Tamanho do Tumor
    int linhaCSV;        // Posição original no arquivo
    struct No *esquerda; // Ponteiro para a subárvore esquerda (menores)
    struct No *direita;  // Ponteiro para a subárvore direita (maiores)
} TNo;

// --- FUNÇÕES AUXILIARES DE ARQUIVO ---

// Função para pegar uma coluna específica de uma linha CSV
// Retorna uma string alocada dinamicamente (precisa de free depois)
char *get_field(char *linha, int numColuna)
{
    char *token;
    char *linhaCopia = strdup(linha); // Faz uma cópia segura da linha
    char *resultado = NULL;

    token = strtok(linhaCopia, ",;"); // Quebra por vírgula ou ponto-e-vírgula
    int contador = 0;

    while (token != NULL)
    {
        if (contador == numColuna)
        {
            resultado = strdup(token); // Copia o dado encontrado
            break;
        }
        token = strtok(NULL, ",;");
        contador++;
    }
    free(linhaCopia); // Limpa a memória auxiliar
    return resultado;
}

// Função para buscar e imprimir uma linha específica do arquivo
void imprimirLinhaDoArquivo(char *nomeArquivo, int linhaAlvo)
{
    FILE *f = fopen(nomeArquivo, "r");
    if (!f)
        return;

    char texto[1024];
    int linhaAtual = 1;

    // Lê o arquivo até chegar na linha desejada
    while (fgets(texto, 1024, f))
    {
        if (linhaAtual == linhaAlvo)
        {
            // Remove o \n final para a formatação ficar bonita
            texto[strcspn(texto, "\n")] = 0;
            printf("%s\n", texto);
            break;
        }
        linhaAtual++;
    }
    fclose(f);
}

// --- FUNÇÕES DA ÁRVORE (Sua lógica original mantida) ---

TNo *criarNo(int chave, int linha)
{
    TNo *novoNo = (TNo *)malloc(sizeof(TNo));
    if (novoNo)
    {
        novoNo->chaveComposta = chave;
        novoNo->linhaCSV = linha;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    }
    return novoNo;
}

// Adaptei levemente para receber a Chave já calculada, facilitando o carregarDados
TNo *inserir(TNo *raiz, int chave, int linha)
{
    if (raiz == NULL)
        return criarNo(chave, linha);

    if (chave < raiz->chaveComposta)
        raiz->esquerda = inserir(raiz->esquerda, chave, linha);
    else
        raiz->direita = inserir(raiz->direita, chave, linha);

    return raiz;
}

// Função recursiva Em-Ordem para gerar o relatório
void gerarRelatorio(TNo *raiz, char *nomeArquivo)
{
    if (raiz != NULL)
    {
        // 1. Visita esquerda (menores)
        gerarRelatorio(raiz->esquerda, nomeArquivo);

        // 2. Processa o atual (busca no arquivo e imprime)
        printf("[Chave: %3d | Linha: %3d] -> ", raiz->chaveComposta, raiz->linhaCSV);
        imprimirLinhaDoArquivo(nomeArquivo, raiz->linhaCSV);

        // 3. Visita direita (maiores)
        gerarRelatorio(raiz->direita, nomeArquivo);
    }
}

// Função Pós-Ordem para limpar memória
void liberarArvore(TNo *no)
{
    if (no != NULL)
    {
        liberarArvore(no->esquerda);
        liberarArvore(no->direita);
        free(no);
    }
}

// --- FUNÇÃO DE CARGA DE DADOS ---

TNo *carregarDados(TNo *raiz, char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo)
    {
        printf("ERRO: Arquivo '%s' nao encontrado!\n", nomeArquivo);
        return raiz;
    }

    char linhaTexto[1024];
    int numeroLinha = 1;

    // Pula o cabeçalho (primeira linha do CSV)
    fgets(linhaTexto, 1024, arquivo);
    numeroLinha++;

    printf("Lendo arquivo e construindo arvore...\n");

    while (fgets(linhaTexto, 1024, arquivo))
    {
        // === CONFIGURAÇÃO DAS COLUNAS ===
        // IMPORTANTE: Verifique no seu CSV quais são os índices (começa em 0)
        // Exemplo: Coluna 0 é Age, Coluna 5 é Tumor Size (ajuste conforme seu arquivo real)
        char *strIdade = get_field(linhaTexto, 0);
        char *strTumor = get_field(linhaTexto, 5); // <--- AJUSTE ESSE NUMERO SE PRECISAR

        if (strIdade && strTumor)
        {
            int idade = atoi(strIdade);
            int tumor = atoi(strTumor);
            int chave = idade + tumor;

            raiz = inserir(raiz, chave, numeroLinha);

            free(strIdade);
            free(strTumor);
        }
        numeroLinha++;
    }

    fclose(arquivo);
    printf("Sucesso! Arvore criada.\n");
    return raiz;
}

// --- MAIN ---

int main()
{
    TNo *raiz = NULL;
    int opcao;
    // Defina aqui o nome exato do seu arquivo CSV
    char nomeArquivo[] = "Breast_Cancer.csv";

    do
    {
        printf("\n--- MENU ABP CANCER ---\n");
        printf("1. Carregar Arquivo\n");
        printf("2. Emitir Relatorio\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            if (raiz != NULL)
            {
                liberarArvore(raiz); // Limpa árvore anterior se existir
                raiz = NULL;
            }
            raiz = carregarDados(raiz, nomeArquivo);
            break;

        case 2:
            if (raiz == NULL)
            {
                printf("AVISO: Carregue o arquivo primeiro (Opcao 1)!\n");
            }
            else
            {
                printf("\n--- RELATORIO ORDENADO (Age + Tumor Size) ---\n");
                gerarRelatorio(raiz, nomeArquivo);
            }
            break;

        case 3:
            printf("Limpando memoria e saindo...\n");
            liberarArvore(raiz);
            raiz = NULL;
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}