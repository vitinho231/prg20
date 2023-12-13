#include "listaencadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inserir um usuário ordenadamente na lista encadeada
void inserirOrdenado(struct Nodo** lista, const struct Usuario* usuario) {
    // Aloca memória para um novo nó
    struct Nodo* novoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (!novoNodo) {
        // Verifica se a alocação de memória foi bem-sucedida
        fprintf(stderr, "Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);  // Encerra o programa com código de erro em caso de falha
    }

    novoNodo->usuario = *usuario;  // Copia as informações do usuário para o novo nó
    novoNodo->proximo = NULL;  // Inicializa o ponteiro para o próximo nó como nulo

    // Verifica se a lista está vazia ou se o novo usuário deve ser inserido no início
    if (*lista == NULL || strcmp(usuario->login, (*lista)->usuario.login) < 0) {
        novoNodo->proximo = *lista;  // O próximo do novo nó aponta para a lista existente
        *lista = novoNodo;  // A lista agora começa com o novo nó
    } else {
        // Caso contrário, percorre a lista para encontrar a posição correta para inserir o novo nó
        struct Nodo* atual = *lista;
        while (atual->proximo != NULL && strcmp(usuario->login, atual->proximo->usuario.login) > 0) {
            atual = atual->proximo;
        }
        novoNodo->proximo = atual->proximo;  // Atualiza o próximo do novo nó
        atual->proximo = novoNodo;  // Insere o novo nó na posição correta
    }
}

// Função para imprimir os elementos da lista
void imprimirLista(const struct Nodo* lista) {
    int i = 1;
    while (lista != NULL) {
        if (lista->usuario.login[0] != '\0') {
            // Imprime as informações do usuário se o login não estiver vazio
            printf("Elemento %d = Login: %s, Senha: %s, Nome: %s\n", i++, lista->usuario.login, lista->usuario.senha, lista->usuario.nome);
        } else {
            // Imprime uma mensagem indicando que o usuário está vazio se o login estiver vazio
            printf("Elemento %d = Usuário vazio, Senha: %s, Nome: %s\n", i++, lista->usuario.senha, lista->usuario.nome);
        }
        lista = lista->proximo;  // Move para o próximo nó na lista
    }
}

// Função para liberar a memória ocupada pela lista encadeada
void liberarLista(struct Nodo* lista) {
    while (lista != NULL) {
        struct Nodo* proximo = lista->proximo;  // Armazena o próximo nó antes de liberar a memória do nó atual
        free(lista);  // Libera a memória ocupada pelo nó atual
        lista = proximo;  // Move para o próximo nó na lista
    }
}
