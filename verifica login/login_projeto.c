#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "libprg2/listaencadeada.h"

void para_demorar() {
    printf("Pressione ENTER para prosseguir\n");
    while (getchar() != '\n');
}

struct User {
    char username[50];
    char password[50];
    char fullName[100];
};

int main() {
    FILE *file = fopen("database.dat", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    struct timeval inicio, fim;
    gettimeofday(&inicio, NULL);

    para_demorar();

    gettimeofday(&fim, NULL);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;

    printf("Tempo gasto: %f segundos.\n", tempo_total);

    struct User users[500];
    for (int i = 0; i < 500; i++) {
        fscanf(file, "%49s %49s %[^\n]", users[i].username, users[i].password, users[i].fullName);
    }

    fclose(file);

    char inputUsername[50];
    char inputPassword[50];
    printf("Login: ");
    scanf("%49s", inputUsername);
    printf("Senha: ");
    scanf("%49s", inputPassword);

    // Criando lista encadeada e adicionando logins a ela
    ListaEncadeada lista;
    inicializaLista(&lista);

    for (int i = 0; i < 500; i++) {
        insereOrdenado(&lista, users[i].username, users[i].password);
    }

    // Imprimindo lista ordenada
    imprimeLista(&lista);

    // Procurando usuário na lista ordenada
    if (procuraUsuario(&lista, inputUsername, inputPassword)) {
        printf("Bem-vindo, %s!\n", obtemNome(&lista, inputUsername));
    } else {
        printf("Credenciais inválidas.\n");
    }

    // Liberando memória alocada para a lista encadeada
    liberaLista(&lista);

    return 0;
}

