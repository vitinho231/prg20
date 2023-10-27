#include <stdio.h>
#include <stdlib.h>
#include "libprg2.h"

int main() {
    // Testando funções para Lista
    struct Lista lista_lisnear;
    int tamanhoMax = 10;
    inicializaLista(&lista, tamanhoMax);

    insereElemento(&lista, 5);
    insereElemento(&lista, 10);
    insereElemento(&lista, 15);

    exibeLista(&lista);

    removeElemento(&lista, 10);

    exibeLista(&lista);

    int buscaLinearResultado = buscaLinear(&lista, 15);
    printf("Resultado da busca linear: %d\n", buscaLinearResultado);

    int buscaBinariaIterativaResultado = buscaBinariaIterativa(&lista, 15);
    printf("Resultado da busca binária iterativa: %d\n", buscaBinariaIterativaResultado);

    int buscaBinariaRecursivaResultado = buscaBinariaRecursiva(&lista, 15, 0, lista.tamanho - 1);
    printf("Resultado da busca binária recursiva: %d\n", buscaBinariaRecursivaResultado);

    // Testando funções para Fila
    Fila fila;
    cria_fila(&fila, 5);

    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);

    printf("Fila após enfileirar: ");
    imprime_fila(&fila);

    desenfileirar(&fila);

    printf("Fila após desenfileirar: ");
    imprime_fila(&fila);

    // Testando funções para Pilha
    Pilha pilha;
    cria_pilha(&pilha, 5);

    empilhar(&pilha);
    empilhar(&pilha);
    empilhar(&pilha);

    printf("Pilha após empilhar: ");
    imprime_pilha(&pilha);

    desempilhar(&pilha);

    printf("Pilha após desempilhar: ");
    imprime_pilha(&pilha);

    tamanho(&pilha);

    vazia(&pilha);

    return 0;
}