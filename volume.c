#include <stdio.h>
1
// Função para converter litros para outras unidades
void converter_litros(float valor, int opcao) {
    switch(opcao) {
        case 1:
            printf("%.2f litros = %.2f mililitros\n", valor, valor * 1000); // Litros para mililitros
            break;
        case 2:
            printf("%.2f litros = %.6f metros cúbicos\n", valor, valor / 1000); // Litros para metros cúbicos
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// Função para converter mililitros para outras unidades
void converter_mililitros(float valor, int opcao) {
    switch(opcao) {
        case 1:
            printf("%.2f mililitros = %.2f litros\n", valor, valor / 1000); // Mililitros para litros
            break;
        case 2:
            printf("%.2f mililitros = %.6f metros cúbicos\n", valor, valor / 1000000); // Mililitros para metros cúbicos
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// Função para converter metros cúbicos para outras unidades
void converter_metros_cubicos(float valor, int opcao) {
    switch(opcao) {
        case 1:
            printf("%.6f metros cúbicos = %.2f litros\n", valor, valor * 1000); // Metros cúbicos para litros
            break;
        case 2:
            printf("%.6f metros cúbicos = %.2f mililitros\n", valor, valor * 1000000); // Metros cúbicos para mililitros
            break;
        default:
            printf("Opção inválida!\n");
    }
}

int main() {
    int escolha, opcao;
    float valor;

    // Menu de opções
    printf("Escolha a unidade de volume de origem:\n");
    printf("1. Litros\n");
    printf("2. Mililitros\n");
    printf("3. Metros cúbicos\n");
    printf("Digite o número da opção: ");
    scanf("%d", &escolha);

    printf("Digite o valor a ser convertido: ");
    scanf("%f", &valor);

    // Menu para escolher a unidade de destino
    printf("Escolha a unidade de destino:\n");
    printf("1. Para Litros\n");
    printf("2. Para Mililitros\n");
    printf("3. Para Metros cúbicos\n");
    printf("Digite o número da opção: ");
    scanf("%d", &opcao);

    // Processar a conversão com base na escolha do usuário
    switch(escolha) {
        case 1:
            converter_litros(valor, opcao);
            break;
        case 2:
            converter_mililitros(valor, opcao);
            break;
        case 3:
            converter_metros_cubicos(valor, opcao);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
