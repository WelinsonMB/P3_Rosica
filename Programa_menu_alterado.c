#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Biblioteca feita para realizar calculos matemticos como raizes

#define PI 3.14159265               // Constante para PI
#define RAIZ_3 1.732050808          // Constante da Raiz de 3
#define METROS_PARA_JARDAS 1.09361  // Conversao metros para jardas
#define CMCUB_PARA_POLCUB 16.387064 // Conversao centimetros cubicos para polegadas cubicas
#define LITROS_PARA_GALOES 0.2642   // Conversao litros para galões
#define KG_PARA_LIBRAS 2.20462262   // Conversao quilos para libras

// Funcao para calcular a area  de figuras planas
float area_figura(int tipo, float w1, float w2, float w3)
{

    switch (tipo)
    {
    case 1:
        return PI * (w1 / 2) * (w1 / 2); // Circulo (w1 e o diametro), logo a formula e pi vezes raio ao quadrado.
    case 2:
        return (w1 * w2) / 2; // Losango (w1 e w2 sao as diagonais)
    case 3:
        return w1 * w2; // Paralelogramo (w1 e a base e w2 e altura (base * altura))
    case 4:
        return ((w1 + w2) / 2) * w3; // trapezio (w1 e a base maior, w2 e a base menor e w3 e altura)
    case 5:
        return (RAIZ_3 / 4) * (w1 * w1); // triangulo equilatero (w1 e a diagonal)
    case 6:
        return (w1 * w2) / 2; // Triangulo  (w1 e a base, w2 e altura)

    default:
        return 0;
    }
}

// Funcao para calcular o volume do solidos geometricos

float volume_solido(int tipo, float w1, float w2, float w3)
{

    switch (tipo)
    {
    case 1:
        return ((4 * PI) / 3) * (w1 / 2) * (w1 / 2) * (w1 / 2); // Esfera onde w1 e o diametro, e operacao (w1/2) e para descobrir o raio
    case 2:
        return (PI * (w1 / 2) * (w1 / 2) * w2) / 3; // Cone, onde w1 e o diametro e w2 e altura
    case 3:
        return PI * (w1 / 2) * (w1 / 2) * w2; // cilintro onde w1 e o diametro e w2 e altura
    case 4:
        return (w1 * w2 * w3); // Paralelepipedo  onde w1,w2 e w3 sao base, largura e altura

    default:
        return 0;
        break;
    }
}

float conversao(int tipo, float num)
{
    switch (tipo)
    {
    case 1:
        return num * METROS_PARA_JARDAS;
    case 2:
        return num / METROS_PARA_JARDAS; // Nesta linha esta dividindo pois e de Jardas para metros
    case 3:
        return num / CMCUB_PARA_POLCUB; // Centimetros cubicos para polegadas cubicas
    case 4:
        return num * CMCUB_PARA_POLCUB; // Polegadas cubicas para centimetros cubicos
    case 5:
        return num * LITROS_PARA_GALOES;
    case 6:
        return num / LITROS_PARA_GALOES; // Galoes para litroes
    case 7:
        return num * KG_PARA_LIBRAS;
    case 8:
        return num / KG_PARA_LIBRAS; // Libras para Kg
    default:
        return 0;
    }
}

