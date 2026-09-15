/*
 * Caixa Eletronico - Ponto de Venda
 * Menu: 1-Consultar saldo | 2-Depositar | 3-Sacar | 4-Encerrar
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTAS 50
#define MAX_MOV 100

typedef struct {
    char nome[50];
    float saldo;
} Conta;

Conta contas[MAX_CONTAS];
int totalContas = 0;

/* Busca a conta pelo nome. Retorna o indice ou -1 se nao existir. */
int buscarConta(char nome[]) {
    for (int i = 0; i < totalContas; i++) {
        if (strcmp(contas[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void cadastrarConta(char nome[]) {
    strcpy(contas[totalContas].nome, nome);
    contas[totalContas].saldo = 0.0f;
    totalContas++;
    printf("\nConta criada com sucesso para %s! Saldo inicial: R$ 0.00\n\n", nome);
}

void consultarSaldo(int idx) {
    printf("\nSaldo disponivel: R$ %.2f\n\n", contas[idx].saldo);
}

bool depositar(int idx, float valor) {
    if (valor <= 0) {
        printf("\nDeposito nao realizado: valor invalido (deve ser maior que zero).\n\n");
        return false;
    }

    contas[idx].saldo += valor;

    printf("\nDeposito de R$ %.2f realizado com sucesso!\n", valor);
    printf("Novo saldo: R$ %.2f\n\n", contas[idx].saldo);
    return true;
}

bool sacar(int idx, float valor) {
    if (valor <= 0) {
        printf("\nSaque nao realizado: valor invalido.\n\n");
        return false;
    }

    if (valor > contas[idx].saldo) {
        printf("\nSaque nao realizado: saldo insuficiente.\n\n");
        return false;
    }

    contas[idx].saldo -= valor;

    printf("\nSaque de R$ %.2f realizado com sucesso!\n", valor);
    printf("Novo saldo: R$ %.2f\n\n", contas[idx].saldo);
    return true;
}

void mostrarMenu() {
    printf("===== MENU =====\n");
    printf("1 - Consultar saldo\n");
    printf("2 - Depositar\n");
    printf("3 - Sacar\n");
    printf("4 - Encerrar\n");
}

void gerarComprovante(char nome[], int idx, float saques[], int qtdSaques,
                       float depositos[], int qtdDepositos) {
    printf("\n========== COMPROVANTE ==========\n");
    printf("Cliente: %s\n", nome);
    printf("Saldo final: R$ %.2f\n", contas[idx].saldo);

    printf("\nDepositos realizados (%d):\n", qtdDepositos);
    if (qtdDepositos == 0) {
        printf("  Nenhum deposito realizado.\n");
    } else {
        for (int i = 0; i < qtdDepositos; i++) {
            printf("  %d. R$ %.2f\n", i + 1, depositos[i]);
        }
    }

    printf("\nSaques realizados (%d):\n", qtdSaques);
    if (qtdSaques == 0) {
        printf("  Nenhum saque realizado.\n");
    } else {
        for (int i = 0; i < qtdSaques; i++) {
            printf("  %d. R$ %.2f\n", i + 1, saques[i]);
        }
    }
    printf("==================================\n\n");
}

int processarCliente(char nome[]) {
    int idx;

    while (1) {
        printf("Digite o nome do cliente: ");
        scanf(" %49[^\n]", nome);

        idx = buscarConta(nome);

        if (idx == -1) {
            char opcao;
            printf("\nConta nao encontrada para '%s'.\n", nome);
            printf("Deseja cadastrar uma nova conta? (s = sim / n = tentar outro nome): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S') {
                cadastrarConta(nome);
                idx = buscarConta(nome);
                break;
            } else {
                continue;
            }
        } else {
            printf("\nBem-vindo(a) de volta, %s!\n\n", nome);
            break;
        }
    }

    return idx;
}

int main() {
    char nome[50];
    int idx = processarCliente(nome);

    bool encerrar = false;
    float saques[MAX_MOV];
    float depositos[MAX_MOV];
    int qtdSaques = 0;
    int qtdDepositos = 0;

    while (!encerrar) {
        mostrarMenu();
        int opcao;
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        float valor;

        switch (opcao) {
            case 1:
                consultarSaldo(idx);
                break;

            case 2:
                printf("Digite o valor do deposito: R$ ");
                scanf("%f", &valor);
                if (depositar(idx, valor)) {
                    depositos[qtdDepositos++] = valor;
                }
                break;

            case 3:
                printf("Digite o valor do saque: R$ ");
                scanf("%f", &valor);
                if (sacar(idx, valor)) {
                    saques[qtdSaques++] = valor;
                }
                break;

            case 4:
                encerrar = true; /* booleano: encerra o menu */
                printf("\nEncerrando atendimento...\n\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n\n");
                break;
        }
    }

    gerarComprovante(nome, idx, saques, qtdSaques, depositos, qtdDepositos);

    return 0;
}