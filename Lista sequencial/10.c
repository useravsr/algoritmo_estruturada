#include<stdio.h>
#include<math.h>
int main(){

    int x1;
    int x2;
    int y1;
    int y2;
    float distancia;

        printf("Insira 4 valores correspondentes aos eixos, X1, X2, Y1, Y2: ");
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

        distancia = sqrt(pow(((float)x2-(float)x1),2)+pow(((float)y2-(float)y1),2)); 

        printf("Distancia = %.4f", distancia);




    return 0;
}