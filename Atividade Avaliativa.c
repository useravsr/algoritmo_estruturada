#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

int totalUsuarios = 0;
int usuariosIds[MAX_USERS];
char usuariosNomes[MAX_USERS][MAX_NAME_LENGTH];
char usuariosEmails[MAX_USERS][MAX_EMAIL_LENGTH];
char usuariosSexos[MAX_USERS][MAX_NAME_LENGTH];
char usuariosEnderecos[MAX_USERS][MAX_ADDRESS_LENGTH];
double usuariosAlturas[MAX_USERS];
int usuariosVacinas[MAX_USERS];


void fazerRestauracao() {
    int totalUsuariosBackup;
    int usuariosIdsBackup[MAX_USERS];
    char usuariosNomesBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEmailsBackup[MAX_USERS][MAX_EMAIL_LENGTH];
    char usuariosSexosBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEnderecosBackup[MAX_USERS][MAX_ADDRESS_LENGTH];
    double usuariosAlturasBackup[MAX_USERS];
    int usuariosVacinasBackup[MAX_USERS];

    totalUsuarios = totalUsuariosBackup;
    for (int i = 0; i < totalUsuariosBackup; i++) {
        usuariosIds[i] = usuariosIdsBackup[i];
        strcpy(usuariosNomes[i], usuariosNomesBackup[i]);
        strcpy(usuariosEmails[i], usuariosEmailsBackup[i]);
        strcpy(usuariosSexos[i], usuariosSexosBackup[i]);
        strcpy(usuariosEnderecos[i], usuariosEnderecosBackup[i]);
        usuariosAlturas[i] = usuariosAlturasBackup[i];
        usuariosVacinas[i] = usuariosVacinasBackup[i];
    }

    printf("Restauração realizada com sucesso!\n");
}

void fazerBackup() {
    int totalUsuariosBackup = totalUsuarios;
    int usuariosIdsBackup[MAX_USERS];
    char usuariosNomesBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEmailsBackup[MAX_USERS][MAX_EMAIL_LENGTH];
    char usuariosSexosBackup[MAX_USERS][MAX_NAME_LENGTH];
    char usuariosEnderecosBackup[MAX_USERS][MAX_ADDRESS_LENGTH];
    double usuariosAlturasBackup[MAX_USERS];
    int usuariosVacinasBackup[MAX_USERS];

    // Copiar os dados para as variáveis de backup
    for (int i = 0; i < totalUsuarios; i++) {
        usuariosIdsBackup[i] = usuariosIds[i];
        strcpy(usuariosNomesBackup[i], usuariosNomes[i]);
        strcpy(usuariosEmailsBackup[i], usuariosEmails[i]);
        strcpy(usuariosSexosBackup[i], usuariosSexos[i]);
        strcpy(usuariosEnderecosBackup[i], usuariosEnderecos[i]);
        usuariosAlturasBackup[i] = usuariosAlturas[i];
        usuariosVacinasBackup[i] = usuariosVacinas[i];
    }

    printf("Backup realizado com sucesso!\n");
}

void imprimirUsuarios() {
    printf("Usuários cadastrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", usuariosIds[i]);
        printf("Nome: %s\n", usuariosNomes[i]);
        printf("Email: %s\n", usuariosEmails[i]);
        printf("Sexo: %s\n", usuariosSexos[i]);
        printf("Endereço: %s\n", usuariosEnderecos[i]);
        printf("Altura: %.2f\n", usuariosAlturas[i]);
        printf("Vacina: %s\n", usuariosVacinas[i] == 1 ? "Sim" : "Não");
        printf("---------------------\n");
    }
}

