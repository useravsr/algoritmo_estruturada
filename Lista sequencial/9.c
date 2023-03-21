#include<stdio.h>
#include<string.h>
int main(){

    char nome[10];
    int salario;
    int vendas;
    float comissao;

    printf("Insira seu nome: ");
    fgets(nome,10,stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Insira seu salario fixo: ");
    scanf("%d", &salario);
    printf("Valor de vendas do mes (em dinheiro): ");
    scanf("%d", &vendas);

    comissao = (float)salario + ((float)vendas * 0.15);

    printf("%s, o valor total a ser recebido sera de %.2f", nome, comissao);

    return 0; 
}


