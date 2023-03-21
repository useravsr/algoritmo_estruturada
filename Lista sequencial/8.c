#include<stdio.h>
int main(){

    int a;
    int b;
    int c;
    int d;
    int DIFERENCA;

        printf("Insira 4 valores inteiros, A, B, C e D: ");
        scanf("%d %d %d %d", &a, &b, &c, &d);

            DIFERENCA = (a*b - c*d);
        
        printf("DIFERENCA = %d", DIFERENCA);

    return 0;
}