void buscarUsuarioPorEmail() {
    char emailBusca[100];
    printf("Digite o email do usuário que deseja buscar: ");
    fgets(emailBusca, sizeof(emailBusca), stdin);
    emailBusca[strcspn(emailBusca, "\n")] = '\0';
    
    int encontrado = 0;
    int indiceEncontrado;
    
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuariosEmails[i], emailBusca) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("Usuário encontrado!\n");
        printf("ID: %d\n", usuariosIds[indiceEncontrado]);
        printf("Nome: %s\n", usuariosNomes[indiceEncontrado]);
        printf("Email: %s\n", usuariosEmails[indiceEncontrado]);
        printf("Sexo: %s\n", usuariosSexos[indiceEncontrado]);
        printf("Endereço: %s\n", usuariosEnderecos[indiceEncontrado]);
        printf("Altura: %.2lf\n", usuariosAlturas[indiceEncontrado]);
        printf("Vacina: %s\n", usuariosVacinas[indiceEncontrado] == 1 ? "Sim" : "Nao");
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
    
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuariosEmails[i], emailExclusao) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("\n\nUsuario encontrado e excluido!\n\n");
        
        for (int j = indiceEncontrado; j < totalUsuarios - 1; j++) {
            strcpy(usuariosNomes[j], usuariosNomes[j + 1]);
            strcpy(usuariosEmails[j], usuariosEmails[j + 1]);
            strcpy(usuariosSexos[j], usuariosSexos[j + 1]);
            strcpy(usuariosEnderecos[j], usuariosEnderecos[j + 1]);
            usuariosAlturas[j] = usuariosAlturas[j + 1];
            usuariosVacinas[j] = usuariosVacinas[j + 1];
        }
        
        totalUsuarios--;
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
    
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(usuariosEmails[i], emailEdicao) == 0) {
            encontrado = 1;
            indiceEncontrado = i;
            break;
        }
    }
    
    if (encontrado) {
        printf("Usuario encontrado!\n");
        
        printf("Novo Nome completo: ");
        fgets(usuariosNomes[indiceEncontrado], sizeof(usuariosNomes[indiceEncontrado]), stdin);
        usuariosNomes[indiceEncontrado][strcspn(usuariosNomes[indiceEncontrado], "\n")] = '\0';
        
        printf("Novo Email: ");
        fgets(usuariosEmails[indiceEncontrado], sizeof(usuariosEmails[indiceEncontrado]), stdin);
        usuariosEmails[indiceEncontrado][strcspn(usuariosEmails[indiceEncontrado], "\n")] = '\0';
        
        while (!validarEmail(usuariosEmails[indiceEncontrado])) {
            printf("Email invalido. Digite novamente: ");
            fgets(usuariosEmails[indiceEncontrado], sizeof(usuariosEmails[indiceEncontrado]), stdin);
            usuariosEmails[indiceEncontrado][strcspn(usuariosEmails[indiceEncontrado], "\n")] = '\0';
        }
        
        printf("Novo Sexo (Feminino, Masculino ou Indiferente): ");
        fgets(usuariosSexos[indiceEncontrado], sizeof(usuariosSexos[indiceEncontrado]), stdin);
        usuariosSexos[indiceEncontrado][strcspn(usuariosSexos[indiceEncontrado], "\n")] = '\0';
        
        while (!validarSexo(usuariosSexos[indiceEncontrado])) {
            printf("Sexo invalido. Digite novamente: ");
            fgets(usuariosSexos[indiceEncontrado], sizeof(usuariosSexos[indiceEncontrado]), stdin);
            usuariosSexos[indiceEncontrado][strcspn(usuariosSexos[indiceEncontrado], "\n")] = '\0';
        }
        
        printf("Novo Endereço: ");
        fgets(usuariosEnderecos[indiceEncontrado], sizeof(usuariosEnderecos[indiceEncontrado]), stdin);
        usuariosEnderecos[indiceEncontrado][strcspn(usuariosEnderecos[indiceEncontrado], "\n")] = '\0';
        
        printf("Nova Altura (entre 1 e 2 metros): ");
        scanf("%lf", &usuariosAlturas[indiceEncontrado]);
        
        while (!validarAltura(usuariosAlturas[indiceEncontrado])) {
            printf("Altura invalida. Digite novamente: ");
            scanf("%lf", &usuariosAlturas[indiceEncontrado]);
        }
        
        printf("Nova Vacina (1 para sim, 0 para nao): ");
        scanf("%d", &usuariosVacinas[indiceEncontrado]);
        
        printf("Usuario editado com sucesso!\n");
    } else {
        printf("Usuario não encontrado.\n");
    }
}

