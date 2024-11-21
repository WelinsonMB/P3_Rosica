#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Biblioteca feita para realizar calculos matemticos como raizes

#define PI 3.14159265               // Constante para PI
#define RAIZ_3 1.732050808          // Constante da Raiz de 3
#define METROS_PARA_JARDAS 1.09361  // Conversão metros para jardas
#define CMCUB_PARA_POLCUB 16.387064 // Conversão centimetros cubicos para polegadas cubicas
#define LITROS_PARA_GALOES 0.2642   // Conversão litros para galões
#define KG_PARA_LIBRAS 2.20462262   // Conversão quilos para libras

// Funcao para calcular a area  de figuras planas
float area_figura(int tipo, float w1, float w2, float w3)
{

      switch (tipo)
      {
      case 1:
            return PI * (w1 / 2) * (w1 / 2); // Circulo (w1 é o diâmetro), logo a formula é pi vezes raio ao quadrado.
      case 2:
            return (w1 * w2) / 2; // Losango (w1 e w2 são as diagonais)
      case 3:
            return w1 * w2; // Paralelogramo (w1 é a base e w2 é altura (base * altura))
      case 4:
            return ((w1 + w2) / 2) * w3; // trapezio (w1 é a base maior, w2 é a base menor e w3 é altura)
      case 5:
            return ((w1 * w1) / 4) * RAIZ_3; // triangulo quilatero (w1 é a diagonal)
      case 6:
            return (w1 * w2) / 2; // Triangulo  (w1 é a base, w2 é altura)

      default:
            return 0;
      }
}

// Função para calcular o volume do solidos geometricos

float volume_solido(int tipo, float w1, float w2, float w3)
{

      switch (tipo)
      {
      case 1:
            return ((4 * PI) / 3) * (w1 / 2) * (w1 / 2) * (w1 / 2); // Esfera onde w1 é o diametro, e operação (w1/2) é para descobrir o raio
      case 2:
            return ((PI / 3) * (w1 / 2) * (w1 / 2) * w2); // Cone, onde w1 é o diametro e w2 é altura
      case 3:
            return (PI * (w1 / 2) * (w1 / 2) * w2); // cilintro onde w1 é o diametro e w2 é altura
      case 4:
            return (w1 * w2 * w3); // Paralelepipedo  onde w1,w2 e w3 são base, largura e altura

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
            return num / METROS_PARA_JARDAS; // Nesta linha está dividindo pois é de Jardas para metros
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

main()
{
      int opcao, tipo;
      float w1, w2, w3, resultado;

      do
      {
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
            // submenu
            switch (opcao)
            {
            case 1:
                  printf("\n\n********************************************************************************");
                  printf("\n\n\t\t********** AREA DE FIGURAS PLANAS **********");
                  printf("\n\n********************************************************************************");
                  printf("\t\n Escolha a opcao desejada:");
                  printf("\n1 - Circulo\n");
                  printf("2 - Losango\n");
                  printf("3 - Paralelogramo\n");
                  printf("4 - Trapezio\n");
                  printf("5 - Triangulo equilatero\n");
                  printf("6 - Triangulo comum\n");
                  printf("0 - Retornar\n");
                  scanf("%d", &tipo);
                  
                  if (tipo == 1) //Caso selecione Circulo
                  {
                      printf("\n\tDigite o diametro do circulo: ");
                      scanf("%f", &w1);
                      resultado = area_figura(tipo, w1, w2, 0); //chamando a funcao circulo
                  }
                  
                  else if (tipo == 2 ) // Se selecionar o losango
                  {
                        printf("Digite a diagonal maior: ");
                        scanf("%f", &w1);
                        printf("Digite a diagonal menor: ");
                        scanf("%f", &w2);
                        resultado = area_figura(tipo, w1, w2, 0); //Chamando a funcão do losango
                  }
                  else if (tipo == 3 || tipo == 6)
                  {
                        printf("Digite a base: ");
                        scanf("%f", &w1);
                        printf("Digite a altura");
                        scanf("%f", &w2);
                        resultado = area_figura(tipo, w1, w2, 0);
                  }
                  else if(tipo == 4)
                  {
                        printf("Digite a diagonal maior: ");
                        scanf("%f", &w1);
                        printf("Digite a diagonal menor: ");
                        scanf("%f", &w2);
                        printf("Digite a altura");
                        scanf("%f", &w3);
                        resultado = area_figura(tipo,w1, w2,w3);
                  }
                        printf("O Resultado da Area e: %.2f\n", resultado);

            default:
                  break;
            }

      } while (opcao != 4);
}