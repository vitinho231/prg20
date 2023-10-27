#include <stdio.h>
#include <stdlib.h>
#include "libprg2.h"

void inicializaLista(struct Lista* lista, int tamanhoMax) {
    lista->elementos = (int*)malloc(sizeof(int) * tamanhoMax);
    lista->tamanho = 0;
}

int insereElemento(struct Lista* lista, int valor) {
    const int TAMANHO_MAX = 0;
    if (lista->tamanho >= TAMANHO_MAX) {
        return 0; // Lista está cheia, não é possível inserir mais elementos
    }

    lista->elementos[lista->tamanho] = valor;
    lista->tamanho++;
    return 1; // Inserção bem-sucedida
}

int removeElemento(struct Lista* lista, int valor) {
    int encontrado = 0;
    int i;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        for (int j = i; j < lista->tamanho - 1; j++) {
            lista->elementos[j] = lista->elementos[j + 1];
        }
        lista->tamanho--;
        return 1; // Remoção bem-sucedida
    } else {
        return 0; // Valor não encontrado na lista
    }
}

void exibeLista(struct Lista* lista) {
    printf("Elementos da lista:\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

int buscaLinear(struct Lista* lista, int valor) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor) {
            return i; // Valor encontrado, retorna a posição
        }
    }
    return -1; // Valor não encontrado na lista
}

int buscaBinariaIterativa(struct Lista* lista, int valor) {
    int inicio = 0;
    int fim = lista->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (lista->elementos[meio] == valor) {
            return meio; // Valor encontrado, retorna a posição
        } else if (lista->elementos[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // Valor não encontrado na lista
}

int buscaBinariaRecursiva(struct Lista* lista, int valor, int inicio, int fim) {
    if (inicio > fim) {
        return -1; // Valor não encontrado na lista
    }

    int meio = (inicio + fim) / 2;

    if (lista->elementos[meio] == valor) {
        return meio; // Valor encontrado, retorna a posição
    } else if (lista->elementos[meio] < valor) {
        return buscaBinariaRecursiva(lista, valor, meio + 1, fim);
    } else {
        return buscaBinariaRecursiva(lista, valor, inicio, meio - 1);
    }
}
