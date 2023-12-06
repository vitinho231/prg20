#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_LOGIN 10
#define MAX_SENHA 10
#define MAX_NOME 30
#define NUM_USUARIOS 500

struct Usuario {
    char login[MAX_LOGIN];
    char senha[MAX_SENHA];
    char nome[MAX_NOME];
};

int verificarCredenciais(const char *login, const char *senha, const struct Usuario *usuario) {
    return (strcmp(login, usuario->login) == 0 && strcmp(senha, usuario->senha) == 0);
}

int buscarUsuario(const char *login, const char *senha, struct Usuario *usuarioEncontrado) {
    FILE *arquivo = fopen("database.dat", "rb");

    if (!arquivo) {
        fprintf(stderr, "Erro ao abrir o arquivo de usuários.\n");
        return 0;
    }

    while (fread(usuarioEncontrado, sizeof(struct Usuario), 1, arquivo)) {
        if (verificarCredenciais(login, senha, usuarioEncontrado)) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

int main() {
    char loginDigitado[MAX_LOGIN];
    char senhaDigitada[MAX_SENHA];

    printf("Digite o login: ");
    scanf("%9s", loginDigitado);

    printf("Digite a senha: ");
    scanf("%9s", senhaDigitada);

    struct Usuario usuarioEncontrado;

    // Medindo o tempo de execução
    clock_t inicio = clock();

    if (buscarUsuario(loginDigitado, senhaDigitada, &usuarioEncontrado)) {
        printf("Bem-vindo, %s!\n", usuarioEncontrado.nome);
    } else {
        printf("Login ou senha incorretos.\n");
    }

    clock_t fim = clock();
    double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos.\n", tempoExecucao);

    return 0;
}
