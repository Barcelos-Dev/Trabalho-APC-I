#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char cpf[15];
    char nome[50];
    char telefone[15];
    char email[50];
    char rua[50];
    char complemento[30];
    char bairro[30];
    char cidade[30];
    char estado[3];
} Cliente;

typedef struct {
    char codigo[10];
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    Cliente clientes[MAX];
    Produto produtos[MAX];
    int totalClientes = 0, totalProdutos = 0, opcao;
    char estados_validos[27][3] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO",
        "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI",
        "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"
    };

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("3. Cadastrar Produto\n");
        printf("4. Listar Produtos\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        
        // Verifica se a entrada é numérica
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero entre 1 e 5.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1: // Cadastro de cliente
                if (totalClientes >= MAX) {
                    printf("Limite maximo de clientes atingido!\n");
                    break;
                }

                printf("\n--- CADASTRO DE CLIENTE ---\n");

                // CPF (valida formato)
                do {
                    printf("CPF (XXX.XXX.XXX-XX): ");
                    scanf("%14s", clientes[totalClientes].cpf);
                    while (getchar() != '\n'); // Limpa o buffer
                    
                    if (strlen(clientes[totalClientes].cpf) != 14 ||
                        clientes[totalClientes].cpf[3] != '.' ||
                        clientes[totalClientes].cpf[7] != '.' ||
                        clientes[totalClientes].cpf[11] != '-') {
                        printf("Formato inválido! Use XXX.XXX.XXX-XX.\n");
                    }
                } while (strlen(clientes[totalClientes].cpf) != 14);

                // Nome
                do {
                    printf("Nome: ");
                    scanf(" %49[^\n]", clientes[totalClientes].nome);
                    while (getchar() != '\n'); // Limpa o buffer
                    if (strlen(clientes[totalClientes].nome) == 0) {
                        printf("Nome nao pode ser vazio!\n");
                    }
                } while (strlen(clientes[totalClientes].nome) == 0);

                // Telefone
                do {
                    printf("Telefone (XX)XXXXX-XXXX: ");
                    scanf("%14s", clientes[totalClientes].telefone);
                    while (getchar() != '\n');
                    if (strlen(clientes[totalClientes].telefone) != 14 ||
                        clientes[totalClientes].telefone[0] != '(' ||
                        clientes[totalClientes].telefone[3] != ')' ||
                        clientes[totalClientes].telefone[9] != '-') {
                        printf("Formato inválido! Use (XX)XXXXX-XXXX.\n");
                    }
                } while (strlen(clientes[totalClientes].telefone) != 14);

                // E-mail
                do {
                    printf("E-mail: ");
                    scanf("%49s", clientes[totalClientes].email);
                    while (getchar() != '\n'); // Limpa o buffer
                    if (strchr(clientes[totalClientes].email, '@') == NULL ||
                        strchr(clientes[totalClientes].email, '.') == NULL) {
                        printf("E-mail invalido! Deve conter '@' e '.'.\n");
                    }
                } while (strchr(clientes[totalClientes].email, '@') == NULL);

                printf("\n--- ENDERECO ---\n");
                // Rua
                do {
                    printf("Rua: ");
                    scanf(" %49[^\n]", clientes[totalClientes].rua);
                    while (getchar() != '\n');
                    if (strlen(clientes[totalClientes].rua) == 0) {
                        printf("Rua nao pode ser vazia!\n");
                    }
                } while (strlen(clientes[totalClientes].rua) == 0);

                // Complemento (opcional)
                printf("Complemento (opcional): ");
                scanf(" %29[^\n]", clientes[totalClientes].complemento);
                while (getchar() != '\n'); 

                // Bairro 
                do {
                    printf("Bairro: ");
                    scanf(" %29[^\n]", clientes[totalClientes].bairro);
                    while (getchar() != '\n'); // Limpa o buffer
                    if (strlen(clientes[totalClientes].bairro) == 0) {
                        printf("Bairro nao pode ser vazio!\n");
                    }
                } while (strlen(clientes[totalClientes].bairro) == 0);

                // Cidade
                do {
                    printf("Cidade: ");
                    scanf(" %29[^\n]", clientes[totalClientes].cidade);
                    while (getchar() != '\n'); // Limpa o buffer
                    if (strlen(clientes[totalClientes].cidade) == 0) {
                        printf("Cidade nao pode ser vazia!\n");
                    }
                } while (strlen(clientes[totalClientes].cidade) == 0);

                // Estado
                int estado_valido;
                do {
                    estado_valido = 0;
                    printf("Estado (sigla, ex: SP): ");
                    scanf("%2s", clientes[totalClientes].estado);
                    while (getchar() != '\n'); // Limpa o buffer

                    // Converter para maiúsculas
                    for (int i = 0; i < 2; i++) {
                        clientes[totalClientes].estado[i] = toupper(clientes[totalClientes].estado[i]);
                    }

                    // Valida se tem 2 caracteres
                    if (strlen(clientes[totalClientes].estado) != 2) {
                        printf("Erro: Use 2 caracteres (ex: SP).\n");
                        continue;
                    }

                    // Valida se a sigla existe
                    for (int j = 0; j < 27; j++) {
                        if (strcmp(clientes[totalClientes].estado, estados_validos[j]) == 0) {
                            estado_valido = 1;
                            break;
                        }
                    }
                    if (!estado_valido) {
                        printf("Erro: Sigla invalida. Use valores como SP, RJ, MG.\n");
                    }
                } while (!estado_valido);

                totalClientes++;
                printf("\nCliente cadastrado com sucesso!\n");
                break;

            case 2: // Listar clientes
                printf("\n--- LISTA DE CLIENTES ---\n");
                if (totalClientes == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                } else {
                    for (int i = 0; i < totalClientes; i++) {
                        printf("\nCliente %d:\n", i + 1);
                        printf("CPF: %s\n", clientes[i].cpf);
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("Telefone: %s\n", clientes[i].telefone);
                        printf("E-mail: %s\n", clientes[i].email);
                        printf("Endereço:\n");
                        printf("  Rua: %s\n", clientes[i].rua);
                        printf("  Complemento: %s\n", clientes[i].complemento);
                        printf("  Bairro: %s\n", clientes[i].bairro);
                        printf("  Cidade: %s\n", clientes[i].cidade);
                        printf("  Estado: %s\n", clientes[i].estado);
                    }
                }
                break;

            case 3: // Cadastro de produto
                if (totalProdutos >= MAX) {
                    printf("Limite maximo de produtos atingido!\n");
                    break;
                }

                printf("\n--- CADASTRO DE PRODUTO ---\n");

                // Código
                do {
                    printf("Codigo (nao pode ser vazio): ");
                    scanf("%9s", produtos[totalProdutos].codigo);
                    while (getchar() != '\n');
                    if (strlen(produtos[totalProdutos].codigo) == 0) {
                        printf("Codigo nao pode ser vazio!\n");
                    }
                } while (strlen(produtos[totalProdutos].codigo) == 0);

                // Nome (
                do {
                    printf("Nome (nao pode ser vazio): ");
                    scanf(" %49[^\n]", produtos[totalProdutos].nome);
                    while (getchar() != '\n'); 
                    if (strlen(produtos[totalProdutos].nome) == 0) {
                        printf("Nome nao pode ser vazio!\n");
                    }
                } while (strlen(produtos[totalProdutos].nome) == 0);

                // Preço
                do {
                    printf("Preco (maior que zero): ");
                    if (scanf("%f", &produtos[totalProdutos].preco) != 1) {
                        printf("Valor invalido! Digite um numero.\n");
                        while (getchar() != '\n'); 
                        produtos[totalProdutos].preco = -1; 
                    } else if (produtos[totalProdutos].preco <= 0) {
                        printf("Erro: Preco deve ser positivo!\n");
                    }
                    while (getchar() != '\n'); 
                } while (produtos[totalProdutos].preco <= 0);

                // Quantidade
                do {
                    printf("Quantidade em estoque (nao negativa): ");
                    if (scanf("%d", &produtos[totalProdutos].quantidade) != 1) {
                        printf("Valor invalido! Digite um numero inteiro.\n");
                        while (getchar() != '\n');
                        produtos[totalProdutos].quantidade = -1;
                    } else if (produtos[totalProdutos].quantidade < 0) {
                        printf("Erro: Quantidade nao pode ser negativa!\n");
                    }
                    while (getchar() != '\n'); // Limpa o buffer
                } while (produtos[totalProdutos].quantidade < 0);

                totalProdutos++;
                printf("\nProduto cadastrado com sucesso!\n");
                break;

            case 4: // Listar produtos
                printf("\n--- LISTA DE PRODUTOS ---\n");
                if (totalProdutos == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    for (int i = 0; i < totalProdutos; i++) {
                        printf("\nProduto %d:\n", i + 1);
                        printf("Codigo: %s\n", produtos[i].codigo);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                        printf("Estoque: %d unidades\n", produtos[i].quantidade);
                    }
                }
                break;

            case 5: // Sair
                printf("\nSistema encerrado. Ate logo!\n");
                break;

            default:
                printf("Opção invalida! Digite um numero entre 1 e 5.\n");
        }
    } while (opcao != 5);

    return 0;
}