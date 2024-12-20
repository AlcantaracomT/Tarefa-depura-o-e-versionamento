#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int validarUnidade(char unidade) {
    unidade = tolower(unidade); 
    return (unidade == 'm' || unidade == 'c' || unidade == 'd'); 
}


void converterComprimento() {
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

   
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    
    do {
        printf("Digite a unidade de origem (m, cm, mm): ");
        scanf(" %c", &unidadeOrigem);
        if (!validarUnidade(unidadeOrigem)) {
            printf("Unidade inválida. Use apenas 'm', 'cm' ou 'mm'.\n");
        }
    } while (!validarUnidade(unidadeOrigem));

    
    do {
        printf("Digite a unidade de destino (m, cm, mm): ");
        scanf(" %c", &unidadeDestino);
        if (!validarUnidade(unidadeDestino)) {
            printf("Unidade inválida. Use apenas 'm', 'cm' ou 'mm'.\n");
        }
    } while (!validarUnidade(unidadeDestino));

    
    if (unidadeOrigem == 'm') {
        if (unidadeDestino == 'cm') {
            resultado = valor * 100;
        } else if (unidadeDestino == 'mm') {
            resultado = valor * 1000;
        } else {
            resultado = valor; 
        }
    } else if (unidadeOrigem == 'c') {
        if (unidadeDestino == 'm') {
            resultado = valor / 100;
        } else if (unidadeDestino == 'mm') {
            resultado = valor * 10;
        } else {
            resultado = valor;
        }
    } else if (unidadeOrigem == 'd') {
        if (unidadeDestino == 'm') {
            resultado = valor / 1000;
        } else if (unidadeDestino == 'c') {
            resultado = valor / 10;
        } else {
            resultado = valor; 
        }
    }

    printf("%.2f %c = %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino);
}

int main() {
    converterComprimento();
    return 0;
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
        converterComprimento();
        system("clear || cls");
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
