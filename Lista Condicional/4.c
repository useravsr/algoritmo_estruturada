#include<stdio.h>
int main(){

    int salario;
    int porcentagem;
    int prestacao;


        scanf("%d", &salario);
        scanf("%d", &prestacao);
    
        porcentagem = salario*0.2;

        if(porcentagem >= prestacao){

            printf("Emprestimo condedido!");

        }else printf("Emprestimo nao concedido!");



    return 0;
}