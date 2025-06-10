#include <stdio.h>

typedef struct {
    char banda[50], genero[50];
    int ano, quantidade;
    float preco;
} CD;

CD cds[100];
int totalCds = 0;



void cadastrarCd() {
    printf("\n--== Cadastro ==--");
    
    printf("\nInforme o Nome da Banda: ");
    scanf("%s", cds[totalCds].banda);
    
    printf("Informe o Ano de Lançamento: ");
    scanf("%d", &cds[totalCds].ano);
    
    printf("Informe o Gênero: ");
    scanf("%s", cds[totalCds].genero);
    
    printf("Informe a Quantidade: ");
    scanf("%d", &cds[totalCds].quantidade);
    
    printf("Informe o Preço: ");
    scanf("%f", &cds[totalCds].preco);
    
    totalCds++;
    
    printf("\nCD cadastrado!\n");
}



void venderCd() {
    char banda[50];
    int quantidade;
    
    printf("\n--== Venda ==--");
    
    printf("\nInforme a Banda: ");
    scanf("%s", banda);
    
    printf("Informe a Quantidade: ");
    scanf("%d", &quantidade);
    
    for (int i = 0; i < totalCds; i++) {
        int j = 0;
        
        while (banda[j] == cds[i].banda[j] && banda[j]) j++;
        
        if (!banda[j] && !cds[i].banda[j]) {
            if (cds[i].quantidade >= quantidade) {
                cds[i].quantidade -= quantidade;
                printf("\nValor total: R$ %.2f\n", quantidade * cds[i].preco);
                printf("Obrigado(a) pela compra!!<3\n");
                
            } else printf("\nQuantidade insuficiente!\n");
            return;
        }
    }
    printf("\nCD não encontrado!\n");
}



void pesquisarPorGenero() {
    char genero[50];
    
    printf("\n--== Procura de CDs por Gênero ==--");
    
    printf("\nGênero: ");
    scanf("%s", genero);
    
    for (int i = 0; i < totalCds; i++) {
        int j = 0;
        while (genero[j] == cds[i].genero[j] && genero[j]) j++;
        if (!genero[j] && !cds[i].genero[j]) {
            printf("\nBanda: %s\n", cds[i].banda);
            printf("Lançamento: %d\n", cds[i].ano);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: R$ %.2f\n", cds[i].preco);
        }
    }
}



void consultarCd() {
    char banda[50];
    
    printf("\n--== Consulta dos CD cadastrados ==--");
    
    printf("\nInforme a Banda: ");
    scanf("%s", banda);
    
    for (int i = 0; i < totalCds; i++) {
        int j = 0;
        
        while (banda[j] == cds[i].banda[j] && banda[j]) j++;
        if (!banda[j] && !cds[i].banda[j]) {
            
            printf("\nBanda: %s\n", cds[i].banda);
            printf("Ano: %d\n", cds[i].ano);
            printf("Gênero: %s\n", cds[i].genero);
            printf("Quantidade: %d\n", cds[i].quantidade);
            printf("Preço: R$ %.2f\n", cds[i].preco);
            
            if (cds[i].quantidade > 0) 
            printf("Unidades disponíveis: %d\n", cds[i].quantidade);
            else 
            printf("Não há unidades disponíveis!\n");
            
            return;
        }
    }
    printf("\nCD não encontrado!\n");
}



int main() {
    int opcao;
    
    printf("--== Bem Vindo a loja Som & Arte==--");
    
    do {
        printf("\n1. Cadastrar CD\n");
        printf("2. Vender CD\n");
        printf("3. Pesquisar por gênero\n");
        printf("4. Consultar CD\n");
        printf("5. Sair\n");
        printf("Selecione uma Opção: ");
        scanf("%d", &opcao);
        
        
        switch (opcao) {
            case 1: cadastrarCd(); 
            break;
            
            case 2: venderCd(); 
            break;
            
            case 3: pesquisarPorGenero(); 
            break;
            
            case 4: consultarCd(); 
            break;
            
            case 5: printf("\nSaindo...\n"); 
            break;
            
            default: printf("\nOpção inválida!\n");
        }
    
        
    } while (opcao != 5);
    return 0;
}






