#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int totalUsuarios;
    char** usuariosNomes;
    char** usuariosEmails;
    char** usuariosSexos;
    char** usuariosEnderecos;
    double* usuariosAlturas;
    int* usuariosVacinas;
} Usuario;

void liberarMemoria(Usuario* usuario);
void alocarMemoria(Usuario* usuario, int tamanho);
void imprimirUsuarios(Usuario* usuario);
void apagarUsuario(Usuario* usuario);
void editarUsuario(Usuario* usuario);
void adicionarUsuario(Usuario* usuario);

#endif

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

int validarAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

int validarEmail(char* email) {
    char* ptr = strchr(email, '@');
    return ptr != NULL;
}

int validarSexo(char* sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}