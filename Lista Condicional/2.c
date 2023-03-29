#include<stdio.h>
int main(){

    int n1;
    int n2;

        scanf("%d %d", &n1, &n2);

    if(n1>n2) printf("O maior e %d.", n1);
    if(n1<n2) printf("O maior e %d.", n2);  
    if(n1==n2) printf("Os 2 numeros inseridos sao iguais!");  


    return 0; 
}