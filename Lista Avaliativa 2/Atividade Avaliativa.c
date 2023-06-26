#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funcoes.h"

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

struct Aluno 
{
    int totalUsuarios;
    int usuariosIds[MAX_USERS];
    char usuariosNomes[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEmails[MAX_USERS][MAX_EMAIL_LENGTH];
    char usuariosSexos[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEnderecos[MAX_USERS][MAX_ADDRESS_LENGTH];
    double usuariosAlturas[MAX_USERS];
    int usuariosVacinas[MAX_USERS];

};

struct Backup{

    int totalUsuariosBackup;
    int usuariosIdsBackup[MAX_USERS];
    char usuariosNomesBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEmailsBackup[MAX_USERS][MAX_EMAIL_LENGTH];
    char usuariosSexosBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEnderecosBackup[MAX_USERS][MAX_ADDRESS_LENGTH];
    double usuariosAlturasBackup[MAX_USERS];
    int usuariosVacinasBackup[MAX_USERS];

};

struct Backup backup;
struct Aluno aluno;

void fazerRestauracao() {


    aluno.totalUsuarios = backup.totalUsuariosBackup;
    for (int i = 0; i < backup.totalUsuariosBackup; i++) {
        aluno.usuariosIds[i] = backup.usuariosIdsBackup[i];
        strcpy(aluno.usuariosNomes[i], backup.usuariosNomesBackup[i]);
        strcpy(aluno.usuariosEmails[i], backup.usuariosEmailsBackup[i]);
        strcpy(aluno.usuariosSexos[i], backup.usuariosSexosBackup[i]);
        strcpy(aluno.usuariosEnderecos[i], backup.usuariosEnderecosBackup[i]);
        aluno.usuariosAlturas[i] = backup.usuariosAlturasBackup[i];
        aluno.usuariosVacinas[i] = backup.usuariosVacinasBackup[i];
    }

    printf("Restauracao realizada com sucesso!\n");
}

void fazerBackup() {

    backup.totalUsuariosBackup = aluno.totalUsuarios;

    for (int i = 0; i < aluno.totalUsuarios; i++) {
        backup.usuariosIdsBackup[i] = aluno.usuariosIds[i];
        strcpy(backup.usuariosNomesBackup[i], aluno.usuariosNomes[i]);
        strcpy(backup.usuariosEmailsBackup[i], aluno.usuariosEmails[i]);
        strcpy(backup.usuariosSexosBackup[i], aluno.usuariosSexos[i]);
        strcpy(backup.usuariosEnderecosBackup[i], aluno.usuariosEnderecos[i]);
        backup.usuariosAlturasBackup[i] = aluno.usuariosAlturas[i];
        backup.usuariosVacinasBackup[i] = aluno.usuariosVacinas[i];
    }

    printf("Backup realizado com sucesso!\n");
}

void imprimirUsuarios() {
    printf("Usuarios cadastrados:\n");
    for (int i = 0; i < aluno.totalUsuarios; i++) {
        printf("ID: %d\n", aluno.usuariosIds[i]);
        printf("Nome: %s\n", aluno.usuariosNomes[i]);
        printf("Email: %s\n", aluno.usuariosEmails[i]);
        printf("Sexo: %s\n", aluno.usuariosSexos[i]);
        printf("Endereço: %s\n", aluno.usuariosEnderecos[i]);
        printf("Altura: %.2f\n", aluno.usuariosAlturas[i]);
        printf("Vacina: %s\n", aluno.usuariosVacinas[i] == 1 ? "Sim" : "Não");
        printf("---------------------\n");
    }
}

void buscarUsuarioPorEmail() {
    char emailBusca[100];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(emailBusca, sizeof(emailBusca), stdin);
    emailBusca[strcspn(emailBusca, "\n")] = '\0';
    
    int encontrado = 0;
    int indiceEncontrado;
    
    for (int i = 0; i < aluno.totalUsuarios; i++) {
        if (strcmp(aluno.usuariosEmails[i], emailBusca) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("Usuario encontrado!\n");
        printf("ID: %d\n", aluno.usuariosIds[indiceEncontrado]);
        printf("Nome: %s\n", aluno.usuariosNomes[indiceEncontrado]);
        printf("Email: %s\n", aluno.usuariosEmails[indiceEncontrado]);
        printf("Sexo: %s\n", aluno.usuariosSexos[indiceEncontrado]);
        printf("Endereço: %s\n", aluno.usuariosEnderecos[indiceEncontrado]);
        printf("Altura: %.2lf\n", aluno.usuariosAlturas[indiceEncontrado]);
        printf("Vacina: %s\n", aluno.usuariosVacinas[indiceEncontrado] == 1 ? "Sim" : "Nao");
    } else {
        printf("Usuario nao encontrado.\n");
    }
}

void excluirUsuarioPorEmail() {
    char emailExclusao[100];
    printf("\n\nDigite o email do usuario que deseja excluir: ");
    fgets(emailExclusao, sizeof(emailExclusao), stdin);
    emailExclusao[strcspn(emailExclusao, "\n")] = '\0';
    
    int encontrado = 0;
    int indiceEncontrado;
    
    for (int i = 0; i < aluno.totalUsuarios; i++) {
        if (strcmp(aluno.usuariosEmails[i], emailExclusao) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("\n\nUsuario encontrado e excluido!\n\n");
        
        for (int j = indiceEncontrado; j < aluno.totalUsuarios - 1; j++) {
            strcpy(aluno.usuariosNomes[j], aluno.usuariosNomes[j + 1]);
            strcpy(aluno.usuariosEmails[j], aluno.usuariosEmails[j + 1]);
            strcpy(aluno.usuariosSexos[j], aluno.usuariosSexos[j + 1]);
            strcpy(aluno.usuariosEnderecos[j], aluno.usuariosEnderecos[j + 1]);
            aluno.usuariosAlturas[j] = aluno.usuariosAlturas[j + 1];
            aluno.usuariosVacinas[j] = aluno.usuariosVacinas[j + 1];
        }
        
        aluno.totalUsuarios--;
    } else {
        printf("Usuario nao encontrado.\n");
    }
}

void editarUsuarioPorEmail() {
    char emailEdicao[100];
    printf("Digite o email do usuario que deseja editar: ");
    fgets(emailEdicao, sizeof(emailEdicao), stdin);
    emailEdicao[strcspn(emailEdicao, "\n")] = '\0';
    
    int encontrado = 0;
    int indiceEncontrado;
    
    for (int i = 0; i < aluno.totalUsuarios; i++) {
        if (strcmp(aluno.usuariosEmails[i], emailEdicao) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("Usuario encontrado!\n");
        
        printf("Novo Nome completo: ");
        fgets(aluno.usuariosNomes[indiceEncontrado], sizeof(aluno.usuariosNomes[indiceEncontrado]), stdin);
        aluno.usuariosNomes[indiceEncontrado][strcspn(aluno.usuariosNomes[indiceEncontrado], "\n")] = '\0';
        
        printf("Novo Email: ");
        fgets(aluno.usuariosEmails[indiceEncontrado], sizeof(aluno.usuariosEmails[indiceEncontrado]), stdin);
        aluno.usuariosEmails[indiceEncontrado][strcspn(aluno.usuariosEmails[indiceEncontrado], "\n")] = '\0';
        
        while (!validarEmail(aluno.usuariosEmails[indiceEncontrado])) {
            printf("Email invalido. Digite novamente: ");
            fgets(aluno.usuariosEmails[indiceEncontrado], sizeof(aluno.usuariosEmails[indiceEncontrado]), stdin);
            aluno.usuariosEmails[indiceEncontrado][strcspn(aluno.usuariosEmails[indiceEncontrado], "\n")] = '\0';
        }
        
        printf("Novo Sexo (Feminino, Masculino ou Indiferente): ");
        fgets(aluno.usuariosSexos[indiceEncontrado], sizeof(aluno.usuariosSexos[indiceEncontrado]), stdin);
        aluno.usuariosSexos[indiceEncontrado][strcspn(aluno.usuariosSexos[indiceEncontrado], "\n")] = '\0';
        
        while (!validarSexo(aluno.usuariosSexos[indiceEncontrado])) {
            printf("Sexo invalido. Digite novamente: ");
            fgets(aluno.usuariosSexos[indiceEncontrado], sizeof(aluno.usuariosSexos[indiceEncontrado]), stdin);
            aluno.usuariosSexos[indiceEncontrado][strcspn(aluno.usuariosSexos[indiceEncontrado], "\n")] = '\0';
        }
        
        printf("Novo Endereço: ");
        fgets(aluno.usuariosEnderecos[indiceEncontrado], sizeof(aluno.usuariosEnderecos[indiceEncontrado]), stdin);
        aluno.usuariosEnderecos[indiceEncontrado][strcspn(aluno.usuariosEnderecos[indiceEncontrado], "\n")] = '\0';
        
        printf("Nova Altura (entre 1 e 2 metros): ");
        scanf("%lf", &aluno.usuariosAlturas[indiceEncontrado]);
        
        while (!validarAltura(aluno.usuariosAlturas[indiceEncontrado])) {
            printf("Altura invalida. Digite novamente: ");
            scanf("%lf", &aluno.usuariosAlturas[indiceEncontrado]);
        }
        
        printf("Nova Vacina (1 para sim, 0 para nao): ");
        scanf("%d", &aluno.usuariosVacinas[indiceEncontrado]);
        
        printf("Usuario editado com sucesso!\n");
    } else {
        printf("Usuario não encontrado.\n");
    }
}

void adicionarUsuario() {
    if (aluno.totalUsuarios == MAX_USERS) {
        printf("O numero maximo de usuarios foi atingido.\n");
        return;
    }

    int novoId = gerarId();
    int idExistente = 0;

    for (int i = 0; i < aluno.totalUsuarios; i++) {
        if (aluno.usuariosIds[i] == novoId) {
            idExistente = 1;
            break;
        }
    }

    if (idExistente) {
        printf("Erro ao gerar o ID. Tente novamente.\n");
        return;
    }

    aluno.usuariosIds[aluno.totalUsuarios] = novoId;

    printf("Nome completo: ");
    fgets(aluno.usuariosNomes[aluno.totalUsuarios], sizeof(aluno.usuariosNomes[aluno.totalUsuarios]), stdin);
    aluno.usuariosNomes[aluno.totalUsuarios][strcspn(aluno.usuariosNomes[aluno.totalUsuarios], "\n")] = '\0';

    printf("Email: ");
    fgets(aluno.usuariosEmails[aluno.totalUsuarios], sizeof(aluno.usuariosEmails[aluno.totalUsuarios]), stdin);
    aluno.usuariosEmails[aluno.totalUsuarios][strcspn(aluno.usuariosEmails[aluno.totalUsuarios], "\n")] = '\0';

    while (!validarEmail(aluno.usuariosEmails[aluno.totalUsuarios])) {
        printf("Email invalido. Digite novamente: ");
        fgets(aluno.usuariosEmails[aluno.totalUsuarios], sizeof(aluno.usuariosEmails[aluno.totalUsuarios]), stdin);
        aluno.usuariosEmails[aluno.totalUsuarios][strcspn(aluno.usuariosEmails[aluno.totalUsuarios], "\n")] = '\0';
    }

    printf("Sexo (Feminino, Masculino ou Indiferente): ");
    fgets(aluno.usuariosSexos[aluno.totalUsuarios], sizeof(aluno.usuariosSexos[aluno.totalUsuarios]), stdin);
    aluno.usuariosSexos[aluno.totalUsuarios][strcspn(aluno.usuariosSexos[aluno.totalUsuarios], "\n")] = '\0';

    while (!validarSexo(aluno.usuariosSexos[aluno.totalUsuarios])) {
        printf("Sexo invalido. Digite novamente: ");
        fgets(aluno.usuariosSexos[aluno.totalUsuarios], sizeof(aluno.usuariosSexos[aluno.totalUsuarios]), stdin);
        aluno.usuariosSexos[aluno.totalUsuarios][strcspn(aluno.usuariosSexos[aluno.totalUsuarios], "\n")] = '\0';
    }

    printf("Endereço: ");
    fgets(aluno.usuariosEnderecos[aluno.totalUsuarios], sizeof(aluno.usuariosEnderecos[aluno.totalUsuarios]), stdin);
    aluno.usuariosEnderecos[aluno.totalUsuarios][strcspn(aluno.usuariosEnderecos[aluno.totalUsuarios], "\n")] = '\0';

    printf("Altura (em metros): ");
    scanf("%lf", &aluno.usuariosAlturas[aluno.totalUsuarios]);
    while (getchar() != '\n'); 

    while (!validarAltura(aluno.usuariosAlturas[aluno.totalUsuarios])) {
        printf("Altura invalida. Digite novamente: ");
        scanf("%lf", &aluno.usuariosAlturas[aluno.totalUsuarios]);
        while (getchar() != '\n'); 
    }

    printf("Numero de doses da vacina: ");
    scanf("%d", &aluno.usuariosVacinas[aluno.totalUsuarios]);
    while (getchar() != '\n'); 

    aluno.totalUsuarios++;

    printf("Usuario adicionado com sucesso!\n");
}

int gerarId() {
    return rand() % 10000 + 1;
}

int validarEmail(char *email) {
    char *ptr = strchr(email, '@');
    return ptr != NULL;
}

int validarSexo(char *sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}

int validarAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

void menu(char *opcao){

    printf("Selecione uma opcaoo:\n");
    printf("1. Incluir usuario\n");
    printf("2. Editar usuario\n");
    printf("3. Excluir usuario\n");
    printf("4. Buscar usuario por email\n");
    printf("5. Imprimir todos os usuarios\n");
    printf("6. Fazer backup dos usuarios\n");
    printf("7. Fazer restauracao dos dados\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    scanf(" %c", opcao);

}

int main() {

    char opcao;
    
    do {
        
        menu(&opcao);
        
       getchar();
        
        switch (opcao) {
            case '1':
                system("cls");
                adicionarUsuario();
                break;
            case '2':
                system("cls");
                editarUsuarioPorEmail();
                break;
            case '3':
                system("cls");
                excluirUsuarioPorEmail();
                break;
            case '4':
                system("cls");
                buscarUsuarioPorEmail();
                break;
            case '5':
                system("cls");
                imprimirUsuarios();
                break;
             case '6':
                system("cls");
                fazerBackup();
                break;
             case '7':
                system("cls");
                fazerRestauracao();
                break;
            case '0':
                system("cls");
                printf("Encerrando o programa.\n");
                break;
            default:
                system("cls");
                printf("Opcao invalida. Digite novamente.\n");
                break;
        }
        
        printf("---------------------\n");
        
    } while (opcao != '0');
    
    return 0;
}
