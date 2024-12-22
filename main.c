#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validarUnidade(char unidade)
{
    unidade = tolower(unidade);
    return (unidade == 'm' || unidade == 'c' || unidade == 'd');
}

void conversorArea();
void conversorTempo();

void converterComprimento()
{
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

    printf("Digite o valor: ");
    scanf("%lf", &valor);

    do
    {
        printf("Digite a unidade de origem (m, cm, mm): ");
        scanf(" %c", &unidadeOrigem);
        if (!validarUnidade(unidadeOrigem))
        {
            printf("Unidade inválida. Use apenas 'm', 'cm' ou 'mm'.\n");
        }
    } while (!validarUnidade(unidadeOrigem));

    do
    {
        printf("Digite a unidade de destino (m, cm, mm): ");
        scanf(" %c", &unidadeDestino);
        if (!validarUnidade(unidadeDestino))
        {
            printf("Unidade inválida. Use apenas 'm', 'cm' ou 'mm'.\n");
        }
    } while (!validarUnidade(unidadeDestino));

    if (unidadeOrigem == 'm')
    {
        if (unidadeDestino == 'cm')
        {
            resultado = valor * 100;
        }
        else if (unidadeDestino == 'mm')
        {
            resultado = valor * 1000;
        }
        else
        {
            resultado = valor;
        }
    }
    else if (unidadeOrigem == 'c')
    {
        if (unidadeDestino == 'm')
        {
            resultado = valor / 100;
        }
        else if (unidadeDestino == 'mm')
        {
            resultado = valor * 10;
        }
        else
        {
            resultado = valor;
        }
    }
    else if (unidadeOrigem == 'd')
    {
        if (unidadeDestino == 'm')
        {
            resultado = valor / 1000;
        }
        else if (unidadeDestino == 'c')
        {
            resultado = valor / 10;
        }
        else
        {
            resultado = valor;
        }
    }

    // Exibição do resultado
    printf("%.2f %c = %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino);
}
void limparBuffer()
{
    while (getchar() != '\n')
        ; // Limpar o buffer de entrada
}

// ConverterVolume
void converterVolume()
{
    float valor, resultado;
    int opcaoOrigem, opcaoDestino;
    char continuar;

    do
    {
        // Solicitar a unidade de origem para volume com validação
        do
        {
            printf("\nEscolha a unidade de origem para volume:\n");
            printf("1 - Litro\n");
            printf("2 - Mililitro\n");
            printf("3 - Metro Cúbico\n");
            printf("Digite a opção da unidade de origem: ");
            if (scanf("%d", &opcaoOrigem) != 1)
            {
                printf("Opção inválida. Por favor, escolha uma opção válida (1, 2 ou 3).\n");
                limparBuffer(); // Limpar o buffer para evitar loop infinito
            }
            else if (opcaoOrigem < 1 || opcaoOrigem > 3)
            {
                printf("Opção inválida. Por favor, escolha uma opção válida (1, 2 ou 3).\n");
            }
        } while (opcaoOrigem < 1 || opcaoOrigem > 3);

        // Solicitar o valor a ser convertido com validação
        do
        {
            printf("Digite o valor a ser convertido: ");
            if (scanf("%f", &valor) != 1)
            {
                printf("Valor inválido. Por favor, digite um número válido.\n");
                limparBuffer(); // Limpar o buffer para evitar loop infinito
            }
            else
            {
                break; // Sai do loop se o valor for válido
            }
        } while (1);

        // Solicitar a unidade de destino com validação
        do
        {
            printf("Escolha a unidade de destino:\n");
            printf("1 - Litro\n");
            printf("2 - Mililitro\n");
            printf("3 - Metro Cúbico\n");
            printf("Digite a opção da unidade de destino: ");
            if (scanf("%d", &opcaoDestino) != 1)
            {
                printf("Opção inválida. Por favor, escolha uma opção válida (1, 2 ou 3).\n");
                limparBuffer(); // Limpar o buffer para evitar loop infinito
            }
            else if (opcaoDestino < 1 || opcaoDestino > 3)
            {
                printf("Opção inválida. Por favor, escolha uma opção válida (1, 2 ou 3).\n");
            }
        } while (opcaoDestino < 1 || opcaoDestino > 3);

        // Conversão de Volume
        if (opcaoOrigem == 1)
        {
            if (opcaoDestino == 1)
            {
                resultado = valor;
            }
            else if (opcaoDestino == 2)
            {
                resultado = valor * 1000; // 1 litro = 1000 mililitros
            }
            else if (opcaoDestino == 3)
            {
                resultado = valor / 1000; // 1 litro = 0.001 metro cúbico
            }
        }
        else if (opcaoOrigem == 2)
        {
            if (opcaoDestino == 1)
            {
                resultado = valor / 1000; // 1000 mililitros = 1 litro
            }
            else if (opcaoDestino == 2)
            {
                resultado = valor;
            }
            else if (opcaoDestino == 3)
            {
                resultado = valor * 1e-6; // 1 mililitro = 1e-6 metro cúbico
            }
        }
        else if (opcaoOrigem == 3)
        {
            if (opcaoDestino == 1)
            {
                resultado = valor * 1000; // 1 metro cúbico = 1000 litros
            }
            else if (opcaoDestino == 2)
            {
                resultado = valor * 1e+6; // 1 metro cúbico = 1000000 mililitros
            }
            else if (opcaoDestino == 3)
            {
                resultado = valor;
            }
        }

        // Exibir o resultado
        printf("Resultado: %.6f\n", resultado); // Mostrar até 6 casas decimais para maior precisão

        // Perguntar se o usuário quer realizar outra conversão com validação de resposta
        do
        {
            printf("\nDeseja realizar outra conversão de volume? (s - sim, n - não): ");
            scanf(" %c", &continuar); // O espaço antes de %c é para limpar o buffer do teclado
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N')
            {
                printf("Opção inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
            }
        } while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N'); // Validar entrada

    } while (continuar == 's' || continuar == 'S'); // Se o usuário escolher 's' ou 'S', o loop continua
}
void converterMassa()
{
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

    printf("Digite o valor: ");
    scanf("%lf", &valor);

    printf("Digite a unidade de origem (t para toneladas, k para quilogramas, g para gramas, m para miligramas): ");
    scanf(" %c", &unidadeOrigem);

    printf("Digite a unidade de destino (t para toneladas, k para quilogramas, g para gramas, m para miligramas): ");
    scanf(" %c", &unidadeDestino);

    if (unidadeOrigem == 't')
    { // Origem: toneladas
        if (unidadeDestino == 'k')
        {
            resultado = valor * 1000; // t para kg
        }
        else if (unidadeDestino == 'g')
        {
            resultado = valor * 1000000; // t para g
        }
        else if (unidadeDestino == 'm')
        {
            resultado = valor * 1000000000; // t para mg
        }
        else if (unidadeDestino == 't')
        {
            resultado = valor; // t para t
        }
        else
        {
            printf("Unidade fornecida invalida!\n");
            return;
        }
    }
    else if (unidadeOrigem == 'k')
    { // Origem: quilograma
        if (unidadeDestino == 't')
        {
            resultado = valor / 1000; // kg para t
        }
        else if (unidadeDestino == 'g')
        {
            resultado = valor * 1000; // kg para g
        }
        else if (unidadeDestino == 'm')
        {
            resultado = valor * 1000000; // kg para mg
        }
        else if (unidadeDestino == 'k')
        {
            resultado = valor; // kg para kg
        }
        else
        {
            printf("Unidade fornecida invalida!\n");
            return;
        }
    }
    else if (unidadeOrigem == 'g')
    { // Origem: gramas
        if (unidadeDestino == 't')
        {
            resultado = valor / 1000000; // g para t
        }
        else if (unidadeDestino == 'k')
        {
            resultado = valor / 1000; // g para kg
        }
        else if (unidadeDestino == 'm')
        {
            resultado = valor * 1000; // g para mg
        }
        else if (unidadeDestino == 'g')
        {
            resultado = valor; // g para g
        }
        else
        {
            printf("Unidade fornecida invalida!\n");
            return;
        }
    }
    else if (unidadeOrigem == 'm')
    { // Origem: miligrama
        if (unidadeDestino == 't')
        {
            resultado = valor / 1000000000; // mg para t
        }
        else if (unidadeDestino == 'k')
        {
            resultado = valor / 1000000; // mg para kg
        }
        else if (unidadeDestino == 'g')
        {
            resultado = valor / 1000; // mg para g
        }
        else if (unidadeDestino == 'm')
        {
            resultado = valor; // mg para mg
        }
        else
        {
            printf("Unidade fornecida invalida!\n");
            return;
        }
    }
    else
    {
        printf("Unidade fornecida invalida!\n");
        return;
    }

    // Exibi\u00e7\u00e3o do resultado
    printf("%.2f %c = %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino);
}

void converterTemperatura()
{
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

    printf("\n--- Conversor de Unidades de Temperatura ---\n");

    printf("Digite o valor da temperatura: ");
    scanf("%lf", &valor);

    printf("Digite a unidade de origem (C para Celsius, F para Fahrenheit, K para Kelvin): ");
    scanf(" %c", &unidadeOrigem);

    printf("Digite a unidade de destino (C para Celsius, F para Fahrenheit, K para Kelvin): ");
    scanf(" %c", &unidadeDestino);

    if (unidadeOrigem == 'C' || unidadeOrigem == 'c')
    {
        if (unidadeDestino == 'F' || unidadeDestino == 'f')
        {
            resultado = (valor * 9 / 5) + 32;
        }
        else if (unidadeDestino == 'K' || unidadeDestino == 'k')
        {
            resultado = valor + 273.15;
        }
        else if (unidadeDestino == 'C' || unidadeDestino == 'c')
        {
            resultado = valor;
        }
    }
    else if (unidadeOrigem == 'F' || unidadeOrigem == 'f')
    {
        if (unidadeDestino == 'C' || unidadeDestino == 'c')
        {
            resultado = (valor - 32) * 5 / 9;
        }
        else if (unidadeDestino == 'K' || unidadeDestino == 'k')
        {
            resultado = (valor - 32) * 5 / 9 + 273.15;
        }
        else if (unidadeDestino == 'F' || unidadeDestino == 'f')
        {
            resultado = valor;
        }
    }
    else if (unidadeOrigem == 'K' || unidadeOrigem == 'k')
    {
        if (unidadeDestino == 'C' || unidadeDestino == 'c')
        {
            resultado = valor - 273.15;
        }
        else if (unidadeDestino == 'F' || unidadeDestino == 'f')
        {
            resultado = (valor - 273.15) * 9 / 5 + 32;
        }
        else if (unidadeDestino == 'K' || unidadeDestino == 'k')
        {
            resultado = valor;
        }
    }
    else
    {
        printf("Unidade de origem inválida.\n");
        return;
    }

    printf("%.2f %c é igual a %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino);
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

/* Função para validar a entrada de inteiros do usuário
   recebe uma entrada e valida caso seja um numero inteiro
*/
int validarInteiro()
{
    int opcao = 0;

    printf("\n--> ");

    while (scanf("%d", &opcao) != 1) // Verificar se é um número inteiro
    {
        system("clear || cls"); // Limpa o terminal
        menu();
        printf("Erro!! \nDigite um número\n--> ");
        while (getchar() != '\n')
            ; // Limpar buffer do teclado
    }

    return opcao;
}

/* Função para validar a entrada de caracteres do usuário
    recebe uma entrada e valida caso seja um caracter alfabetico.
*/
char validarCaracter()
{
    char input;

    printf("\n--> ");

    while (getchar() != '\n')
        ; // Limpa o buffer

    scanf("%c", &input);

    // Verificar se o caractere esta entra (a-z ou A-Z)
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
    {
        return input;
    }
    else
    {
        printf("Erro!! \nDigite\n--> ");
        return validarCaracter();
    }
}
// OBS: se for usar as funções validaInteiro e validaCaracter, coloque suas funções daqui para bauo

// Função para entrar na opção escolhida
void opcaoMenu()
{
    int opcao;
    int valido = 0;

    do
    {
        opcao = validarInteiro();

        if (opcao < 0 || opcao > 9)
        {
            system("clear || cls");
            menu();
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
        system("clear || cls");
        converterMassa();
        break;
    case 3:
        system("clear || cls");
        converterVolume();
        break;

    case 4:
        system("clear || cls");
        converterTemperatura();
        break;

    case 5:
        printf("Conversor de velocidade ainda não implementado.\n");
        break;

    case 6:
        printf("Conversor de potência ainda não implementado.\n");
        break;

    case 7:
        conversorArea(); // Chama a função de conversão de área
        break;

    case 8:
        system("clear || cls");
        conversorTempo();
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
    menu();      // Mostrar menu
    opcaoMenu(); // Escolha da função do menu
    return 0;
}

// Função para conversão de área
void conversorArea()
{
    float metrosQuadrados, centimetrosQuadrados;
    int escolha;

    printf("\n--- Conversor de Unidades de Área ---\n");
    printf("Escolha a conversão:\n");
    printf("1 - Metros quadrados para centímetros quadrados\n");
    printf("2 - Centímetros quadrados para metros quadrados\n");
    printf("--> ");

    while (scanf("%d", &escolha) != 1 || (escolha < 1 || escolha > 2))
    {
        printf("Opção inválida. Tente novamente:\n--> ");
        while (getchar() != '\n')
            ; // Limpar buffer
    }

    if (escolha == 1)
    {
        printf("Digite o valor em metros quadrados: ");
        scanf("%f", &metrosQuadrados);
        centimetrosQuadrados = metrosQuadrados * 10000;
        printf("%.2f metros quadrados equivalem a %.2f centímetros quadrados.\n", metrosQuadrados, centimetrosQuadrados);
    }
    else if (escolha == 2)
    {
        printf("Digite o valor em centímetros quadrados: ");
        scanf("%f", &centimetrosQuadrados);
        metrosQuadrados = centimetrosQuadrados / 10000;
        printf("%.2f centímetros quadrados equivalem a %.2f metros quadrados.\n", centimetrosQuadrados, metrosQuadrados);
    }

    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}

void conversorTempo()
{
    int opcao, tempo;

    do
    {
        printf("\n       Digite um Número Para Escolher a Opção\n");
        printf("\n***********************************************************************************************\n");
        printf("| 1 | Converter segundos para minutos\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 2 | Converter segundos para horas\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 3 | Converter minutos para segundos\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 4 | Converter minutos para horas\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 5 | Converter horas para segundos\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 6 | Converter horas para minutos\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("| 0 | Sair\n");
        printf("\n***********************************************************************************************\n");

        opcao = validarInteiro();

        switch (opcao)
        {
        case 1:
            system("clear || cls");
            printf("Digite o tempo em segundos: ");
            scanf("%d", &tempo);

            printf("\n%d segundos é igual a %d minutos\n\n", tempo, tempo / 60);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        case 2:
            system("clear || cls");
            printf("Digite o tempo em segundos: ");
            scanf("%d", &tempo);

            printf("\n%d segundos é igual a %d horas\n\n", tempo, tempo / 3600);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        case 3:
            system("clear || cls");
            printf("Digite o tempo em minutos: ");
            scanf("%d", &tempo);

            printf("\n%d minutos é igual a %d segundos\n\n", tempo, tempo * 60);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        case 4:
            system("clear || cls");
            printf("Digite o tempo em minutos: ");
            scanf("%d", &tempo);

            printf("\n%d minutos é igual a %d horas\n\n", tempo, tempo / 60);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        case 5:
            system("clear || cls");
            printf("Digite o tempo em horas: ");
            scanf("%d", &tempo);

            printf("\n%d horas é igual a %d segundos\n\n", tempo, tempo * 3600);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        case 6:
            system("clear || cls");
            printf("Digite o tempo em horas: ");
            scanf("%d", &tempo);

            printf("\n%d horas é igual a %d minutos\n\n", tempo, tempo * 60);
            system("read -p 'Pressione Enter para continuar...' var");
            break;
        default:
            printf("\nOpção inválida\n");
            break;
        }
    } while (opcao != 0);
}
