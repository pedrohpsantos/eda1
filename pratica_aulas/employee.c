#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Funcionario
typedef struct {
    int id;
    char nome[50];
    char cargo[30];
    float salario;
} Funcionario;

// Função para cadastrar um novo funcionário
// Retorna um ponteiro para o novo funcionário alocado
Funcionario* criarFuncionario(int id, char *nome, char *cargo, float salario) {
    Funcionario *f = (Funcionario*) malloc(sizeof(Funcionario));
    if (f == NULL) {
        printf("Erro ao alocar memoria para funcionario.\n");
        exit(1);
    }
    
    f->id = id;
    strcpy(f->nome, nome);
    strcpy(f->cargo, cargo);
    f->salario = salario;
    
    return f;
}

// Função para dar aumento (manipulação de valor via ponteiro)
void aumentarSalario(Funcionario *f, float percentual) {
    if (f != NULL) {
        f->salario += f->salario * (percentual / 100.0);
        printf("Salario de %s atualizado para R$ %.2f\n", f->nome, f->salario);
    }
}

// Função para listar todos os funcionários
void listarFuncionarios(Funcionario **lista, int qtd) {
    if (qtd == 0) {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Funcionarios ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("ID: %d | Nome: %-20s | Cargo: %-15s | Salario: R$ %.2f\n", 
               lista[i]->id, lista[i]->nome, lista[i]->cargo, lista[i]->salario);
    }
    printf("-----------------------------\n");
}

int main() {
    // Vetor de ponteiros para Funcionario (permite manipular cada um individualmente)
    Funcionario *equipe[10]; 
    int qtdAtual = 0;
    int opcao;
    
    // Variáveis auxiliares para leitura
    int auxId;
    char auxNome[50], auxCargo[30];
    float auxSalario, auxPercentual;

    do {
        printf("\n--- GESTAO DE RH ---\n");
        printf("1. Contratar Funcionario\n");
        printf("2. Listar Equipe\n");
        printf("3. Dar Aumento\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (qtdAtual < 10) {
                    printf("\nDigite o ID: ");
                    scanf("%d", &auxId);
                    printf("Nome: ");
                    scanf(" %[^\n]", auxNome); // Lê string com espaços
                    printf("Cargo: ");
                    scanf(" %[^\n]", auxCargo);
                    printf("Salario: ");
                    scanf("%f", &auxSalario);

                    equipe[qtdAtual] = criarFuncionario(auxId, auxNome, auxCargo, auxSalario);
                    qtdAtual++;
                    printf("Funcionario contratado com sucesso!\n");
                } else {
                    printf("Limite de funcionarios atingido!\n");
                }
                break;

            case 2:
                listarFuncionarios(equipe, qtdAtual);
                break;

            case 3:
                printf("\nDigite o ID do funcionario para aumento: ");
                scanf("%d", &auxId);
                
                int encontrado = 0;
                for(int i=0; i<qtdAtual; i++) {
                    if(equipe[i]->id == auxId) {
                        printf("Digite a porcentagem do aumento: ");
                        scanf("%f", &auxPercentual);
                        aumentarSalario(equipe[i], auxPercentual);
                        encontrado = 1;
                        break;
                    }
                }
                if(!encontrado) printf("Funcionario nao encontrado.\n");
                break;

            case 4:
                printf("Liberando memoria e saindo...\n");
                // Importante: Liberar a memória de cada funcionário alocado
                for (int i = 0; i < qtdAtual; i++) {
                    free(equipe[i]);
                }
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}