void adicionarUsuario() {
    if (totalUsuarios == MAX_USERS) {
        printf("O numero maximo de usuarios foi atingido.\n");
        return;
    }

    int novoId = gerarId();
    int idExistente = 0;

    for (int i = 0; i < totalUsuarios; i++) {
        if (usuariosIds[i] == novoId) {
            idExistente = 1;
            break;
        }
    }

    if (idExistente) {
        printf("Erro ao gerar o ID. Tente novamente.\n");
        return;
    }

    usuariosIds[totalUsuarios] = novoId;

    printf("Nome completo: ");
    fgets(usuariosNomes[totalUsuarios], sizeof(usuariosNomes[totalUsuarios]), stdin);
    usuariosNomes[totalUsuarios][strcspn(usuariosNomes[totalUsuarios], "\n")] = '\0';

    printf("Email: ");
    fgets(usuariosEmails[totalUsuarios], sizeof(usuariosEmails[totalUsuarios]), stdin);
    usuariosEmails[totalUsuarios][strcspn(usuariosEmails[totalUsuarios], "\n")] = '\0';

    while (!validarEmail(usuariosEmails[totalUsuarios])) {
        printf("Email invalido. Digite novamente: ");
        fgets(usuariosEmails[totalUsuarios], sizeof(usuariosEmails[totalUsuarios]), stdin);
        usuariosEmails[totalUsuarios][strcspn(usuariosEmails[totalUsuarios], "\n")] = '\0';
    }

    printf("Sexo (Feminino, Masculino ou Indiferente): ");
    fgets(usuariosSexos[totalUsuarios], sizeof(usuariosSexos[totalUsuarios]), stdin);
    usuariosSexos[totalUsuarios][strcspn(usuariosSexos[totalUsuarios], "\n")] = '\0';

    while (!validarSexo(usuariosSexos[totalUsuarios])) {
        printf("Sexo invalido. Digite novamente: ");
        fgets(usuariosSexos[totalUsuarios], sizeof(usuariosSexos[totalUsuarios]), stdin);
        usuariosSexos[totalUsuarios][strcspn(usuariosSexos[totalUsuarios], "\n")] = '\0';
    }

    printf("Endereço: ");
    fgets(usuariosEnderecos[totalUsuarios], sizeof(usuariosEnderecos[totalUsuarios]), stdin);
    usuariosEnderecos[totalUsuarios][strcspn(usuariosEnderecos[totalUsuarios], "\n")] = '\0';

    printf("Altura (em metros): ");
    scanf("%lf", &usuariosAlturas[totalUsuarios]);
    while (getchar() != '\n'); 

    while (!validarAltura(usuariosAlturas[totalUsuarios])) {
        printf("Altura invalida. Digite novamente: ");
        scanf("%lf", &usuariosAlturas[totalUsuarios]);
        while (getchar() != '\n'); 
    }

    printf("Numero de doses da vacina: ");
    scanf("%d", &usuariosVacinas[totalUsuarios]);
    while (getchar() != '\n'); 

    totalUsuarios++;

    printf("Usuario adicionado com sucesso!\n");
}

int gerarId() {
    return rand() % 10000 + 1;
}

int validarEmail(char email) {
    char ptr = strchr(email, '@');
    return ptr != NULL;
}

int validarSexo(char sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}

int validarAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}


int main() {

    char opcao;
    
    do {
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
        scanf(" %c", &opcao);
        
       getchar();
        
        switch (opcao) {
            case '1':
                adicionarUsuario();
                break;
            case '2':
                editarUsuarioPorEmail();
                break;
            case '3':
                excluirUsuarioPorEmail();
                break;
            case '4':
                buscarUsuarioPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
             case '6':
                 fazerBackup();
                 break;
             case '7':
                 fazerRestauracao();
                 break;
            case '0':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opçao invalida. Digite novamente.\n");
                break;
        }
        
        printf("---------------------\n");
        
    } while (opcao != '0');
    
    return 0;
}
