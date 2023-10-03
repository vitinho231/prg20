#include <stdio.h>
#include <stdlib.h>
#include "libprg.h"

void cria_pilha(Pilha *pilha, int capacidade) {
    pilha->valores = (int *)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}


void imprime_pilha(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("A pilha está vazia. Nada para imprimir.\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = 0; i <= pilha->topo; i++) {
            printf("%d ", pilha->valores[i]);
        }
        printf("\n");
    }
}

void empilha(Pilha *pilha, int valor) {
    if (pilha->topo == pilha->capacidade - 1) {
        printf("Pilha cheia. Não é possível empilha.\n");
    } else {
        pilha->topo++;
        pilha->valores[pilha->topo] = valor;
        printf("Valor %d empilhado.\n", valor);
    }
}

void desempilhar(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("Pilha vazia. Não é possível desempilhar.\n");
    } else {
        printf("Valor %d desempilhado.\n", pilha->valores[pilha->topo]);
        pilha->topo--;
    }
}

void tamanho(Pilha *pilha) {
    printf("Tamanho da pilha: %d\n", pilha->topo + 1);
}

void vazia(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("A pilha está vazia.\n");
    } else {
        printf("A pilha não está vazia.\n");
    }
}

int main() {
    Pilha minhaPilha;

    cria_pilha(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);

    empilha(&minhaPilha, 10);
    empilha(&minhaPilha, 20);
    empilha(&minhaPilha, 30);

    tamanho(&minhaPilha);
    vazia(&minhaPilha);

    desempilhar(&minhaPilha);
    desempilhar(&minhaPilha);

    tamanho(&minhaPilha);
    vazia(&minhaPilha);

    return 0;
}
