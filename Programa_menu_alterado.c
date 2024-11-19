#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Biblioteca feita para realizar calculos matemticos como raizes 

#define PI 3.14159265                    // Constante para PI
#define RAIZ_3 1.732050808              // Constante da Raiz de 3
#define METROS_PARA_JARDAS 1.09361      // Conversão metros para jardas
#define CMCUB_PARA_POLCUB 16.387064   // Conversão centimetros cubicos para polegadas cubicas
#define LITROS_PARA_GALOES 0.2642       // Conversão litros para galões
#define KG_PARA_LIBRAS 2.20462262       // Conversão quilos para libras

 //Funcao para calcular a area  de figuras planas 
float area_figura(int tipo, float w1, float w2, float w3){

      switch (tipo)
      {
      case 1: return PI * (w1/2) * (w1/2); //Circulo (w1 é o diâmetro), logo a formula é pi vezes raio ao quadrado.
      case 2: return (w1 * w2) / 2; //Losango (w1 e w2 são as diagonais)
      case 3: return w1 * w2; //Paralelogramo (w1 é a base e w2 é altura (base * altura))
      case 4: return ((w1 + w2)/2)*w3; //trapezio (w1 é a base maior, w2 é a base menor e w3 é altura)
      case 5: return ((w1 * w1) / 4) * RAIZ_3; // triangulo quilatero (w1 é a diagonal)
      case 6: return (w1 * w2) /2; //Triangulo  (w1 é a base, w2 é altura)

      default: return 0;
      }
}

//Função para calcular o volume do solidos geometricos

float volume_solido(int tipo, float w1, float w2, float w3){

      switch (tipo)
      {
      case 1: return ((4 * PI) / 3)*(w1/2)*(w1/2)*(w1/2); //Esfera onde w1 é o diametro, e operação (w1/2) é para descobrir o raio
      case 2: return ((PI/3)*(w1/2)*(w1/2)*w2); //Cone, onde w1 é o diametro e w2 é altura
      case 3: return (PI * (w1/2)* (w1/2) * w2); //cilintro onde w1 é o diametro e w2 é altura
      case 4: return (w1 * w2 * w3 ); //Paralelepipedo  onde w1,w2 e w3 são base, largura e altura

      default: return 0;
            break;
      }

}

