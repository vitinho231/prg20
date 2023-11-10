#include "libprg2.h"
#include <stdio.h>
#include <stdlib.h>

// Implementações das funções

void cria_fila(Fila *fila, int capacidade) {
    fila->elementos = (int *)malloc(sizeof(int) * capacidade);
    fila->capacidade = capacidade;
    fila->inicio = fila->tamanho = 0;
}

void imprime_fila(const Fila *fila) {
    int i;
    for (i = 0; i < fila->tamanho; i++) {
        printf("%d ", fila->elementos[(fila->inicio + i) % fila->capacidade]);
    }
    printf("\n");
}

int enfileira(Fila *fila, int elemento) {
    if (fila->tamanho == fila->capacidade) {
        return -1; // Fila cheia
    }

    fila->elementos[(fila->inicio + fila->tamanho) % fila->capacidade] = elemento;
    fila->tamanho++;
    return 0; // Sucesso
}

int desenfileirar(Fila *fila) {
    if (fila->tamanho == 0) {
        return -1; // Fila vazia
    }

    int elemento = fila->elementos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return elemento;
}
