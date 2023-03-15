#include<stdio.h>
int main(){

    float altura;
    char sexo;
    float resultado = 0;

        printf("Insira sua altura: ");
        scanf("%f", &altura);

        fflush(stdin);

        printf("\nInsira seu sexo: \"M\" ou \"F\": ");
        scanf("%c", &sexo);

    if(sexo == 'M'){

       resultado = (72.7 * altura) - 58;
       printf("%.1f", resultado);

    }else if(sexo == 'F'){

       resultado = (62.1 * altura) - 44,7;
       printf("%.1f", resultado);


    };

    

}