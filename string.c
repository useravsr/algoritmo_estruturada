#include<stdio.h>
#include<string.h>
int main(){

    char nome[100];
    char sobrenome[100];

    scanf("%s %s", nome, sobrenome);

    (strlen(nome) > strlen(sobrenome)) ? printf("Frase 1 maior que frase 2") : printf("Frase 2 maior que frase 1");
    
    if(strlen(nome) == strlen(sobrenome)) printf("As frases posuem o mesmo tamanho");
        
    return 0;
}
