#include<stdio.h>
int main(){

    int n1;
    int opcao;

    printf("Insira um numero:");
    scanf("%d", &n1);

    printf("Escolha impar ou par:\n1-Impar\n2-Par\n>");
    scanf("%d", &opcao);

    switch(opcao){

        case 1:
            for (int i = 1; i < n1; i+=2){

                printf("%d\n", i);
        
            }
         break;

         case 2:
            for (int i = 0; i < n1; i+=2){

                printf("%d\n", i);

            }

    }


    return 0;
}