#include<stdio.h>
int main(){

    int n1;
    int n2;
    int n3 = 9 ; 

    printf("Insira um intervalo:");
    scanf("%d %d", &n1, &n2);

    for(int i = n1; i<n2 ; i++){

        n3+=2;
        if(n3 > n2) break;
        printf("%d\n", n3);

    }


    return 0;
}