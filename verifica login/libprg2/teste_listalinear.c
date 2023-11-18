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
}