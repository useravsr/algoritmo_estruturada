#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

    int n1;
    float n2;
    double n3;
    char n4;
    char n5[10];
    int n6; 


        printf("Insira um numero inteiro: ");
        scanf("%d", &n1);

        printf("Insira dois numeros reais: ");
        scanf("%f %lf", &n2, &n3);

            fflush(stdin);

        printf("Insira uma letra: ");
        scanf("%c", &n4);

            fflush(stdin);

        printf("Insira uma string: ");
        fgets(n5, 10, stdin);
        n5[strcspn(n5, "\n")] = 0;

            fflush(stdin);

        printf("Insira um inteiro(Endereco): ");
        scanf("%d", &n6);

            system("cls");

        printf("Numero inteiro: %d\n", n1);
        printf("Numeros reais: %.3f e %lf\n", n2, n3);
        printf("Letra: %c\n", n4);
        printf("String: %s\n", n5);
        printf("Endereco: %x\n", &n6);

    
    return 0;

}