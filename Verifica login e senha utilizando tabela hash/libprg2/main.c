#include <stdio.h>
#include "libprg2.h"

int main() {
    // Teste da lista linear
    Lista lista;
    inicializaLista(&lista, 5);

    insereElemento(&lista, 10);
    insereElemento(&lista, 20);
    insereElemento(&lista, 30);

    printf("Lista Linear: ");
    exibeLista(&lista);

    int busca = 20;
    int posicao = buscaLinear(&lista, busca);
    if (posicao != -1) {
        printf("Elemento %d encontrado na posição %d\n", busca, posicao);
    } else {
        printf("Elemento %d não encontrado na lista\n", busca);
    }

    // Teste da fila
    Fila fila;
    cria_fila(&fila, 3);

    enfileira(&fila, 5);
    enfileira(&fila, 10);
    enfileira(&fila, 15);

    printf("\nFila: ");
    imprime_fila(&fila);

    int elemento_desenfileirado = desenfileirar(&fila);
    printf("Elemento desenfileirado: %d\n", elemento_desenfileirado);

    // Teste da pilha
    Pilha pilha;
    cria_pilha(&pilha, 4);

    empilha(&pilha, 25);
    empilha(&pilha, 30);

    printf("\nPilha: ");
    imprime_pilha(&pilha);

    int elemento_desempilhado = desempilha(&pilha);
    printf("Elemento desempilhado: %d\n", elemento_desempilhado);

    return 0;
}
