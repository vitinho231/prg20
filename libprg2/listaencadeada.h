#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

struct Node {
    char username[50];
    char password[50];
    char fullName[100];
    struct Node *next;
};

typedef struct {
    struct Node *head;
} ListaEncadeada;

void inicializaLista(ListaEncadeada *lista);
void insereOrdenado(ListaEncadeada *lista, const char *username, const char *password);
void imprimeLista(const ListaEncadeada *lista);
int procuraUsuario(const ListaEncadeada *lista, const char *username, const char *password);
const char *obtemNome(const ListaEncadeada *lista, const char *username);
void liberaLista(ListaEncadeada *lista);

#endif
