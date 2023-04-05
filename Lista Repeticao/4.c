#include<stdio.h>
int main(){

    int n1=0;
    int n2;

    scanf("%d", &n2);

    for(int i = 0; i < n2 ; i++){

        n1+=3;
        if(n1 > n2) break;
        if(n1 != 0) printf("%d\n", n1);


    }

    return 0; 
}