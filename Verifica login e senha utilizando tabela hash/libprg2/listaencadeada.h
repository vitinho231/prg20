// libprg2/listaencadeada.h

#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

struct Nodo {
    char login[MAX_LOGIN];
    char senha[MAX_SENHA];
    struct Nodo* proximo;
};

void inserirOrdenado(struct Nodo** lista, const char* login, const char* senha);
void imprimirLista(const struct Nodo* lista);

#endif // LISTAENCADEADA_H
