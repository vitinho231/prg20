#include "listaencadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializaLista(ListaEncadeada *lista) {
    lista->head = NULL;
}

void insereOrdenado(ListaEncadeada *lista, const char *username, const char *password) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Erro ao alocar memória para novo nó");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->username, username, sizeof(newNode->username) - 1);
    strncpy(newNode->password, password, sizeof(newNode->password) - 1);
    newNode->next = NULL;

    if (lista->head == NULL || strcmp(username, lista->head->username) < 0) {
        newNode->next = lista->head;
        lista->head = newNode;
        return;
    }

    struct Node *current = lista->head;
    while (current->next != NULL && strcmp(username, current->next->username) > 0) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void imprimeLista(const ListaEncadeada *lista) {
    int i = 1;
    struct Node *current = lista->head;
    while (current != NULL) {
        printf("Elemento %d = %s, senha %s\n", i, current->username, current->password);
        current = current->next;
        i++;
    }
}

int procuraUsuario(const ListaEncadeada *lista, const char *username, const char *password) {
    struct Node *current = lista->head;
    while (current != NULL) {
        if (strcmp(username, current->username) == 0 && strcmp(password, current->password) == 0) {
            return 1; // Usuário encontrado
        }
        current = current->next;
    }
    return 0; // Usuário não encontrado
}

const char *obtemNome(const ListaEncadeada *lista, const char *username) {
    struct Node *current = lista->head;
    while (current != NULL) {
        if (strcmp(username, current->username) == 0) {
            return current->fullName; // Retorna o nome do usuário
        }
        current = current->next;
    }
    return NULL; // Usuário não encontrado
}

void liberaLista(ListaEncadeada *lista) {
    struct Node *current = lista->head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    lista->head = NULL;
}
