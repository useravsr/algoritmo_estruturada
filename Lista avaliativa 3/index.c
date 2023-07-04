#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"


void liberarMemoria(Usuario* usuario){

    for (int i = 0; i < usuario->totalUsuarios; i++) {
    free(usuario->usuariosNomes[i]);
    free(usuario->usuariosEmails[i]);
    free(usuario->usuariosSexos[i]);
    free(usuario->usuariosEnderecos[i]);
}

free(usuario->usuariosNomes);
free(usuario->usuariosEmails);
free(usuario->usuariosSexos);
free(usuario->usuariosEnderecos);
free(usuario->usuariosAlturas);
free(usuario->usuariosVacinas);
free(usuario);

}

void alocarMemoria(Usuario* usuario, int tamanho) {
    usuario->usuariosNomes = malloc(tamanho * sizeof(char*));
    usuario->usuariosEmails = malloc(tamanho * sizeof(char*));
    usuario->usuariosSexos = malloc(tamanho * sizeof(char*));
    usuario->usuariosEnderecos = malloc(tamanho * sizeof(char*));
    usuario->usuariosAlturas = malloc(tamanho * sizeof(double));
    usuario->usuariosVacinas = malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        usuario->usuariosNomes[i] = malloc(100 * sizeof(char));
        usuario->usuariosEmails[i] = malloc(100 * sizeof(char));
        usuario->usuariosSexos[i] = malloc(100 * sizeof(char));
        usuario->usuariosEnderecos[i] = malloc(100 * sizeof(char));
    }
}

void menu(char* opcao) {
    printf("Selecione uma opcao:\n\n");
    printf("1- Inserir usuario.\n");
    printf("2- Editar usuarios.\n");
    printf("3- Excluir usuario.\n");
    printf("4- Listar usuarios cadastrados.\n");
    printf("5- Sair.\n>");
    scanf(" %c", opcao);
    getchar();
}

void imprimirUsuarios(Usuario* usuario) {
    for (int i = 0; i < usuario->totalUsuarios; i++) {
        printf("\n\nUSUARIO %d\n\n", i);
        printf("%s\n", usuario->usuariosNomes[i]);
        printf("%s\n", usuario->usuariosEmails[i]);
        printf("%s\n", usuario->usuariosSexos[i]);
        printf("%s\n", usuario->usuariosEnderecos[i]);
        printf("%.2lf\n", usuario->usuariosAlturas[i]);
        printf("%d\n", usuario->usuariosVacinas[i]);
    }
}

