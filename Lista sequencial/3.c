#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

    int numeroInteiro;
    float numeroReal;
    double numeroRealDouble;
    char letra;
    char umaString[10];
    int endereco; 


        printf("Insira um numero inteiro: ");
        scanf("%d", &numeroInteiro);

        printf("Insira dois numeros reais: ");
        scanf("%f %lf", &numeroReal, &numeroRealDouble);

            fflush(stdin);

        printf("Insira uma letra: ");
        scanf("%c", &letra);

            fflush(stdin);

        printf("Insira uma string: ");
        fgets(umaString, 10, stdin);
        umaString[strcspn(umaString, "\n")] = 0;

            fflush(stdin);
            system("cls");

        printf("Numero inteiro: %d\n", numeroInteiro);
        printf("Numeros reais: %.3f e %lf\n", numeroReal, numeroRealDouble);
        printf("Letra: %c\n", letra);
        printf("String: %s\n", umaString);
        printf("Endereco: %x\n", &numeroInteiro);

    
    return 0;

}