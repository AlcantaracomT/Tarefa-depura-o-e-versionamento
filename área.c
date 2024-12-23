#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void menu();
int validarEntrada();
void opcaoMenu();
void conversorArea();

// Função principal
int main()
{
    menu();          // Mostrar menu
    opcaoMenu();     // Escolha da função do menu
    return 0;
}

// Função para exibir o menu
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

// Função para tratar a entrada do menu
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
        printf("Conversor de comprimento ainda não implementado.\n");
        break;

    case 2:
        printf("Conversor de massa ainda não implementado.\n");
        break;

    case 3:
        printf("Conversor de volume ainda não implementado.\n");
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
        conversorArea(); // Chama a função de conversão de área
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

// Corrigindo para função para conversão de área
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
        while (getchar() != '\n'); // Limpar buffer
    }

    if (escolha == 1) 
    {
         do {
            printf("Digite o valor em metros quadrados (não pode ser negativo): ");
            scanf("%f", &metrosQuadrados);
            if (metrosQuadrados < 0)
                printf("Erro: o valor não pode ser negativo. Tente novamente.\n");
        } while (metrosQuadrados < 0);

        centimetrosQuadrados = metrosQuadrados * 10000;
        printf("%.2f metros quadrados equivalem a %.2f centímetros quadrados.\n", metrosQuadrados, centimetrosQuadrados);
    }
    else if (escolha == 2)
     {
        do {
            printf("Digite o valor em centímetros quadrados (não pode ser negativo): ");
            scanf("%f", &centimetrosQuadrados);
            if (centimetrosQuadrados < 0)
                printf("Erro: o valor não pode ser negativo. Tente novamente.\n");
        } while (centimetrosQuadrados < 0);

        metrosQuadrados = centimetrosQuadrados / 10000;
        printf("%.2f centímetros quadrados equivalem a %.2f metros quadrados.\n", centimetrosQuadrados, metrosQuadrados);
    }

    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}
