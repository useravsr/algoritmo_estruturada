#include<stdio.h>
int main(){

    int soma = 0;

    for(int i=1;i<=1000;i++){

        if(i%3==0 || i%5==0){

            soma+=i;
            printf("%d ", i);

        }

    }

    printf(" %d", soma);

    return 0;
}