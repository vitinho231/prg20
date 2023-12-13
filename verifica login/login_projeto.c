#include <stdio.h>
#include "libprg2/listaencadeada.h"

int main() {
    // Abrir o arquivo de usuários em modo leitura binária
    FILE* arquivo = fopen("/home/vitor/CLionProjects/prg029003/verifica login/database.dat", "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de usuários"); // Mensagem de erro caso o arquivo não possa ser aberto
        return 1; // Sair do programa com código de erro
    }

    struct Nodo* listaOrdenada = NULL; // Inicializar lista encadeada
    struct Usuario usuario; // Estrutura para armazenar dados lidos do arquivo

    // Lendo os dados do arquivo e construindo a lista ordenada
    while (fread(&usuario, sizeof(struct Usuario), 1, arquivo)) {
        inserirOrdenado(&listaOrdenada, &usuario); // Inserir usuário na lista ordenada
    }

    fclose(arquivo); // Fechar o arquivo após a leitura

    // Imprimindo a lista ordenada
    printf("\nLista Ordenada:\n");
    imprimirLista(listaOrdenada);

    // Liberando a memória utilizada pela lista encadeada
    liberarLista(listaOrdenada);

    return 0; // Programa termina com sucesso
}
