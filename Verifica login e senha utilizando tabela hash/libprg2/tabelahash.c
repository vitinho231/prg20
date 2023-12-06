// libprg2/tabelahash.c

#include "tabelahash.h"
#include <stdlib.h>
#include <string.h>

int hash(const char* str, int tamanho) {
    int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % tamanho;
}

struct TabelaHash* criarTabelaHash(int tamanho) {
    struct TabelaHash* tabela = (struct TabelaHash*)malloc(sizeof(struct TabelaHash));
    tabela->elementos = (struct Nodo**)calloc(tamanho, sizeof(struct Nodo*));
    tabela->tamanho = tamanho;
    return tabela;
}

void inserirNaTabela(struct TabelaHash* tabela, const char* login, const char* senha) {
    int indice = hash(login, tabela->tamanho);

    struct Nodo* novoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    strncpy(novoNodo->login, login, MAX_LOGIN - 1);
    novoNodo->login[MAX_LOGIN - 1] = '\0';  // Garantindo que a string está terminada corretamente
    strncpy(novoNodo->senha, senha, MAX_SENHA - 1);
    novoNodo->senha[MAX_SENHA - 1] = '\0';  // Garantindo que a string está terminada corretamente
    novoNodo->proximo = tabela->elementos[indice];
    tabela->elementos[indice] = novoNodo;
}

int buscarNaTabela(const struct TabelaHash* tabela, const char* login, const char* senha) {
    int indice = hash(login, tabela->tamanho);

    struct Nodo* atual = tabela->elementos[indice];
    while (atual != NULL) {
        if (strcmp(login, atual->login) == 0 && strcmp(senha, atual->senha) == 0) {
            return 1;  // Encontrou
        }
        atual = atual->proximo;
    }

    return 0;  // Não encontrou
}

void liberarTabelaHash(struct TabelaHash* tabela) {
    for (int i = 0; i < tabela->tamanho; ++i) {
        struct Nodo* atual = tabela->elementos[i];
        while (atual != NULL) {
            struct Nodo* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }

    free(tabela->elementos);
    free(tabela);
}
