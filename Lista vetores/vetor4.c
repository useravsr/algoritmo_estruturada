#include<stdio.h>
#include<stdlib.h>
int main(){

    int vetor[80];
    int entrada = 0; 
    int contador = 0; 
    int quantidade = 0;
    int posicao[80];
    int opcao = 0;
    

    do{

        printf("Insira um numero para o array:");
        scanf("%d", &vetor[quantidade]);

        system("cls");

        printf("Deseja inserir mais algum numero?\n1 - Sim\n0 - Nao\n>");
        scanf("%d", &opcao);

        quantidade++;

    }while(opcao != 1 || contador > 80); 



    printf("Testar numero:");
    scanf("%d", &entrada);

    for(int i = 0; i < quantidade; i++){

        if(entrada == vetor[i]){

            posicao[contador] = i;
            contador++;

        }

    }

    if(contador>0){

        printf("Existem %d numeros iguais! ", contador);
        printf("Nas casas: ");

        for(int i = 0; i<contador; i++){

            printf("%d ", posicao[i]);

        }


    }else {

        printf("Nenhum numero igual foi encontrado!");

    }


    return 0; 

}