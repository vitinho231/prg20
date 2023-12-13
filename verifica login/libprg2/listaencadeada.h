#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// Definição da estrutura Usuario que representa as informações do usuário
struct Usuario {
    char login[10];  // Campo para armazenar o login com no máximo 10 caracteres
    char senha[10];  // Campo para armazenar a senha com no máximo 10 caracteres
    char nome[30];   // Campo para armazenar o nome com no máximo 30 caracteres
};

// Definição da estrutura Nodo que representa um nó na lista encadeada
struct Nodo {
    struct Usuario usuario;  // Informações do usuário armazenadas no nó
    struct Nodo* proximo;    // Ponteiro para o próximo nó na lista
};

// Assinatura da função para inserir um usuário ordenadamente na lista
void inserirOrdenado(struct Nodo** lista, const struct Usuario* usuario);

// Assinatura da função para imprimir os elementos da lista
void imprimirLista(const struct Nodo* lista);

// Assinatura da função para liberar a memória ocupada pela lista encadeada
void liberarLista(struct Nodo* lista);

#endif // LISTA_ENCADEADA_H
