#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265          // Constante para PI
#define RAIZ_3 1.732050808     // Constante para √3
#define METROS_PARA_JARDAS 1.09361      // Conversão metros para jardas
#define CM_CUB_PARA_POL_CUB 16.387064   // Conversão cm³ para pol³
#define LITROS_PARA_GALOES 0.2642       // Conversão litros para galões
#define KG_PARA_LIBRAS 2.20462262       // Conversão quilos para libras

// Funcao para calcular a area de figuras planas
float area_figura(int tipo, float v1, float v2) {
    // A funcao aceita 'tipo' para identificar o tipo de figura e os parametros v1 e v2.
    switch(tipo) {
        case 1: return PI * (v1 / 2) * (v1 / 2);            // Circulo (v1 e o diâmetro)
        case 2: return (v1 * v2) / 2;                        // Losango (v1 e v2 sao as diagonais)
        case 3: return v1 * v2;                              // Paralelogramo (v1 e base, v2 e altura)
        case 4: return ((v1 + v2) / 2) * v2;                 // Trapezio (v1 e base maior, v2 e base menor e altura)
        case 5: return (v1 * v2) / 2;                        // Triangulo (v1 e base, v2 e altura)
        default: return 0;
    }
}

// Função para calcular o volume de sólidos geométricos
float volume_solido(int tipo, float v1, float v2, float v3) {
    // A função aceita 'tipo' para identificar o tipo de sólido e os parâmetros v1, v2 e v3.
    switch(tipo) {
        case 1: return (4 * PI * (v1 / 2) * (v1 / 2) * (v1 / 2)) / 3;         // Esfera (v1 é o diâmetro)
        case 2: return (PI * (v1 / 2) * (v1 / 2) * v2) / 3;                   // Cone (v1 é diâmetro, v2 é altura)
        case 3: return PI * (v1 / 2) * (v1 / 2) * v2;                         // Cilindro (v1 é diâmetro, v2 é altura)
        case 4: return v1 * v2 * v3;                                          // Paralelepípedo (v1, v2, v3 são as dimensões)
        default: return 0;
    }
}

// Função para realizar as conversões de unidades
float conversao(int tipo, float num) {
    switch(tipo) {
        case 1: return num * METROS_PARA_JARDAS;        // Metros para Jardas
        case 2: return num / METROS_PARA_JARDAS;        // Jardas para Metros
        case 3: return num / CM_CUB_PARA_POL_CUB;       // Cm³ para Pol³
        case 4: return num * CM_CUB_PARA_POL_CUB;       // Pol³ para Cm³
        case 5: return num * LITROS_PARA_GALOES;        // Litros para Galões
        case 6: return num / LITROS_PARA_GALOES;        // Galões para Litros
        case 7: return num * KG_PARA_LIBRAS;            // Quilogramas para Libras
        case 8: return num / KG_PARA_LIBRAS;            // Libras para Quilogramas
        default: return 0;
    }
}

int main() {
    int opcao, tipo;
    float v1, v2, v3, resultado;

    do {
        // Menu principal
        printf("********************************************************************************\n");
        printf("********** MENU PRINCIPAL **********\n");
        printf("1 - Calcular área de figuras planas\n");
        printf("2 - Calcular volume de sólidos geométricos\n");
        printf("3 - Conversão de medidas\n");
        printf("4 - Sair\n");
        printf("Escolha a opção: ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao) {
            case 1:
                // Menu de áreas
                printf("Escolha a figura para calcular a área:\n");
                printf("1 - Círculo\n2 - Losango\n3 - Paralelogramo\n4 - Trapézio\n5 - Triângulo\n");
                printf("Escolha a opção: ");
                scanf("%d", &tipo);
                if (tipo == 1) {
                    printf("Digite o diâmetro do círculo: ");
                    scanf("%f", &v1);
                    resultado = area_figura(tipo, v1, 0);
                } else {
                    printf("Digite os parâmetros necessários:\n");
                    if (tipo == 2 || tipo == 4) {
                        printf("Digite a diagonal maior: ");
                        scanf("%f", &v1);
                        printf("Digite a diagonal menor: ");
                        scanf("%f", &v2);
                    } else if (tipo == 3 || tipo == 5) {
                        printf("Digite a base: ");
                        scanf("%f", &v1);
                        printf("Digite a altura: ");
                        scanf("%f", &v2);
                    }
                    resultado = area_figura(tipo, v1, v2);
                }
                printf("A área é: %f\n", resultado);
                break;

            case 2:
                // Menu de volumes
                printf("Escolha o sólido para calcular o volume:\n");
                printf("1 - Esfera\n2 - Cone\n3 - Cilindro\n4 - Paralelepípedo\n");
                printf("Escolha a opção: ");
                scanf("%d", &tipo);
                printf("Digite os parâmetros necessários:\n");
                if (tipo == 1 || tipo == 2 || tipo == 3) {
                    printf("Digite o diâmetro: ");
                    scanf("%f", &v1);
                    printf("Digite a altura: ");
                    scanf("%f", &v2);
                    resultado = volume_solido(tipo, v1, v2, 0);
                } else {
                    printf("Digite o comprimento: ");
                    scanf("%f", &v1);
                    printf("Digite a largura: ");
                    scanf("%f", &v2);
                    printf("Digite a altura: ");
                    scanf("%f", &v3);
                    resultado = volume_solido(tipo, v1, v2, v3);
                }
                printf("O volume é: %f\n", resultado);
                break;

            case 3:
                // Menu de conversões
                printf("Escolha a conversão:\n");
                printf("1 - Metros para Jardas\n2 - Jardas para Metros\n3 - Cm³ para Pol³\n");
                printf("4 - Pol³ para Cm³\n5 - Litros para Galões\n6 - Galões para Litros\n");
                printf("7 - Quilogramas para Libras\n8 - Libras para Quilogramas\n");
                printf("Escolha a opção: ");
                scanf("%d", &tipo);
                printf("Digite o valor a ser convertido: ");
                scanf("%f", &v1);
                resultado = conversao(tipo, v1);
                printf("O resultado da conversão é: %f\n", resultado);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

        printf("Pressione <ENTER> para continuar...\n");
        getchar();  // Captura a tecla ENTER
        getchar();  // Aguarda a confirmação
    } while (opcao != 4);

    return 0;
}
