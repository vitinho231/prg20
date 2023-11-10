#include "libprg2.h"
#include <stdio.h>
#include <stdlib.h>



// Circular Linked List
void inicializaListaCircular(ListaCircular *lista) {
    lista->head = NULL;
}

void insereElementoCircular(ListaCircular *lista, int valor) {
    // Implementação para inserir um elemento em uma lista circular encadeada
    Node *novoNo = (Node *)malloc(sizeof(Node));
    novoNo->data = valor;
    novoNo->next = NULL;

    if (lista->head == NULL) {
        lista->head = novoNo;
        novoNo->next = lista->head; // Para torná-la circular
    } else {
        Node *temp = lista->head;
        while (temp->next != lista->head) {
            temp = temp->next;
        }
        temp->next = novoNo;
        novoNo->next = lista->head;
    }
}

void removeElementoCircular(ListaCircular *lista, int valor) {
    // Implementação para remover um elemento de uma lista circular encadeada
    if (lista->head == NULL) {
        printf("A lista circular está vazia\n");
        return;
    }

    Node *atual = lista->head;
    Node *anterior = NULL;

    // Encontrar o nó a ser removido
    while (atual->data != valor) {
        if (atual->next == lista->head) {
            printf("Elemento %d não encontrado na lista circular\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->next;
    }

    // Remover o nó
    if (atual == lista->head) {
        if (atual->next == lista->head) {
            free(atual);
            lista->head = NULL;
        } else {
            Node *ultimo = lista->head;
            while (ultimo->next != lista->head) {
                ultimo = ultimo->next;
            }
            ultimo->next = lista->head->next;
            lista->head = lista->head->next;
            free(atual);
        }
    } else {
        anterior->next = atual->next;
        free(atual);
    }
}

void exibeListaCircular(ListaCircular *lista) {
    // Implementação para exibir os elementos de uma lista circular encadeada
    if (lista->head == NULL) {
        printf("A lista circular está vazia\n");
        return;
    }

    Node *temp = lista->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != lista->head);
    printf("\n");
}

// Doubly Circular Linked List
void inicializaListaDuplaCircular(ListaDuplaCircular *lista) {
    lista->head = NULL;
}

void insereElementoDuplaCircular(ListaDuplaCircular *lista, int valor) {
    // Implementação para inserir um elemento em uma lista circular duplamente encadeada
    DNode *novoNo = (DNode *)malloc(sizeof(DNode));
    novoNo->data = valor;
    novoNo->prev = NULL;
    novoNo->next = NULL;

    if (lista->head == NULL) {
        lista->head = novoNo;
        novoNo->next = lista->head;
        novoNo->prev = lista->head;
    } else {
        DNode *ultimo = lista->head->prev;
        novoNo->next = lista->head;
        novoNo->prev = ultimo;
        ultimo->next = novoNo;
        lista->head->prev = novoNo;
    }
}

void removeElementoDuplaCircular(ListaDuplaCircular *lista, int valor) {
    // Implementação para remover um elemento de uma lista circular duplamente encadeada
    if (lista->head == NULL) {
        printf("A lista circular duplamente encadeada está vazia\n");
        return;
    }

    DNode *atual = lista->head;
    DNode *anterior = NULL;

    // Encontrar o nó a ser removido
    while (atual->data != valor) {
        if (atual->next == lista->head) {
            printf("Elemento %d não encontrado na lista circular duplamente encadeada\n", valor);
            return;
        }
        anterior = atual;
        atual = atual->next;
    }

    // Remover o nó
    if (atual == lista->head) {
        if (atual->next == lista->head) {
            free(atual);
            lista->head = NULL;
        } else {
            DNode *ultimo = lista->head->prev;
            lista->head = lista->head->next;
            lista->head->prev = ultimo;
            ultimo->next = lista->head;
            free(atual);
        }
    } else {
        anterior->next = atual->next;
        atual->next->prev = anterior;
        free(atual);
    }
}

void exibeListaDuplaCircular(ListaDuplaCircular *lista) {
    // Implementação para exibir os elementos de uma lista circular duplamente encadeada
    if (lista->head == NULL) {
        printf("A lista circular duplamente encadeada está vazia\n");
        return;
    }

    DNode *temp = lista->head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != lista->head);
    printf("\n");
}

// Linked List-based Queue
void criaFilaLista(FilaLista *fila) {
    fila->front = fila->rear = NULL;
}

void enfileirarLista(FilaLista *fila, int valor) {
    // Implementação para enfileirar um elemento em uma fila encadeada
    QNode *novoNo = (QNode *)malloc(sizeof(QNode));
    novoNo->data = valor;
    novoNo->next = NULL;

    if (fila->rear == NULL) {
        fila->front = fila->rear = novoNo;
    } else {
        fila->rear->next = novoNo;
        fila->rear = novoNo;
    }
}

int desenfileirarLista(FilaLista *fila) {
    // Implementação para desenfileirar um elemento de uma fila encadeada
    if (fila->front == NULL) {
        printf("A fila está vazia\n");
        return -1; // Código de erro para fila vazia
    }

    QNode *temp = fila->front;
    int valor = temp->data;
    fila->front = fila->front->next;

    if (fila->front == NULL) {
        fila->rear = NULL;
    }

    free(temp);
    return valor;
}

void imprimeFilaLista(const FilaLista *fila) {
    // Implementação para imprimir os elementos de uma fila encadeada
    if (fila->front == NULL) {
        printf("A fila está vazia\n");
        return;
    }

    QNode *temp = fila->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Linked List-based Stack
void criaPilhaLista(PilhaLista *pilha) {
    pilha->top = NULL;
}

void empilharLista(PilhaLista *pilha, int valor) {
    // Implementação para empilhar um elemento em uma pilha encadeada
    SNode *novoNo = (SNode *)malloc(sizeof(SNode));
    novoNo->data = valor;
    novoNo->next = pilha->top;
    pilha->top = novoNo;
}

int desempilharLista(PilhaLista *pilha) {
    // Implementação para desempilhar um elemento de uma pilha encadeada
    if (pilha->top == NULL) {
        printf("A pilha está vazia\n");
        return -1; // Código de erro para pilha vazia
    }

    SNode *temp = pilha->top;
    int valor = temp->data;
    pilha->top = pilha->top->next;
    free(temp);
    return valor;
}

void imprimePilhaLista(const PilhaLista *pilha) {
    // Implementação para imprimir os elementos de uma pilha encadeada
    if (pilha->top == NULL) {
        printf("A pilha está vazia\n");
        return;
    }

    SNode *temp = pilha->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
