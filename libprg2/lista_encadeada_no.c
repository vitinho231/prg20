#include <stdio.h>
#include <stdlib.h>
#include "libprg2.h"


struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoInicio(struct No** cabeca, int valor) {
    struct No* novoNo = criarNo(valor);
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

void exibirLista(struct No* cabeca) {
    struct No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberarLista(struct No* cabeca) {
    struct No* atual = cabeca;
    struct No* proximoNo;
    while (atual != NULL) {
        proximoNo = atual->proximo;
        free(atual);
        atual = proximoNo;
    }
}
