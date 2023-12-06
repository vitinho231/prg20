#include <stdlib.h>
#include <stdio.h>
#include "libprg2.h"

void cria_pilha(Pilha *pilha, int capacidade) {
    pilha->elementos = (float *)malloc(capacidade * sizeof(float));
    pilha->tamanho = 0;
    pilha->capacidade = capacidade;
}

void imprime_pilha(const Pilha *pilha) {
    printf("Pilha: ");
    for (int i = 0; i < pilha->tamanho; ++i) {
        printf("%.2f ", pilha->elementos[i]);
    }
    printf("\n");
}

void empilhar(Pilha *pilha, float valor) {
    if (pilha->tamanho < pilha->capacidade) {
        pilha->elementos[pilha->tamanho++] = valor;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

float desempilhar(Pilha *pilha) {
    if (pilha->tamanho > 0) {
        return pilha->elementos[--(pilha->tamanho)];
    } else {
        printf("Erro: Pilha vazia.\n");
        return 0.0; // Valor padrão, poderia ser tratado de maneira diferente conforme necessário
    }
}

void tamanho(const Pilha *pilha) {
    printf("Tamanho da pilha: %d\n", pilha->tamanho);
}

void vazia(const Pilha *pilha) {
    if (pilha->tamanho == 0) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }
}

