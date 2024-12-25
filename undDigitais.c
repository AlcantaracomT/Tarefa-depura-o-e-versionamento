#include <stdio.h>
#include <math.h>

void menu() {                                               // Menu com as opções de conversão
    const char *opcoes[] = {
        "Bits",
        "Bytes",
        "Kilobytes (KB)",
        "Megabytes (MB)",
        "Gigabytes (GB)",
        "Terabytes (TB)"
    };

    printf("Escolha a unidade de origem:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, opcoes[i]);
    }
}

double convertUnidade(double valor, int daUnidade, int paraUnidade) {
    double fatores[] = {1.0 / 8.0, 1.0, 1024.0, pow(1024, 2), pow(1024, 3), pow(1024, 4)}; // Tabela de fatores de conversao em relacao a bytes

    double valorBytes = valor * fatores[daUnidade - 1]; // Convertendo para bytes primeiro

    return valorBytes / fatores[paraUnidade - 1]; // Converter de bytes para a unidade de destino
}

int main() {
    int daUnidade, paraUnidade;
    double valor, resultado;
    char repeat;

    do {
        printf("\n-------CONVERSOR DE UNIDADES DIGITAIS-------\n\n");

        do {
            menu();
            printf("\nDigite o numero correspondente a unidade de origem: "); // escolhendo a unidade de origem
            scanf("%d", &daUnidade);

            if (daUnidade < 1 || daUnidade > 6) {
                char tryAgain[4];
                printf("Unidade de origem invalida. Deseja tentar de novo? (S/N): ");
                scanf(" %3s", tryAgain);

                if (tryAgain[0] == 'N' || tryAgain[0] == 'n') {
                    printf("\nObrigado por usar o conversor de unidades!\n");
                    return 0;
                }
            }
        } while (daUnidade < 1 || daUnidade > 6);

        
        printf("Digite o valor a ser convertido: ");    // inserindo o valor a ser convertido
        scanf("%lf", &valor);

        
        do {
            menu();  // Aqui você corrigiu a chamada de 'print_menu()' para 'menu()'
            printf("\nDigite o numero correspondente a unidade de destino: ");  // Escolhendo a unidade a ser convertida
            scanf("%d", &paraUnidade);

            if (paraUnidade < 1 || paraUnidade > 6) {
                char tryAgain[4];
                printf("Unidade de destino invalida. Deseja tentar de novo? (S/N): ");
                scanf(" %3s", tryAgain);

                if (tryAgain[0] == 'N' || tryAgain[0] == 'n') {
                    printf("\nObrigado por usar o conversor de unidades!\n");
                    return 0;
                }
            }
        } while (paraUnidade < 1 || paraUnidade > 6);

    
        resultado = convertUnidade(valor, daUnidade, paraUnidade);

        printf("\nResultado: %.6lf\n", resultado);

        printf("\nDeseja fazer outra conversao? (S/N): ");
        scanf(" %c", &repeat);

    } while (repeat == 'S' || repeat == 's');

    printf("\n\nObrigado por usar o conversor de unidades!\n\n");
    return 0;
}
