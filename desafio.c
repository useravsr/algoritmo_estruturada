#include<stdio.h>

float celsius(float valor){

    return (9.0/5.0 * valor) + 32;

}

float fahrenheit(float valor){

    return (valor-32)*5.0/9.0;

}

float formula (float k, float f){

    return k - f + 273.15;


}

int main(){

    int escolha = 0;
    float f = 0;
    float k = 0;
    float resultado = 0;

    printf("Escolha a conversao:\n1- Celsius para Fahrenheint\n2- Fahrenheit para Celsius\n3 - Kelvin para Celsius\n>");
    scanf("%d", &escolha);

    printf("Insira o valor de f:");
    scanf("%f", &f);

    printf("Insira o valor de k:");
    scanf("%f", &k);
    


    switch(escolha){

        case 1:
            resultado = celsius(f);
            printf("%.2f",resultado);
            break;
        
        case 2:
            resultado = fahrenheit(f);
            printf("%.2f", resultado);
            break;

        case 3: 
            resultado = formula(k ,f);
            printf("%.2f", resultado);
            break;

    }

    


    return 0;
}