void apagarUsuario(Usuario* usuario){

    char emailExclusao[100];
    int encontrado = 0;
    int indiceEncontrado;

    printf("Digite o email do usuario que deseja editar: ");
    fgets(emailExclusao, sizeof(emailExclusao), stdin);
    emailExclusao[strcspn(emailExclusao, "\n")] = '\0';

    for(int i = 0; i < usuario->totalUsuarios; i++){
        if(strcmp(usuario->usuariosEmails[i], emailExclusao) == 0){

            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }

    if (encontrado){

        printf("\n\nUsuario encontrado e excluido!\n\n");

        for(int j = indiceEncontrado; j < usuario->totalUsuarios - 1; j++){

            strcpy(usuario->usuariosNomes[j], usuario->usuariosNomes[j+1]);
            strcpy(usuario->usuariosEmails[j], usuario->usuariosEmails[j+1]);
            strcpy(usuario->usuariosSexos[j], usuario->usuariosSexos[j+1]);
            strcpy(usuario->usuariosEnderecos[j], usuario->usuariosEnderecos[j+1]);
            usuario->usuariosAlturas[j] = usuario->usuariosAlturas[j+1];
            usuario->usuariosVacinas[j] = usuario->usuariosVacinas[j+1]; 
            
        }

        usuario->totalUsuarios--;

    }else{

        printf("Usuario nao encontrado!");

    }

}

void editarUsuario(Usuario* usuario){

    char emailEdicao[100];
    int encontrado = 0;
    int indiceEncontrado;

    printf("Digite o email do usuario que deseja editar: ");
    fgets(emailEdicao, sizeof(emailEdicao), stdin);
    emailEdicao[strcspn(emailEdicao, "\n")] = '\0';

    for(int i = 0; i < usuario->totalUsuarios; i++){
        if(strcmp(usuario->usuariosEmails[i], emailEdicao) == 0){

            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }

    if (encontrado){
        
        system("cls");
        printf("Usuario encontrado!\n");
        printf("Novo Nome completo: ");
        fgets(usuario->usuariosNomes[indiceEncontrado], 100, stdin);
        usuario->usuariosNomes[indiceEncontrado][strcspn(usuario->usuariosNomes[indiceEncontrado], "\n")] = '\0';

        printf("Novo Email: ");
        fgets(usuario->usuariosEmails[indiceEncontrado], 100, stdin);
        usuario->usuariosEmails[indiceEncontrado][strcspn(usuario->usuariosEmails[indiceEncontrado], "\n")] = '\0';
        while (!validarEmail(usuario->usuariosEmails[indiceEncontrado])) {
            printf("Email invalido. Digite novamente: ");
            fgets(usuario->usuariosEmails[indiceEncontrado], 100, stdin);
            usuario->usuariosEmails[indiceEncontrado][strcspn(usuario->usuariosEmails[indiceEncontrado], "\n")] = '\0';
        }

        printf("Novo Sexo (Feminino, Masculino ou Indiferente): ");
        fgets(usuario->usuariosSexos[indiceEncontrado], 100, stdin);
        usuario->usuariosSexos[indiceEncontrado][strcspn(usuario->usuariosSexos[indiceEncontrado], "\n")] = '\0';
        while (!validarSexo(usuario->usuariosSexos[indiceEncontrado])) {
            printf("Sexo invalido! Digite novamente:");
            fgets(usuario->usuariosSexos[indiceEncontrado], 100, stdin);
            usuario->usuariosSexos[indiceEncontrado][strcspn(usuario->usuariosSexos[indiceEncontrado], "\n")] = '\0';
        }

        printf("Novo Endereço: ");
        fgets(usuario->usuariosEnderecos[indiceEncontrado], 100, stdin);
        usuario->usuariosEnderecos[indiceEncontrado][strcspn(usuario->usuariosEnderecos[indiceEncontrado], "\n")] = '\0';

        printf("Nova Altura (entre 1 e 2 metros): ");
        scanf("%lf", &usuario->usuariosAlturas[indiceEncontrado]);
        while (getchar() != '\n');

        while (!validarAltura(usuario->usuariosAlturas[indiceEncontrado])) {
            printf("Altura invalida. Digite novamente: ");
            scanf("%lf", &usuario->usuariosAlturas[indiceEncontrado]);
            while (getchar() != '\n');
        }


        printf("Nova Vacina (1 para sim, 0 para nao): ");
         scanf("%d", &usuario->usuariosVacinas[indiceEncontrado]);
        while (getchar() != '\n');

        printf("Usuario editado com sucesso!\n\n\n");

    }else{

        printf("Usuario nao encontrado!");

    }
    

}

void adicionarUsuario(Usuario* usuario) {
    printf("Nome completo: ");
    fgets(usuario->usuariosNomes[usuario->totalUsuarios], 100, stdin);
    usuario->usuariosNomes[usuario->totalUsuarios][strcspn(usuario->usuariosNomes[usuario->totalUsuarios], "\n")] = '\0';

    printf("Email: ");
    fgets(usuario->usuariosEmails[usuario->totalUsuarios], 100, stdin);
    usuario->usuariosEmails[usuario->totalUsuarios][strcspn(usuario->usuariosEmails[usuario->totalUsuarios], "\n")] = '\0';
    while (!validarEmail(usuario->usuariosEmails[usuario->totalUsuarios])) {
        printf("Email invalido. Digite novamente: ");
        fgets(usuario->usuariosEmails[usuario->totalUsuarios], 100, stdin);
        usuario->usuariosEmails[usuario->totalUsuarios][strcspn(usuario->usuariosEmails[usuario->totalUsuarios], "\n")] = '\0';
    }

    printf("Sexo (Feminino, Masculino ou Indiferente): ");
    fgets(usuario->usuariosSexos[usuario->totalUsuarios], 100, stdin);
    usuario->usuariosSexos[usuario->totalUsuarios][strcspn(usuario->usuariosSexos[usuario->totalUsuarios], "\n")] = '\0';
    while (!validarSexo(usuario->usuariosSexos[usuario->totalUsuarios])) {
        printf("Sexo invalido! Digite novamente:");
        fgets(usuario->usuariosSexos[usuario->totalUsuarios], 100, stdin);
        usuario->usuariosSexos[usuario->totalUsuarios][strcspn(usuario->usuariosSexos[usuario->totalUsuarios], "\n")] = '\0';
    }

    printf("Endereco: ");
    fgets(usuario->usuariosEnderecos[usuario->totalUsuarios], 100, stdin);
    usuario->usuariosEnderecos[usuario->totalUsuarios][strcspn(usuario->usuariosEnderecos[usuario->totalUsuarios], "\n")] = '\0';

    printf("Altura (em metros): ");
    scanf("%lf", &usuario->usuariosAlturas[usuario->totalUsuarios]);
    while (getchar() != '\n');

    while (!validarAltura(usuario->usuariosAlturas[usuario->totalUsuarios])) {
        printf("Altura invalida. Digite novamente: ");
        scanf("%lf", &usuario->usuariosAlturas[usuario->totalUsuarios]);
        while (getchar() != '\n');
    }

    printf("Vacina(1 - Sim e 0 - Nao): ");
    scanf("%d", &usuario->usuariosVacinas[usuario->totalUsuarios]);
    while (getchar() != '\n');

    usuario->totalUsuarios++;
}

int main() {
    Usuario* usuario;
    usuario = malloc(sizeof(Usuario));
    usuario->totalUsuarios = 0;
    alocarMemoria(usuario, 100);

    char opcao;

    do {
        menu(&opcao);

        switch (opcao) {
            case '1':
                system("cls");
                adicionarUsuario(usuario);
                break;

            case '2':
                system("cls");
                editarUsuario(usuario);
                break;

            case '3':
                system("cls");
                apagarUsuario(usuario);
                break;

            case '4':
                system("cls");
                imprimirUsuarios(usuario);
                break;

            case '5':
                liberarMemoria(usuario);
                break;

            default:
                printf("Erro!");
                break;
        }

    } while (opcao != '5');

    return 0;
}
