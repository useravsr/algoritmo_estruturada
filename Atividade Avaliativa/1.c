#include<stdio.h>
int main(){

    int A;
    int B;
    int C;
    int D;
    int DIFERENCA = 0;

    printf("Insira 4 valores:");
    scanf("%d %d %d %d", &A, &B, &C, &D);

    DIFERENCA=(A*B-D*C);

    printf("DIFERENCA = (%d * %d - %d * %d)\n", A,B,C,D);
    printf("DIFERENCA = (%d)", DIFERENCA);


    return 0;
}

/*
DIFERENCA = (“valor de A” * “valor de B” - ““valor de C” * ““valor de D”)
DIFERENCA = (“valor de DIFERENCA”)

*/