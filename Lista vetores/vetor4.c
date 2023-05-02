#include<stdio.h>
#include<stdlib.h>
int main(){

    int vetor[6];
    int entrada = 0; 
    int contador = 0; 
    int posicao[6];
    
    for(int i=0; i<6; i++){

        vetor[i] = rand() % 100;
        printf("%d\n", vetor[i]);

    }   

    printf("Insira um numero:");
    scanf("%d", &entrada);

    for(int i = 0; i < 6; i++){

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