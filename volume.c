#include <stdio.h>

void converterVolume(float valor, int opcaoOrigem, int opcaoDestino) {
    // 1 = Litro, 2 = Mililitro, 3 = Metro Cúbico
    float resultado;

    // Conversão de Litro (1)
    if (opcaoOrigem == 1) {
        if (opcaoDestino == 1) {
            resultado = valor;
        } else if (opcaoDestino == 2) {
            resultado = valor * 1000;  // 1 litro = 1000 mililitros
        } else if (opcaoDestino == 3) {
            resultado = valor / 1000;  // 1 litro = 0.001 metro cúbico
        }
    }

    // Conversão de Mililitro (2)
    else if (opcaoOrigem == 2) {
        if (opcaoDestino == 1) {
            resultado = valor / 1000;  // 1000 mililitros = 1 litro
        } else if (opcaoDestino == 2) {
            resultado = valor;
        } else if (opcaoDestino == 3) {
            resultado = valor * 1e-6;  // 1 mililitro = 1e-6 metro cúbico
        }
    }

    // Conversão de Metro Cúbico (3)
    else if (opcaoOrigem == 3) {
        if (opcaoDestino == 1) {
            resultado = valor * 1000;  // 1 metro cúbico = 1000 litros
        } else if (opcaoDestino == 2) {
            resultado = valor * 1e+6;  // 1 metro cúbico = 1000000 mililitros
        } else if (opcaoDestino == 3) {
            resultado = valor;
        }
    }

    printf("Resultado: %.6f\n", resultado);  // Mostrar até 6 casas decimais para maior precisão
}

int main() {
    int opcaoOrigem, opcaoDestino;
    float valor;
    char continuar;

    do {
        printf("Conversor de Unidades de Volume\n");
        printf("Escolha a unidade de origem:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metro Cúbico\n");
        printf("Digite a opção da unidade de origem: ");
        scanf("%d", &opcaoOrigem);

        printf("Digite o valor a ser convertido: ");
        scanf("%f", &valor);

        printf("Escolha a unidade de destino:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metro Cúbico\n");
        printf("Digite a opção da unidade de destino: ");
        scanf("%d", &opcaoDestino);

        // Realiza a conversão
        converterVolume(valor, opcaoOrigem, opcaoDestino);

        // Pergunta se o usuário deseja continuar ou sair
        printf("Deseja realizar outra conversão? (s - sim, n - não): ");
        scanf(" %c", &continuar); // Espaço antes de %c para limpar o buffer do teclado

    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por usar o Conversor de Unidades. Até logo!\n");

    return 0;
}
