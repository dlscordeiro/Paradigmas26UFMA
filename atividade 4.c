#include <stdio.h>

float somar(float notas[], int n) {
    if (n == 0) return 0;
    return notas[n - 1] + somar(notas, n - 1);
}

float calcularMedia(float notas[], int quantidade) {
    return somar(notas, quantidade) / quantidade;
}

char gerarClassificacao(float media) {
    if (media >= 9.5) return 'A';
    if (media >= 8.0) return 'B';
    if (media >= 7.0) return 'C';
    if (media >= 6.0) return 'D';
    return 'E';
}

int gerarAproveitamento(char c) {
    return (c == 'A' || c == 'B');
}

void processarDisciplina() {
    int quantidadeNotas;
    printf("Digite a quantidade de notas: ");
    scanf("%d", &quantidadeNotas);

    float notas[quantidadeNotas];
    for (int j = 0; j < quantidadeNotas; j++) {
        printf("Digite a nota %d: ", j + 1);
        scanf("%f", &notas[j]);
    }

    float media = calcularMedia(notas, quantidadeNotas);
    char classificacao = gerarClassificacao(media);

    printf("Media: %.2f\n", media);
    printf("Classificacao: %c\n", classificacao);
    printf("Doutorado: %s\n", gerarAproveitamento(classificacao) ? "APROVEITAR" : "NAO APROVEITAR");
}

void processarDisciplinas(int restantes, int numero) {
    if (restantes == 0) return;
    printf("\nDisciplina %d\n", numero);
    processarDisciplina();
    processarDisciplinas(restantes - 1, numero + 1);
}

int main() {
    int quantidadeDisciplinas;
    printf("Digite a quantidade de disciplinas: ");
    scanf("%d", &quantidadeDisciplinas);

    processarDisciplinas(quantidadeDisciplinas, 1);
    return 0;
}