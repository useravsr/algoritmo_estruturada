#include <stdio.h>
int main(){

    int n1[4];
    int n2[4];
    int total[4];

    for(int i = 0; i<4; i++){

        scanf("%d %d", &n1[i], &n2[i]);
      
        total[i] = n1[i] + n2[i];

        if(total[i] % 2 == 0){

            printf ("Par\n");

        } else {

            printf("Impar\n");

        }
    }

    return 0; 
}