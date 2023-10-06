#include <stdio.h>
#include <stdlib.h>
#include "libprg.h"

void cria_fila(Fila *fila, int capacidade) {
    fila->valores = (int *)malloc(capacidade * sizeof(int));
    fila->inicio = fila->fim = -1;
    fila->capacidade = capacidade;
}

void imprime_fila(Fila *fila) {
    if (fila->inicio == -1) {
        printf("Fila vazia.\n");
        return;
    }

    for (int i = fila->inicio; i <= fila->fim; i++)
        printf("%d ", fila->valores[i]);
    printf("\n");
}

int enfileira(Fila *fila, int elemento) {
    if (fila->fim == fila->capacidade - 1)
        return -1; // Código de erro: fila cheia

    if (fila->inicio == -1)
        fila->inicio = 0;

    fila->valores[++fila->fim] = elemento;
    return 0; // Operação bem-sucedida
}

int desenfileirar(Fila *fila) {
    if (fila->inicio == -1)
        return -1; // Código de erro: fila vazia

    int removido = fila->valores[fila->inicio++];

    if (fila->inicio > fila->fim)
        fila->inicio = fila->fim = -1; // Resetar a fila

    return removido;
}
