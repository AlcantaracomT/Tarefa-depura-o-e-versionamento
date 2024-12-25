#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


void menu();
int validarInteiro();
void opcaoMenu();
void converterComprimento();
void converterMassa();
void converterVolume();
void converterTemperatura();
void converterVelocidade();
void converterVelocidade();
void converter_potencia();
void conversorArea();
void conversorTempo();
void menuUidade();
double convertUnidade(double valor, int daUnidade, int paraUnidade);



// Função principal
int main()
{
    menu();      // Mostrar menu
    opcaoMenu(); // Escolha da função do menu
    return 0;
}


//Função para mostrar as opções do menu
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

// Função para entrar na opção escolhida no menu
void opcaoMenu()
{
    int opcao;
    do
    {
        menu(); // Mostrar o menu a cada iteração
        opcao = validarInteiro();

        if (opcao < 0 || opcao > 9)
        {
            printf("Opção inválida. Tente novamente.\n");
            continue; // Voltar ao início do loop
        }

        system("clear || cls"); // Limpar a tela antes de chamar a função correspondente

        switch (opcao)
        {
        case 1:
            converterComprimento();
            break;
        case 2:
            converterMassa();
            break;
        case 3:
            converterVolume();
            break;
        case 4:
            converterTemperatura();
            break;
        case 5:
            converterVelocidade();
            break;
        case 6:
            converter_potencia();
            break;
        case 7:
            conversorArea();
            break;
        case 8:
            conversorTempo();
            break;
        case 9:
            int daUnidade, paraUnidade;
            double valor, resultado;
            char repeat;

            do {
                printf("\n-------CONVERSOR DE UNIDADES DIGITAIS-------\n\n");

                do {
                    menuUidade();
                    printf("\nDigite o numero correspondente a unidade de origem: "); // escolhendo a unidade de origem
                    scanf("%d", &daUnidade);

                    if (daUnidade < 1 || daUnidade > 6) {
                        char tryAgain[4];
                        printf("Unidade de origem invalida. Deseja tentar de novo? (S/N): ");
                        scanf(" %3s", tryAgain);

                        if (tryAgain[0] == 'N' || tryAgain[0] == 'n') {
                            printf("\nObrigado por usar o conversor de unidades!\n");
                            break;
                        }
                    }
                } while (daUnidade < 1 || daUnidade > 6);

                
                printf("Digite o valor a ser convertido: ");    // inserindo o valor a ser convertido
                scanf("%lf", &valor);

                
                do {
                    menuUidade();  // Aqui você corrigiu a chamada de 'print_menu()' para 'menu()'
                    printf("\nDigite o numero correspondente a unidade de destino: ");  // Escolhendo a unidade a ser convertida
                    scanf("%d", &paraUnidade);

                    if (paraUnidade < 1 || paraUnidade > 6) {
                        char tryAgain[4];
                        printf("Unidade de destino invalida. Deseja tentar de novo? (S/N): ");
                        scanf(" %3s", tryAgain);

                        if (tryAgain[0] == 'N' || tryAgain[0] == 'n') {
                            printf("\nObrigado por usar o conversor de unidades!\n");
                            break;
                        }
                    }
                } while (paraUnidade < 1 || paraUnidade > 6);

            
                resultado = convertUnidade(valor, daUnidade, paraUnidade);

                printf("\nResultado: %.6lf\n", resultado);

                printf("\nDeseja fazer outra conversao? (S/N): ");
                scanf(" %c", &repeat);

            } while (repeat == 'S' || repeat == 's');
            break;
        case 0:
            printf("\nSaindo do programa. Obrigado!\n");
            return; // Sair do programa
        default:
            printf("Opção inválida.\n");
            break;
        }

        printf("\nPressione Enter para voltar ao menu...");
        getchar(); // Aguardar entrada
        getchar(); // Garantir que o buffer foi limpo
    } while (1); 
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



//Validar na função de comprimento
int validarUnidade(char unidade)
{
    //unidade = tolower(unidade);
    return (unidade == 'M' || unidade == 'c' || unidade == 'm');
}


//Função para converter Comprimento
void converterComprimento()
{
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;

    printf("Digite o valor: ");
    scanf("%lf", &valor);

    do
    {
        printf("Digite a unidade de destino: \n");
        printf("M para Metro\n");
        printf("c para Centimetro\n");
        printf("m para milimetro\n");
        printf("Digite a unidade de destino: (M, c, m)\n");
        scanf(" %c", &unidadeOrigem);
        if (!validarUnidade(unidadeOrigem))
        {
            printf("Unidade inválida. Use apenas 'M', 'c' ou 'm'.\n");
        }
    } while (!validarUnidade(unidadeOrigem));

    do
    {
        printf("Digite a unidade de destino: \n");
        printf("M para Metro\n");
        printf("c para Centimetro\n");
        printf("m para milimetro\n");
        printf("Digite a unidade de destino: (M, c, m)\n");
        scanf(" %c", &unidadeDestino);
        if (!validarUnidade(unidadeDestino))
        {
            printf("Unidade inválida. Use apenas 'M', 'c' ou 'm'.\n");
        }
    } while (!validarUnidade(unidadeDestino));

    if (unidadeOrigem == 'M')
    {
        if (unidadeDestino == 'c')
        {
            resultado = valor * 100;
        }
        else if (unidadeDestino == 'm')
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
        if (unidadeDestino == 'M')
        {
            resultado = valor / 100;
        }
        else if (unidadeDestino == 'm')
        {
            resultado = valor * 10;
        }
        else
        {
            resultado = valor;
        }
    }
    else if (unidadeOrigem == 'm')
    {
        if (unidadeDestino == 'M')
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



//Limpar o buffer do teclado
void limparBuffer()
{
    while (getchar() != '\n')
        ; // Limpar o buffer de entrada
}



// função para Converter Volume
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



//Função para conversão de Massa
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



//Função para conversão de Temperatura
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


//Função para converte velocidade
void converterVelocidade() {
    double velocidade, resultado;
    int opcao;
    do {
        printf("\nUnidades de Velocidade\n");
        printf("1. km/h para m/s\n2. km/h para mph\n3. m/s para km/h\n4. m/s para mph\n5. mph para km/h\n6. mph para m/s\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Ok, calculo finalizado.\n");
            break;
        }
        printf("\nDigite o valor da velocidade: ");
        scanf("%lf", &velocidade);
        switch (opcao) {
            case 1:
                resultado = velocidade / 3.6; // Conversor de km/h para m/s
                printf("%.2f km/h é igual a %.2f m/s\n", velocidade, resultado);
                break;
            case 2:
                resultado = velocidade / 1.609; // Conversor de km/h para mph
                printf("%.2f km/h é igual a %.2f mph\n", velocidade, resultado);
                break;
            case 3:
                resultado = velocidade * 3.6; // Conversor de m/s para km/h
                printf("%.2f m/s é igual a %.2f km/h\n", velocidade, resultado);
                break;
            case 4:
                resultado = velocidade * 2.237; // Conversor de m/s para mph
                printf("%.2f m/s é igual a %.2f mph\n", velocidade, resultado);
                break;
            case 5:
                resultado = velocidade * 1.609; // Conversor de mph para km/h
                printf("%.2f mph é igual a %.2f km/h\n", velocidade, resultado);
                break;
            case 6:
                resultado = velocidade / 2.237; // Conversor de mph para m/s
                printf("%.2f mph é igual a %.2f m/s\n", velocidade, resultado);
                break;
            default: // Não vai rodar caso escolha uma opção que não está disponivel 
                printf("Opção inválida. Tente novamente com outra opção.\n");
        }
    } while (opcao != 0);
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
}


void converter_potencia()
{
    double valor, resultado = 0.0;
    char unidadeOrigem, unidadeDestino;
    printf("\n--- Conversor de Unidades de Potencia ---\n"); // Menu inicial
    printf("Digite a unidade de origem (W para Watts, K para quiloWatts e C para cavalo a vapor): "); // Menu para determinação da unidade de origem
    scanf(" %c", &unidadeOrigem); // ler a unidade correspondente a unidade de origem
    printf("Digite o valor da Potencia: "); // Menu para digitação do valor original
    scanf("%lf", &valor); // leitura do valor original da potência
    printf("Digite a unidade de destino (W para Watts, K para quiloWatts e C para cavalo-vapor): ");// Menu para determinação da unidade de destino
    scanf(" %c", &unidadeDestino);// ler a unidade correspondente a unidade de destino
    if (unidadeOrigem == 'W' || unidadeOrigem == 'w') // Verificando se foi selecionado Watts na unidade origem
    {
        if (unidadeDestino == 'K' || unidadeDestino == 'k') // Verificando se foi selecionado quiloWatts para unidade destino
        {
            resultado = valor/1000; // Convertendo Watts para quiloWatts
        }
        else if (unidadeDestino == 'C' || unidadeDestino == 'c') //Verificando se foi selecionado cavalo-vapor para unidade destino
        {
            resultado = valor/735.5; // Convertendo Watts para cavalo-vapor
        }
        else if (unidadeDestino == 'W' || unidadeDestino == 'w') //Verificando se foi selecionado Watts para unidade destino
        {
            resultado = valor; //Mantendo mesmo valor, sem conversão necessária
        }
        else{
            printf("Error! Unidade não encontrada!"); // Sem unidade de destino correspondente
            return;
        }
    }
    else if (unidadeOrigem == 'K' || unidadeOrigem == 'k') // Verificando se foi selecionado quiloWatts na unidade origem
    {
        if (unidadeDestino == 'W' || unidadeDestino == 'w') // Verificando se foi selecionado Watts para unidade destino
        {
            resultado = valor * 1000; // Convertendo quiloWatts para Watts
        }
        else if (unidadeDestino == 'C' || unidadeDestino == 'c') // Verificando se foi selecionado cavalo-vapor para unidade destino
        {
            resultado = valor / 1000 / 735.5; // Convertendo quiloWatts para cavalo-vapor
        }
        else if (unidadeDestino == 'K' || unidadeDestino == 'k') //Verificando se foi selecionado quiloWatts para unidade destino
        {
            resultado = valor; //Mantendo mesmo valor, sem conversão necessária
        }
         else{
            printf("Error! Unidade não encontrada!"); // Sem unidade de destino correspondente
            return;
        }
    }
    else if (unidadeOrigem == 'C' || unidadeOrigem == 'c') // Verificando se foi selecionado cavalo-vapor na unidade origem
    {
        if (unidadeDestino == 'W' || unidadeDestino == 'w')//Verificando se foi selecionado Watts para unidade destino
        {
            resultado = valor*735.5; // Convertendo cavalo-vapor para Watts
        }
        else if (unidadeDestino == 'K' || unidadeDestino == 'k') //Verificando se foi selecionado quiloWatts para unidade destino
        {
            resultado = valor*735.5/1000; // Convertendo cavalo-vapor para quiloWatts
        }
        else if (unidadeDestino == 'C' || unidadeDestino == 'c') //Verificando se foi selecionado cavalo-vapor para unidade destino
        {
            resultado = valor; //Mantendo mesmo valor, sem conversão necessária
        }
        else{
            printf("Error! Unidade não encontrada!"); // Sem unidade de destino correspondente
            return;
        }
    }
    else
    {
        printf("Unidade de origem inválida.\n"); // Sem unidade de destino correspondente
        return;
    }
    printf("%.2f %c é igual a %.2f %c\n", valor, unidadeOrigem, resultado, unidadeDestino); //Escrevendo o valor de origem e destino
}


//Função para conversão de Tempo
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
            break;
        case 2:
            system("clear || cls");
            printf("Digite o tempo em segundos: ");
            scanf("%d", &tempo);

            printf("\n%d segundos é igual a %d horas\n\n", tempo, tempo / 3600);
            break;
        case 3:
            system("clear || cls");
            printf("Digite o tempo em minutos: ");
            scanf("%d", &tempo);

            printf("\n%d minutos é igual a %d segundos\n\n", tempo, tempo * 60);
            break;
        case 4:
            system("clear || cls");
            printf("Digite o tempo em minutos: ");
            scanf("%d", &tempo);

            printf("\n%d minutos é igual a %d horas\n\n", tempo, tempo / 60);
            break;
        case 5:
            system("clear || cls");
            printf("Digite o tempo em horas: ");
            scanf("%d", &tempo);

            printf("\n%d horas é igual a %d segundos\n\n", tempo, tempo * 3600);
            break;
        case 6:
            system("clear || cls");
            printf("Digite o tempo em horas: ");
            scanf("%d", &tempo);

            printf("\n%d horas é igual a %d minutos\n\n", tempo, tempo * 60);
            break;
        case 0:
            break;
        default:
            printf("\nOpção inválida\n");
            break;
        }
    } while (opcao != 0);
}



 // Menu com as opções de conversão de unidade
void menuUidade() {
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


//Função para conversão de Unidade
double convertUnidade(double valor, int daUnidade, int paraUnidade) {
    double fatores[] = {1.0 / 8.0, 1.0, 1024.0, pow(1024, 2), pow(1024, 3), pow(1024, 4)}; // Tabela de fatores de conversao em relacao a bytes

    double valorBytes = valor * fatores[daUnidade - 1]; // Convertendo para bytes primeiro

    return valorBytes / fatores[paraUnidade - 1]; // Converter de bytes para a unidade de destino
}