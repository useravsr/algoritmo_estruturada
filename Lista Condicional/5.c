#include<stdio.h>
#include<math.h>
int main(){

    int n1;
    float raiz;

        scanf("%d", &n1);

        if(n1>=0){
            
            raiz = sqrt(n1);
            printf("%.3f", raiz);

        }else printf("Numero inserido e negativo");

    return 0; 
}