float conversao(int tipo, float num){
      switch (tipo){
      case 1: return num * METROS_PARA_JARDAS;
      case 2: return num / METROS_PARA_JARDAS; // Nesta linha está dividindo pois é de Jardas para metros 
      case 3: return num / CMCUB_PARA_POLCUB; // Centimetros cubicos para polegadas cubicas
      case 4: return num * CMCUB_PARA_POLCUB; //Polegadas cubicas para centimetros cubicos
      case 5: return num * LITROS_PARA_GALOES;
      case 6: return num / LITROS_PARA_GALOES; //Galoes para litroes
      case 7: return num * KG_PARA_LIBRAS; 
      case 8: return num / KG_PARA_LIBRAS; //Libras para Kg 
      default: return 0; 
            
      }
}


      

      
main()
{
      int opcao;
      
            do{        //primeiro looping
                                  //menu principal
      printf("********************************************************************************");
      puts  ("\n\n\t\t********** P R O G R A M A   M E N U **********");
      printf("\n\n********************************************************************************");
      puts("\n\n \tEscolha a opcao desejada:");
      
      puts("\n\t 1 - Calcular area de figuras planas");
      puts("\t 2 - Calcular volume de solidos geometricos"); 
      puts("\t 3 - Conversao de medidas");
      puts("\t 4 - Sair");
      printf("\n\t\t\t\tOpcao: "); scanf ("%d", &opcao);
      
      fflush(stdin);          //limpa o buffer do teclado
      system("cls");          //limpa a tela
      
      switch (opcao)          //escolha
      { 
                     
                case 1:
                do            //segundo looping
                { 
                        //submenu 1
            printf("\n\n********************************************************************************");         
            puts("\n\n\t\t********** AREA DE FIGURAS PLANAS **********");
            printf("\n\n********************************************************************************");
            puts("\t\n Escolha a opcao desejada:");
            puts("\n\t 1 - Circulo");
            puts("\t 2 - Losango");
            puts("\t 3 - Paralelogramo");
            puts("\t 4 - Trapezio");
            puts("\t 5 - Triangulo");
            puts("\t 0 - Retornar");
            printf("\t\t\t\tOpcao: ");
            scanf("\n\t%d", &opcao);
      
      fflush(stdin);          
      system("cls");
      
      float dia, area, d1, d2, base, alt;          //declara��o das 
      float A, B, C;                                 // vari�veis que ser�o usadas no switch
      
      switch(opcao)    //segunda escolha    
      {
      case 1:           
           printf("\n\n********************************************************************************");
           puts("\n\n\t\t********** 1. AREA DO CIRCULO **********");     
           printf("\n\n********************************************************************************");
           printf("\n\tDigite o diametro do circulo: ");
           scanf("%f", &dia);
           area= circulo(dia);
           printf("\n\n\n\n\n\t>>>  A area do circulo e %f", area);
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
            
     case 2:
           printf("\n\n********************************************************************************");
           puts("\n\n\t\t********** 2. AREA DO LOSANGO **********");
           printf("\n\n********************************************************************************");
           printf("\n\tDigite a diagonal 1: "); scanf("%f", &d1);
           printf("\n\tDigite a diagonal 2: "); scanf("%f", &d2);
           area= losango(d1,d2);
           printf("\n\n\t>>>  A area do losango e %f", area);
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
     
     case 3:
          printf("\n\n********************************************************************************");
          puts("\n\n\t\t********** 3. AREA DO PARALELOGRAMO **********");
          printf("\n\n********************************************************************************");
          printf("\n\n\n\tDigite a base: "); scanf("%f", &base);
          printf("\n\tDigite a altura: "); scanf("%f", &alt);
          area=paralelogramo(base,alt);
          printf("\n\n\t>>> A area do paralelogramo e %f", area);
          printf("\n\n\n\n********************************************************************************");
          printf("\n\n Pressione <ENTER> para retornar ao menu.");
          getch(); break;
          
     case 4:
          printf("\n\n********************************************************************************");
          puts("\n\n\t\t********** 4. AREA DO TRAPEZIO **********");
          printf("\n\n********************************************************************************");        
          printf("\n\tDigite a base maior: "); scanf("%f", &B);
          printf("\n\tDigite a base menor: "); scanf("%f", &base); 
          printf("\n\tDigite a altura: "); scanf("%f", &alt);
          area=trapezio(B,base,alt);
          printf("\n\n\t>>> A area do trapezio e: %f", area);
          printf("\n\n********************************************************************************");
          printf("\n\n Pressione <ENTER> para retornar ao menu.");
          getch(); break;
     
     case 5:
          printf("\n\n********************************************************************************");
          puts("\n\n\t\t********** 5. AREA DO TRIANGULO **********");
          printf("\n\n********************************************************************************");
          printf("\n\tDigite o lado A do triangulo: "); scanf("%f", &A);
          printf("\n\tDigite o lado B do triangulo: "); scanf("%f", &B);
          printf("\n\tDigite o lado C do triangulo: "); scanf("%f", &C);
           if(A==B && B==C)
          {
             area=tri_equi(A,B,C);
             printf(" \n\n\n\t\tTriangulo Equilatero >>> area: %f", area);
             printf("\n\n********************************************************************************");
             printf("\n\n Pressione <ENTER> para retornar ao menu."); getch();
             }
             else
                 if(A!=B && B!=C && A!=C)
            {
              area=tri(A,B,C);
              printf("\n\n\n\t\tTriangulo Escaleno >>> area: %f", area);
              printf("\n\n********************************************************************************");
              printf("\n\n Pressione <ENTER> para retornar ao menu.");
              getch();
              }
                   else 
                    if(A==C && A!=B && B!=C||A==B&&A!=C&&B!=C||C==B&&C!=A&&B!=A)
                    {
                      area=tri(A,B,C);
                      printf("\n\n\n\t\tTriangulo Isosceles >>> area: %f", area);
                      printf("\n\n********************************************************************************");      
                      printf("\n\n Pressione <ENTER> para retornar ao menu.");
                      getch();
                      }
                      
                      break;
    case 0: break;
         
    default:
                  printf    ("\n\n ******************************* opcao invalida ********************************");
                  printf ("Pressione <ENTER> para retornar ao menu");
                  getch();
      }           //fecha o "segunda escolha"
           
      system("cls"); 
      }              //fecha o segundo looping
      while (opcao!=0);            //condi��o para voltar para o submenu 1
      break;           //vai direto para o fim do primeiro switch sem testar os demais case      
              
              case 2:
                   
                   do        //terceiro looping
                   {
                             // submenu 2
                   printf("\n\n********************************************************************************");
                   puts("\n\n\t\t********** VOLUME DE SOLIDOS GEOMETRICOS **********");
                   printf("\n\n\n********************************************************************************");          
                   puts("\n\t Escolha a opcao desejada:");
                   puts("\n\t 1 - Esfera");
                   puts("\t 2 - Cone Circular");
                   puts("\t 3 - Cilindro");
                   puts("\t 4 - Paralelepipedo");
                   puts("\t 0 - Retornar");
            
            printf("\n\t\t\t\tOpcao: "); scanf("%d", &opcao);
          
    fflush(stdin);
    system("cls");
    
    float dia, vol, alt, comp, larg;
    switch (opcao)
    {
    case 1:
           printf("\n\n\n********************************************************************************");
           puts("\n\n\t\t********** 1. VOLUME DA ESFERA **********");
           printf("\n\n********************************************************************************");
           printf("\nDigite o diametro: "); scanf("%f", &dia);
                vol=esf(dia);         
           printf("\n\n\n\t>>> O volume da esfera e %f.",  vol);
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
       
    case 2:
           printf("\n\n\n********************************************************************************");
           puts ("\n\n\t\t********** 2. VOLUME DO CONE CIRCULAR **********");
           printf("\n\n********************************************************************************");
           printf("\n\tDigite o diametro da base:  "); scanf("%f",&dia);
           printf("\n\tDigite altura:  "); scanf("%f",&alt);
           vol=cone(dia,alt); 
           printf("\n\t>>> O volume do cone circular e %f.", vol );
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
               
    case 3:
           printf("\n\n\n********************************************************************************");
           puts("\n\n\t\t********** 3. VOLUME CILINDRO **********");
           printf("\n\n********************************************************************************");
           printf("\n\tDigite o diametro: "); scanf("%f",&dia);
           printf("\n\tDigite altura:  "); scanf("%f",&alt);
           vol= cilindro(dia,alt);
           printf("\n\t>>>O volume do cilindro e %f", vol);
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
           
    case 4:
           printf("\n\n\n********************************************************************************");
           puts("\n\n\t\t********** 4. VOLUME DO PARALELEPIPEDO **********");
           printf("\n\n********************************************************************************");
           printf("\n\tDigite o comprimento:  "); scanf("%f",&comp);
           printf("\n\tDigite a largura:  "); scanf("%f",&larg);
           printf("\n\tDigite a altura:  "); scanf("%f",&alt);
           vol=paral(comp, larg, alt);
           printf("\n\t>>>O volume do paralelepipedo e %f.",vol);
           printf("\n\n\n********************************************************************************");
           printf("\n\n Pressione <ENTER> para retornar ao menu.");
           getch(); break;
    
    case 0:
           break;       

    default:
           printf ("\n\n ******************************* opcao invalida ********************************");
           printf ("Pressione <ENTER> para retornar ao menu");
           getch();
            }              //fecha o terceiro switch 
            
             system("cls");
             
              }
           while(opcao!=0);        //condi��o para voltar para o submenu 2
           break;   
        
           case 3:
           do       
           {
                                   //submenu 3
      printf("\n\n********************************************************************************");
      puts("\n\n\t\t********** CONVERSAO DE MEDIDAS **********");
      printf("\n********************************************************************************");
      puts("\n\t\t\t Escolha a opcao desejada");
      puts("\n Converter:\n");
      printf(" 1 - Metros para Jardas");                                   printf("\t\t\t\t 5 - Litros para Galoes\n");
      printf("\n 2 - Jardas para Metros");                                 printf("\t\t\t\t 6 - Galoes para Litros\n");
      printf("\n 3 - Centimetros cubicos para Polegadas cubicas");         printf("\t 7 - Quilogramas para Libras\n");
      printf("\n 4 - Polegadas cubicas para Centimetros cubicos");         printf("\t 8 - Libras para Quilogramas\n");
            
            
            puts("\n\n\t\t 0 - Retornar");
            printf("\t\t\t\tOpcao: ");
            scanf("\n\t%d", &opcao);
      
      system("cls");      
      fflush(stdin);
      
      float num, result;
      
      switch (opcao)
      {
             case 1:
                  printf("\n\n********************************************************************************");
                  puts("\n\n\t\t********** 1. METROS EM JARDAS **********");     
                  printf("\n\n********************************************************************************");
                  printf("\n\n\tDigite o valor em metros a ser convertido: ");
                  scanf("%f", &num);
                  result= m_j(num);
                  printf("\n\n\t\t %f m = %f yd", num, result);
                  printf("\n\n\n\n\n********************************************************************************");
                  printf("\n\n Pressione <ENTER> para retornar ao menu.");
                  getch(); break;
           
             case 2:
                  printf("\n\n********************************************************************************");
                  puts("\n\n\t\t********** 2. JARDAS EM METROS **********");     
                  printf("\n\n********************************************************************************");
                  printf("\n\n\tDigite o valor em jardas a ser convertido: ");
                  scanf("%f", &num);
                  result= j_m(num);
                  printf("\n\n\t\t %f yd = %f m", num, result);
                  printf("\n\n\n\n\n********************************************************************************");
                  printf("\n\n Pressione <ENTER> para retornar ao menu.");
                  getch(); break;
             
             case 3:
                  printf("\n\n********************************************************************************");
                  puts("\n\n\t********* 3. CENTIMETROS CUBICOS EM POLEGADAS CUBICAS **********");     
                  printf("\n\n********************************************************************************");          
                  printf("\n\n\tDigite o valor em centimetros cubicos a ser convertido: ");
                  scanf("%f", &num);
                  result= cmcub_polcub(num);
                  printf("\n\n\t\t %f cm3 = %f in3", num, result);
                  printf("\n\n********************************************************************************");
                  printf("\n\n Pressione <ENTER> para retornar ao menu.");
                  getch(); break;
           
             case 4:
                  printf("\n\n********************************************************************************");
                  puts("\n\n\t********** 4. POLEGADAS CUBICAS EM CENTIMETROS CUBICOS **********");     
                  printf("\n\n********************************************************************************");
                  printf("\nDigite o valor em polegadas cubicas a ser convertido: ");
                  scanf("%f", &num);
                  result= polcub_cmcub(num);
                  printf("\n\n\t\t %f in3 = %f cm3", num, result);
                  printf("\n\n********************************************************************************");
                  printf("\n\n Pressione <ENTER> para retornar ao menu.");
                 getch(); break;
            
            case 5:
                 printf("\n\n********************************************************************************");
                 puts("\n\n\t\t********** 5. LITROS EM GALOES **********");     
                 printf("\n\n********************************************************************************");
                 printf("\nDigite o valor em litros a ser convertido: ");
                 scanf("%f", &num);
                 result= l_gl(num);
                 printf("\n\n\t\t %f L = %f gal", num, result);
                 printf("\n\n********************************************************************************");
                 printf("\n\n Pressione <ENTER> para retornar ao menu.");
                 getch(); break;
           
            case 6:
                 printf("\n\n********************************************************************************");
                 puts("\n\n\t\t********** 6. GALOES EM LITROS **********");     
                 printf("\n\n********************************************************************************");
                 printf("\nDigite o valor em galoes a ser convertido: ");
                 scanf("%f", &num);
                 result= gl_l(num);
                 printf("\n\n\t\t %f gal = %f L", num, result);
                 printf("\n\n********************************************************************************");
                 printf("\n\n Pressione <ENTER> para retornar ao menu.");
                 getch(); break;
           
           case 7:
                printf("\n\n********************************************************************************");
                puts("\n\n\t********** 7. QUILOGRAMAS EM LIBRAS **********");     
                printf("\n\n********************************************************************************");
                printf("\nDigite o valor em quilogramas a ser convertido: ");
                scanf("%f", &num);
                result= kg_lib(num);
                printf("\n\n\t\t %f kg = %f lb", num, result);
                printf("\n\n********************************************************************************");
                printf("\n\n Pressione <ENTER> para retornar ao menu.");
                getch(); break;                                                                                                               
           
           case 8:
                printf("\n\n********************************************************************************");
                puts("\n\n\t********* 8. LIBRAS EM QUILOGRAMAS **********");     
                printf("\n\n********************************************************************************");          
                printf("\nDigite o valor em libras a ser convertido: ");
                scanf("%f", &num);
                result= lib_kg(num);
                printf("\n\n\t\t %f lb = %f kg", num, result);
                printf("\n\n********************************************************************************");
                printf("\n\n Pressione <ENTER> para retornar ao menu.");
                getch(); break;
           
           case 0:break;
                  
           default:
           printf ("\n\n ******************************* opcao invalida ********************************");
           printf ("Pressione <ENTER> para retornar ao menu");
           getch();
           }
           
           system("cls");
           }
           while(opcao!=0);      //cond. volta para o terceiro submenu
           break;   
             
             case 4:
                  break;
                  
             default:
             printf ("\n\n ******************************* opcao invalida ********************************");
             printf ("Pressione <ENTER> para retornar ao menu");
             }      //fecha o primeito switch
             getch();
             system("cls");
             
}            //fecha o primeiro looping
while (opcao!=4);

 return 0;
}

