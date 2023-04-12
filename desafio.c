#include<stdio.h>
int main(){

    int escolha = 0;
    int valor = 0;

    printf("Escolha a conversao:\n1- Celsius para Fahrenheint\n2- Fahrenheit para Celsius\n>");
    scanf("%d", &escolha);

    printf("Insira o valor a ser convertido:");
    scanf("%d", &valor);

    (escolha == 1) ? celsius(valor) : fahrenheit(valor);


    return 0;
}

int celsius(valor){

   float resultado = (9*valor/5) + 32;
   printf("%f", resultado);

   return 0;

}

int fahrenheit(valor){

    float resultado = (valor-32)*5/9;
    printf("%f", resultado);

    return 0;

}