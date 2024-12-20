#include <stdio.h>
#include <stdlib.h>

void converterComprimento() {
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

    
    printf("Digite o valor: ");
     scanf("%lf", &valor);

    printf("Digite a unidade de origem (m, cm, mm): ");
     scanf(" %c", &unidadeOrigem);

   printf("Digite a unidade de destino (m, cm, mm): ");
   scanf(" %c", &unidadeDestino);

    
    if (unidadeOrigem == 'm') {
       if (unidadeDestino == 'cm') {
           resultado = valor * 100;  
       } else if (unidadeDestino == 'mm') {
          resultado = valor * 1000; 
       } else if (unidadeDestino == 'm') {
            resultado = valor; 
       }
    } else if (unidadeOrigem == 'cm') {
       if (unidadeDestino == 'm') {
           resultado = valor / 100;  
       } else if (unidadeDestino == 'mm') {
           resultado = valor * 10;   
       } else if (unidadeDestino == 'cm') {
           resultado = valor; 
       }
    } else if (unidadeOrigem == 'mm') {
        if (unidadeDestino == 'm') {
            resultado = valor / 1000;
        } else if (unidadeDestino == 'cm') {
            resultado = valor / 10;   
        } else if (unidadeDestino == 'mm') {
            resultado = valor; 
        }
    } else {
        printf("Unidade de origem inválida!\n");
        return;
    }

     //Exibição do resultado
    printf("%.2f %c = %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino);
}

// Função para converter volume
void converterVolume() {
    float valor, resultado;
    int opcaoOrigem, opcaoDestino;
    char continuar;

    do {
        // Solicitar a unidade de origem para volume
        printf("\nEscolha a unidade de origem para volume:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metro Cúbico\n");
        printf("Digite a opção da unidade de origem: ");
        scanf("%d", &opcaoOrigem);

        // Solicitar o valor a ser convertido
        printf("Digite o valor a ser convertido: ");
        scanf("%f", &valor);

        // Solicitar a unidade de destino
        printf("Escolha a unidade de destino:\n");
        printf("1 - Litro\n");
        printf("2 - Mililitro\n");
        printf("3 - Metro Cúbico\n");
        printf("Digite a opção da unidade de destino: ");
        scanf("%d", &opcaoDestino);
        // Conversão de Volume
        if (opcaoOrigem == 1) {
            if (opcaoDestino == 1) {
                resultado = valor;
            } else if (opcaoDestino == 2) {
                resultado = valor * 1000;  // 1 litro = 1000 mililitros
            } else if (opcaoDestino == 3) {
                resultado = valor / 1000;  // 1 litro = 0.001 metro cúbico
            }
        } else if (opcaoOrigem == 2) {
            if (opcaoDestino == 1) {
                resultado = valor / 1000;  // 1000 mililitros = 1 litro
            } else if (opcaoDestino == 2) {
                resultado = valor;
            } else if (opcaoDestino == 3) {
                resultado = valor * 1e-6;  // 1 mililitro = 1e-6 metro cúbico
            }
        } else if (opcaoOrigem == 3) {
            if (opcaoDestino == 1) {
                resultado = valor * 1000;  // 1 metro cúbico = 1000 litros
            } else if (opcaoDestino == 2) {
                resultado = valor * 1e+6;  // 1 metro cúbico = 1000000 mililitros
            } else if (opcaoDestino == 3) {
                resultado = valor;
            }
        }

        // Exibir o resultado
        printf("Resultado: %.6f\n", resultado);  // Mostrar até 6 casas decimais para maior precisão

        // Perguntar se o usuário quer realizar outra conversão
        printf("\nDeseja realizar outra conversão de volume? (s - sim, n - não): ");
        scanf(" %c", &continuar);  // O espaço antes de %c é para limpar o buffer do teclado

    } while (continuar == 's' || continuar == 'S');  // Se o usuário escolher 's' ou 'S', o loop continua
}

void menu()
{
    printf("\n       Digite um Número Para Escolher a Opção\n");
     printf("\n***********************************************************************************************\n");
    printf("| 1 | Converter Unidades de comprimento (metro, centímetro, milímetro)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 2 | Converter Unidades de massa (quilograma, grama, tonelada)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 3 | Converter Unidades de volume (litro, mililitro, metros cúbicos)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 4 | Converter Unidades de temperatura (Celsius, Fahrenheit, Kelvin)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 5 | Converter Unidades de velocidade (km/h, m/s, mph)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 6 | Converter Watts (W), quilowatts (kW), cavalos-vapor (cv ou hp)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 7 | Converter Unidades de área (metro quadrado, centímetro quadrado)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 8 | Converter Unidades de Unidades de tempo (segundos, minutos, horas)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 9 | Converter Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 0 | Sair\n");
    printf("\n***********************************************************************************************\n");
}

// Função para validar a entrada do usuário
int validarEntrada()
{
    int opcao = 0;

    printf("\n--> ");

    while (scanf("%d", &opcao) != 1) // Verificar se é um número inteiro
    {
        system("clear || cls"); // Limpa o terminal
        menu();
        printf("Erro!! \nDigite um número\n--> ");
        while (getchar() != '\n'); // Limpar buffer do teclado
    }

    return opcao;
}

// Função para entrar na opção escolhida
void opcaoMenu()
{
    int opcao;
    int valido = 0;

    do
    {
        opcao = validarEntrada();

        if (opcao < 0 || opcao > 9)
        {
            system("clear || cls"); // Limpa o terminal
            menu();                 // Mostra o menu novamente
            printf("Opção inválida. Digite outro número.\n");
        }
        else
            valido = 1;

    } while (valido != 1);

    switch (opcao)
    {
    case 1:
         system("clear || cls");
        converterComprimento();
        break;

    case 2:
        printf("Conversor de massa ainda não implementado.\n");
        break;
    case 3:
        system("clear || cls");
        converterVolume();
        break;

    case 4:
        printf("Conversor de temperatura ainda não implementado.\n");
        break;

    case 5:
        printf("Conversor de velocidade ainda não implementado.\n");
        break;

    case 6:
        printf("Conversor de potência ainda não implementado.\n");
        break;

    case 7:
        printf("Conversor de área ainda não implementado.\n");
        break;

    case 8:
        printf("Conversor de tempo ainda não implementado.\n");
        break;

    case 9:
        printf("Conversor de dados ainda não implementado.\n");
        break;

    case 0:
        system("clear || cls"); // Limpa o terminal
        printf("\n******************\n");
        printf("\nFim do Programa\n");
        printf("\n******************\n");
        break;

    default:
        printf("\nOpção inválida\n");
        break;
    }
}

// Função principal
int main()
{
    menu();          // Mostrar menu
    opcaoMenu();     // Escolha da função do menu
    return 0;
}