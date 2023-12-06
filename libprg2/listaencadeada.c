#include "listaencadeada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inserirOrdenado(struct Nodo** lista, const char* login, const char* senha) {
    struct Nodo* novoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    strncpy(novoNodo->login, login, MAX_LOGIN - 1);
    novoNodo->login[MAX_LOGIN - 1] = '\0';  // Garantindo que a string está terminada corretamente
    strncpy(novoNodo->senha, senha, MAX_SENHA - 1);
    novoNodo->senha[MAX_SENHA - 1] = '\0';  // Garantindo que a string está terminada corretamente
    novoNodo->proximo = NULL;

    if (*lista == NULL || strcmp(login, (*lista)->login) < 0) {
        novoNodo->proximo = *lista;
        *lista = novoNodo;
    } else {
        struct Nodo* atual = *lista;
        while (atual->proximo != NULL && strcmp(login, atual->proximo->login) > 0) {
            atual = atual->proximo;
        }
        novoNodo->proximo = atual->proximo;
        atual->proximo = novoNodo;
    }
}

void imprimirLista(const struct Nodo* lista) {
    int i = 1;
    while (lista != NULL) {
        printf("Elemento %d = %s, senha %s\n", i++, lista->login, lista->senha);
        lista = lista->proximo;
    }
}
