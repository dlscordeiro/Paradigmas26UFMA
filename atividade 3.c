#include <stdio.h>

// Função para calcular a média
float calcularMedia(float notas[], int quantidade) {
    float soma = 0;

    for (int i = 0; i < quantidade; i++) {
        soma += notas[i];
    }

    return soma / quantidade;
}

// Função para gerar a classificação
char gerarClassificacao(float media) {

    if (media >= 9.5 && media <= 10.0) {
        return 'A';
    } 
    else if (media >= 8.0) {
        return 'B';
    } 
    else if (media >= 7.0) {
        return 'C';
    } 
    else if (media >= 6.0) {
        return 'D';
    } 
    else {
        return 'E';
    }
}

// Função para verificar aproveitamento
int gerarAproveitamento(char classificacao) {

    if (classificacao == 'A' || classificacao == 'B') {
        return 1; // Aproveitar
    } 
    else {
        return 0; // Não aproveitar
    }
}

int main() {

    int quantidadeDisciplinas;

    printf("Digite a quantidade de disciplinas: ");
    scanf("%d", &quantidadeDisciplinas);

    char classificacoes[quantidadeDisciplinas];

    for (int i = 0; i < quantidadeDisciplinas; i++) {

        int quantidadeNotas;

        printf("\nDisciplina %d\n", i + 1);

        printf("Digite a quantidade de notas: ");
        scanf("%d", &quantidadeNotas);

        float notas[quantidadeNotas];

        for (int j = 0; j < quantidadeNotas; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &notas[j]);
        }

        // Calcula a média
        float media = calcularMedia(notas, quantidadeNotas);

        // Gera a classificação
        classificacoes[i] = gerarClassificacao(media);

        // Verifica aproveitamento
        int aproveitamento = gerarAproveitamento(classificacoes[i]);

        printf("Media: %.2f\n", media);
        printf("Classificacao: %c\n", classificacoes[i]);

        if (aproveitamento == 1) {
            printf("Doutorado: APROVEITAR\n");
        } else {
            printf("Doutorado: NAO APROVEITAR\n");
        }
    }

    return 0;
}