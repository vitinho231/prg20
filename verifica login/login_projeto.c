#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libprg2/listaencadeada.h"

int main() {
    char loginDigitado[MAX_LOGIN];
    char senhaDigitada[MAX_SENHA];

    struct Nodo* listaOrdenada = NULL;

    FILE* arquivo = fopen("database.dat", "rb");
    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo de usuários.\n");
        return 1;
    }

    // Lendo os dados do arquivo e construindo a lista ordenada
    while (fread(&usuarioEncontrado, sizeof(struct Usuario), 1, arquivo)) {
        inserirOrdenado(&listaOrdenada, usuarioEncontrado.login, usuarioEncontrado.senha);
    }

    fclose(arquivo);

    // Medindo o tempo de execução
    clock_t inicio = clock();

    printf("Digite o login: ");
    scanf("%9s", loginDigitado);

    printf("Digite a senha: ");
    scanf("%9s", senhaDigitada);

    if (buscarUsuario(loginDigitado, senhaDigitada, &usuarioEncontrado)) {
        printf("Bem-vindo, %s!\n", usuarioEncontrado.nome);
    } else {
        printf("Login ou senha incorretos.\n");
    }

    // Imprimindo a lista ordenada
    printf("\nLista Ordenada:\n");
    imprimirLista(listaOrdenada);

    clock_t fim = clock();
    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos.\n", tempoExecucao);

    return 0;
}
