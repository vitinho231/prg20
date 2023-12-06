// verifica login/login_projeto.c

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libprg2/tabelahash.h"

// ... (Definições de constantes e estruturas existentes)

int main(int argc, char *argv[]) {
    if (argc == 3) {
        // Modo de teste: receber login e senha como argumentos
        char* loginDigitado = argv[1];
        char* senhaDigitada = argv[2];

        struct TabelaHash* tabela = criarTabelaHash(TAMANHO_TABELA_HASH);

        // Lê os dados do arquivo e insere na tabela hash
        FILE* arquivo = fopen("database.dat", "rb");
        if (!arquivo) {
            fprintf(stderr, "Erro ao abrir o arquivo de usuários.\n");
            return 1;
        }

        struct Usuario usuarioEncontrado;
        while (fread(&usuarioEncontrado, sizeof(struct Usuario), 1, arquivo)) {
            inserirNaTabela(tabela, usuarioEncontrado.login, usuarioEncontrado.senha);
        }

        fclose(arquivo);

        // Medindo o tempo de execução
        clock_t inicio = clock();

        if (buscarNaTabela(tabela, loginDigitado, senhaDigitada)) {
            printf("Bem-vindo, %s!\n", usuarioEncontrado.nome);
        } else {
            printf("Login ou senha incorretos.\n");
        }

        liberarTabelaHash(tabela);

        clock_t fim = clock();
        double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos.\n", tempoExecucao);

        return 0;
    } else {

    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        // Modo de teste: receber login e senha como argumentos
        char* loginDigitado = argv[1];
        char* senhaDigitada = argv[2];

        struct TabelaHash* tabela = criarTabelaHash(TAMANHO_TABELA_HASH);

        // Lê os dados do arquivo e insere na tabela hash
        FILE* arquivo = fopen("database.dat", "rb");
        if (!arquivo) {
            fprintf(stderr, "Erro ao abrir o arquivo de usuários.\n");
            return 1;
        }

        struct Usuario usuarioEncontrado;
        while (fread(&usuarioEncontrado, sizeof(struct Usuario), 1, arquivo)) {
            inserirNaTabela(tabela, usuarioEncontrado.login, usuarioEncontrado.senha);
        }

        fclose(arquivo);

        // Medindo o tempo de execução
        clock_t inicio = clock();

        if (buscarNaTabela(tabela, loginDigitado, senhaDigitada)) {
            printf("Bem-vindo, %s!\n", usuarioEncontrado.nome);
        } else {
            printf("Login ou senha incorretos.\n");
        }

        liberarTabelaHash(tabela);

        clock_t fim = clock();
        double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos.\n", tempoExecucao);

        return 0;
    } else {
        // Modo interativo: receber login e senha do usuário
        char loginDigitado[MAX_LOGIN];
        char senhaDigitada[MAX_SENHA];

        printf("Digite o login: ");
        scanf("%9s", loginDigitado);

        printf("Digite a senha: ");
        scanf("%9s", senhaDigitada);

        struct TabelaHash* tabela = criarTabelaHash(TAMANHO_TABELA_HASH);

        // Lê os dados do arquivo e insere na tabela hash
        FILE* arquivo = fopen("database.dat", "rb");
        if (!arquivo) {
            fprintf(stderr, "Erro ao abrir o arquivo de usuários.\n");
            return 1;
        }

        struct Usuario usuarioEncontrado;
        while (fread(&usuarioEncontrado, sizeof(struct Usuario), 1, arquivo)) {
            inserirNaTabela(tabela, usuarioEncontrado.login, usuarioEncontrado.senha);
        }

        fclose(arquivo);

        // Medindo o tempo de execução
        clock_t inicio = clock();

        if (buscarNaTabela(tabela, loginDigitado, senhaDigitada)) {
            printf("Bem-vindo, %s!\n", usuarioEncontrado.nome);
        } else {
            printf("Login ou senha incorretos.\n");
        }

        liberarTabelaHash(tabela);

        clock_t fim = clock();
        double tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo de execução: %f segundos.\n", tempoExecucao);

        return 0;
    }
}
