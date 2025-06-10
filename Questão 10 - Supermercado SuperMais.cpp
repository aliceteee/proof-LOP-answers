#include <stdio.h>

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produto;


void cadastrarProduto() {
    printf("\nInforme o nome do produto: ");
    scanf("%s", produto.nome);
    printf("Informe a quantidade do produto em estoque: ");
    scanf("%d", &produto.quantidade);
    printf("Informe o preço do produto: ");
    scanf("%f", &produto.preco);
}


void visualizarProduto() {
    printf("\nInformações do produto:\n");
    printf("\nNome: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Preço: R$ %.2f\n", produto.preco);
}


void realizarCompra() {
    int quantidadeComprada;
    printf("\nInforme a quantidade do produto que deseja: ");
    scanf("%d", &quantidadeComprada);
    if (quantidadeComprada > produto.quantidade) {
        printf("\nQuantidade insuficiente em estoque!\n");
    } else {
        produto.quantidade -= quantidadeComprada;
        printf("\nCompra realizada com sucesso!\n");
        printf("\nQuantidade restante em estoque: %d\n", produto.quantidade);
    }
}


int main() {
    int opcao;
    produto.quantidade = 0;
        printf("--==Bem Vindo ao supermercado SuperMais==--\n");
    do {
        printf("\nSistema de Controle de Estoque\n");
        printf("1. Cadastrar produto\n");
        printf("2. Visualizar produto\n");
        printf("3. Realizar compra\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 4);
    
    return 0;
}