#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Pizza;

typedef struct {
    int codigo;
    char nome[50];
    int telefone;
} Cliente;

Pizza pizzas[100];
Cliente clientes[100];
int totalPizzas = 0, totalClientes = 0;

void cadastrarPizza() {
    printf("\n--== Cadastros das Pizzas ==--\n");
    
    printf("Código da Pizza: ");
    scanf("%d", &pizzas[totalPizzas].codigo);
    
    printf("Sabor da Pizza: ");
    scanf("%s", pizzas[totalPizzas].nome);
    
    printf("Preço: ");
    scanf("%f", &pizzas[totalPizzas].preco);
    
    totalPizzas++;
    
    printf("\nPizza cadastrada!\n");
}

void cadastrarCliente() {
    printf("\n--== Cadastros dos Clientes ==--\n");
    
    printf("Código do Cliente: ");
    scanf("%d", &clientes[totalClientes].codigo);
    
    printf("Nome do Cliente: ");
    scanf("%s", clientes[totalClientes].nome);
    
    printf("Telefone: ");
    scanf("%d", &clientes[totalClientes].telefone);
    
    totalClientes++;
    
    printf("\nCliente cadastrado!\n");
}

void listarPizzas() {
    printf("\nPizzas Cadastradas:\n");
    
    for (int i = 0; i < totalPizzas; i++) {
        printf("\nCódigo: %d\n", pizzas[i].codigo);
        printf("Preço: %s\n", pizzas[i].nome);
        printf("Preço: %.2f\n", pizzas[i].preco);
    }
}

void listarClientes() {
    printf("\nClientes Cadastrados:\n");
    
    for (int i = 0; i < totalClientes; i++) {
        printf("\nCódigo: %d\n", clientes[i].codigo);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Telefone: %d\n", clientes[i].telefone);
    }
}

void venderPizza() {
    int codigoCliente;
    
    printf("\nCódigo do Cliente: ");
    scanf("%d", &codigoCliente);
    
    int clienteEncontrado = -1;
    
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clienteEncontrado = i;
            break;
        }
    }
    if (clienteEncontrado == -1) {
        printf("\nCliente não encontrado!\n");
        return;
    }
    printf("\nPizzas Disponíveis:\n");
    for (int i = 0; i < totalPizzas; i++) {
        printf("\nCódigo: %d\n", pizzas[i].codigo);
        printf("Sabor: %s\n", pizzas[i].nome);
        printf("Preço: %.2f\n", pizzas[i].preco);
    }
    float total = 0;
    
    printf("\nDigite o código da pizza que deseja comprar (0 para sair): ");
    
    int opcao;
    
    printf("\nPizzas compradas: \n");
    
    while (1) {
        scanf("%d", &opcao);
        if (opcao == 0) break;
        for (int i = 0; i < totalPizzas; i++) {
            if (pizzas[i].codigo == opcao) {
                total += pizzas[i].preco;
                printf("\nCódigo: %d\n", pizzas[i].codigo);
                printf("Sabor: %s\n", pizzas[i].nome);
                printf("Preço: %.2f\n", pizzas[i].preco);
                break;
            }
        }
        printf("\nDigite o código da pizza que deseja comprar (0 para sair): ");
    }
    printf("\nValor total: %.2f\n", total);
}

int main() {
    int opcao;
    
    printf("--== Bem Vindo(a) a Pizzaria Nostra Pizza ==--\n");
    
    do {
        printf("\n1. Cadastrar Pizza\n");
        printf("2. Cadastrar Cliente\n");
        printf("3. Listar Pizzas\n");
        printf("4. Listar Clientes\n");
        printf("5. Vender Pizza\n");
        printf("6. Sair\n");
        printf("Escolha uma Opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: cadastrarPizza(); 
            break;
            
            case 2: cadastrarCliente(); 
            break;
            
            case 3: listarPizzas(); 
            break;
            
            case 4: listarClientes(); 
            break;
            
            case 5: venderPizza(); 
            break;
            
            case 6: printf("Saindo...\n"); 
            break;
            
            default: printf("Opção inválida!\n");
        }
        
    } while (opcao != 6);
    return 0;
}