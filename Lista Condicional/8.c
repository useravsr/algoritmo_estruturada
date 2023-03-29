#include <stdio.h>
int main(){

    int estado;
    int valor;
    int imposto;

    printf("            1  |   2  |   3  |  4\n");
    printf("Estados :  MG  |  SP  |  RJ  | MS\nImposto :  7%%  |  12%% | 15%%  | 8%%\n\n\n");
    printf("Insira o numero refente ao estado:");

    scanf("%d", &estado);

    printf("Insira o valor do produto: ");
    scanf("%d", &valor);

    switch(estado){

        case 1:

            imposto = valor*0.7;

        break;

        case 2:

            imposto = valor*0.12;

        break;

        case 3:

            imposto = valor*0.15;

        break;

        case 4:

            imposto = valor*0.8;

        break;

        default:

            printf("Estado inserido invalido!");
        
        break;

    }

    printf("O valor final do produto sera de %d", valor + imposto);

    return 0;
}