#include <stdio.h>
#include "libprg2.h"

int main() {
    struct No* cabeca = NULL;

    // Inserir elementos na lista
    inserirNoInicio(&cabeca, 3);
    inserirNoInicio(&cabeca, 7);
    inserirNoInicio(&cabeca, 1);

    // Exibir a lista
    printf("Lista: ");
    exibirLista(cabeca);

    // Liberar memória
    liberarLista(cabeca);

    return 0;
}
