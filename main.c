#include <stdio.h>
#include <stdlib.h>

void printaMenuPrincipal();
int pegarOpcao();
void opcaoMenuPrincpal();
void conversorTempo();

// Função principal
int main()
{
    printaMenuPrincipal();          // Mostrar menu
    opcaoMenuPrincpal();     // Escolha da função do menu
    return 0;
}

void printaMenuPrincipal()
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
    printf("| 8 | Converter Unidades de tempo (segundos, minutos, horas)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 9 | Converter Bits, bytes, kilobytes (KB), megabytes (MB), gigabytes (GB), terabytes (TB)\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| 0 | Sair\n");
    printf("\n***********************************************************************************************\n");
}

// Função para validar a entrada do usuário
int pegarOpcao()
{
    int opcao = 0;

    printf("\n--> ");

    while (scanf("%d", &opcao) != 1) // Verificar se é um número inteiro
    {
        system("clear || cls"); // Limpa o terminal
        printaMenuPrincipal();
        printf("Erro!! \nDigite um número\n--> ");
        while (getchar() != '\n'); // Limpar buffer do teclado
    }

    return opcao;
}

// Função para entrar na opção escolhida
void opcaoMenuPrincpal()
{
    int opcao;

    do {
        printaMenuPrincipal();
        opcao = pegarOpcao();

        switch (opcao) {
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
                printf("Conversor de área ainda não implementado.\n");
                break;

            case 8:
                system("clear || cls"); // Limpa o terminal
                conversorTempo();
                break;

            case 9:
                printf("Conversor de dados ainda não implementado.\n");
                break;

            default:
                printf("\nOpção inválida\n");
                break;
        }
    } while (opcao != 0);

    printf("\n******************\n");
    printf("\nFim do Programa\n");
    printf("\n******************\n");
}

void conversorTempo() {
    int opcao, tempo;

    do {
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

        opcao = pegarOpcao();

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
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 0:
            printf("Entrou aqui");
            //system("clear || cls");
            printf("\n******************\n");
            return;
            break;
        default:
            break;
        }
    } while (opcao != 0);
}
