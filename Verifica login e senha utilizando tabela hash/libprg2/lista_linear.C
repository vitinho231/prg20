#include "libprg2.h"
#include <stdio.h>
#include <stdlib.h>

// Implementações das funções

void inicializaLista(Lista *lista, int tamanhoMax) {
    lista->elementos = (int *)malloc(sizeof(int) * tamanhoMax);
    lista->tamanho = 0;
}

int insereElemento(Lista *lista, int valor) {
    if (lista->tamanho >= TAMANHO_MAX) {
        return -1; // Lista cheia
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return 0; // Sucesso
}

int removeElemento(Lista *lista, int valor) {
    int i;
    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            break;
        }
    }

    if (i == lista->tamanho) {
        return -1; // Elemento não encontrado
    }

    for (int j = i; j < lista->tamanho - 1; j++) {
        lista->elementos[j] = lista->elementos[j + 1];
    }

    lista->tamanho--;
    return 0; // Sucesso
}

void exibeLista(const Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int buscaLinear(const Lista *lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            return i; // Índice do elemento encontrado
        }
    }

    return -1; // Elemento não encontrado
}

int buscaBinariaIterativa(const Lista *lista, int valor) {
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor) {
            return meio; // Elemento encontrado
        } else if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Elemento não encontrado
}

int buscaBinariaRecursiva(const Lista *lista, int valor, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (lista->elementos[meio] == valor) {
        return meio; // Elemento encontrado
    } else if (lista->elementos[meio] < valor) {
        return buscaBinariaRecursiva(lista, valor, meio + 1, fim);
    } else {
        return buscaBinariaRecursiva(lista, valor, inicio, meio - 1);
    }
}
