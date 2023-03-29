#include<stdio.h>
int main(){

    int A;
    int B;
    int C;
    int D;
    int somaAB;
    int somaDC;

        scanf("%d %d %d %d", &A, &B, &C, &D);

        somaAB = A + B;
        somaDC = D + C;

        if(B>C && D>A && C + D > A + B && C>0 && D>0 && A%2==0){
            
             printf("Valores aceitos!");
                   
        }else printf("Valores nao aceitos");



    return 0;
}