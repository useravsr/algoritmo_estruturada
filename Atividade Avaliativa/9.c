#include<stdio.h>
int main(){

    int escolha = 0;
    int quantidade = 0;
    int total = 0; 

    do{

        printf("Lista de compras:\n1 -> Abacaxi - 5,00 a unidade.\n2 -> Maca - 1,00 a unidade.\n3 -> Pera - 4,00 a unidade.\n4 - Finalizar compra\n>");
        scanf("%d", &escolha);


        switch(escolha){

            case 1:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &quantidade);
                total += 5 * quantidade;
            break;
            case 2:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &quantidade);
                total += 1 * quantidade;
            break;
            case 3:
                printf("Insira a quantidade de frutas:");
                scanf("%d", &quantidade);
                total += 4 * quantidade;
            break;

        }

    }while(escolha!=4);

    printf("Total de compras: %d", total);

    return 0;
}