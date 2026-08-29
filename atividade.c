#include <stdio.h>
#include <string.h>

int main() {

    char nomeCliente[50];
    int idade;
    float saldo;

    char produtos[10][50];
    float precos[10];
    int quantidadeProdutos;

    printf("=== CADASTRO DE PRODUTOS ===\n");

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidadeProdutos);
    getchar();

    // Cadastro dos produtos
    for (int i = 0; i < quantidadeProdutos; i++) {

        printf("\nProduto %d\n", i + 1);

        printf("Nome do produto: ");
        fgets(produtos[i], 50, stdin);
        produtos[i][strcspn(produtos[i], "\n")] = '\0';

        printf("Preco do produto: R$ ");
        scanf("%f", &precos[i]);
        getchar();
    }

    // Mostra os produtos cadastrados
    printf("\n=== PRODUTOS CADASTRADOS ===\n");

    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("%d - %s - R$ %.2f\n",
               i + 1, produtos[i], precos[i]);
    }

    // Cadastro do cliente
    printf("\n=== DADOS DO CLIENTE ===\n");

    printf("Nome do cliente: ");
    fgets(nomeCliente, 50, stdin);
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);

    printf("Saldo disponivel: R$ ");
    scanf("%f", &saldo);

    int produtoEscolhido;
    int quantidade;
    float valorCompra;

    printf("\nEscolha o produto: ");
    scanf("%d", &produtoEscolhido);

    printf("Quantidade: ");
    scanf("%d", &quantidade);

    valorCompra = precos[produtoEscolhido - 1] * quantidade;

    // Decisão
    printf("\n=== DECISAO ===\n");

    if (idade >= 18 && saldo >= valorCompra) {
        printf("Compra aprovada!\n");
    }
    else {
        printf("Compra negada!\n");
    }

    // Saída
    printf("\n=== SAIDA ===\n");
    printf("Cliente: %s\n", nomeCliente);
    printf("Produto: %s\n", produtos[produtoEscolhido - 1]);
    printf("Quantidade: %d\n", quantidade);
    printf("Valor da compra: R$ %.2f\n", valorCompra);
    printf("Saldo disponivel: R$ %.2f\n", saldo);

    return 0;
}