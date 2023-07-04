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
void menu(char* opcao);
void imprimirUsuarios(Usuario* usuario);
void apagarUsuario(Usuario* usuario);
void editarUsuario(Usuario* usuario);
void adicionarUsuario(Usuario* usuario);

#endif

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