int main()
{
    int opcao, tipo;
    float w1, w2, w3, resultado, num;

    do
    {
        // Menu principal
        printf(" MENU PRINCIPAL \n");
        printf("1 - Calcular area de figuras planas\n");
        printf("2 - Calcular volume de solidos geometricos\n");
        printf("3 - Conversao de medidas\n");
        printf("4 - Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        getchar();
        system("cls"); // Limpar Tela

        // submenu
        switch (opcao)
        {
        case 1:
            printf("\n\n AREA DE FIGURAS PLANAS ");
            printf("\n\n");
            printf("\n Escolha a opcao desejada:");
            printf("\n1 - Circulo\n");
            printf("2 - Losango\n");
            printf("3 - Paralelogramo\n");
            printf("4 - Trapezio\n");
            printf("5 - Triangulo equilatero\n");
            printf("6 - Triangulo comum\n");
            printf("Opcao: ");
            scanf("%d", &tipo);
            printf("\n");

            if (tipo == 1) // Caso selecione Circulo
            {
                printf("\nDigite o diametro do circulo: ");
                scanf("%f", &w1);
                resultado = area_figura(tipo, w1, 0, 0); // chamando a funcao circulo
            }

            else if (tipo == 2) // Se selecionar o losango
            {
                printf("Digite a diagonal maior: ");
                scanf("%f", &w1);
                printf("Digite a diagonal menor: ");
                scanf("%f", &w2);
                resultado = area_figura(tipo, w1, w2, 0); // Chamando a funcao do losango
            }
            else if (tipo == 3 || tipo == 6) // Chamando a funcao do paralelogramo e do triangulo comum
            {
                printf("Digite a base: ");
                scanf("%f", &w1);
                printf("Digite a altura: ");
                scanf("%f", &w2);
                resultado = area_figura(tipo, w1, w2, 0);
            }
            else if (tipo == 4) // Chamando a funçcao do Trapezio
            {
                printf("Digite a diagonal maior: ");
                scanf("%f", &w1);
                printf("Digite a diagonal menor: ");
                scanf("%f", &w2);
                printf("Digite a altura: ");
                scanf("%f", &w3);
                resultado = area_figura(tipo, w1, w2, w3);
            }
            else if (tipo == 5) // Chamando a funcao do triangulo equilatero
            {
                printf("Digite o tamanho da diagonal: ");
                scanf("%f", &w1);
                resultado = area_figura(tipo, w1, 0, 0);
            }

            printf("O Resultado da Area e: %.2f\n", resultado);
            break;

            // Submenu 2
        case 2:
            printf("\n\n VOLUME DE SOLIDOS GEOMETRICOS ");
            printf("\n\n\n");
            printf("\n Escolha a opcao desejada:\n");
            printf("1 - Esfera\n");
            printf("2 - Cone Circular\n");
            printf("3 - Cilindro\n");
            printf("4 - Paralelepipedo\n");
            printf("Opcao: ");
            scanf("%d", &tipo);

            if (tipo == 1)
            {
                printf("Digite o diametro: ");
                scanf("%f", &w1);
                resultado = volume_solido(tipo, w1, 0, 0);
            }

            else if (tipo == 2 || tipo == 3) // Se for cilindro ou cone circular.
            {
                printf("Digite o diametro: ");
                scanf("%f", &w1);
                printf("Digite a altura: ");
                scanf("%f", &w2);
                resultado = volume_solido(tipo, w1, w2, 0);
            }
            else // Se for um paralelepipeto
            {
                printf("Digite o comprimento: ");
                scanf("%f", &w1);
                printf("Digite a largura: ");
                scanf("%f", &w2);
                printf("Digite a altura: ");
                scanf("%f", &w3);
                resultado = volume_solido(tipo, w1, w2, w3);
            }

            printf("O volume e: %f\n", resultado);
            break;

        case 3:
            puts("\n\nCONVERSAO DE MEDIDAS ");
            puts("\nEscolha a opcao desejada\n");
            printf("1 - Metros para Jardas\n2 - Jardas para Metros\n");
            printf("3 - Centimetros cubicos para Polegadas cubicas\n4 - Polegadas cubicas para Centimetros cubicos\n");
            printf("5 - Litros para Galoes\n6 - Galoes para Litros\n");
            printf("7 - Quilogramas para Libras\n8 - Libras para Quilogramas\n");

            printf("Escolha a Opcao: ");
            scanf("%d", &tipo);
            printf("Digite o valor a ser convertido: ");
            scanf("%f", &num);
            printf("Opcao: ");
            resultado = conversao(tipo, num);
            printf("O resultado da conversao e: %.2f\n", resultado);

            break;

        case 4:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao inválida!\n");
        }

        printf("Pressione <ENTER> para continuar...\n");
        getchar(); // Captura a tecla ENTER
        getchar(); // Aguarda a confirmação
        system("cls");

    } while (opcao != 4);
}