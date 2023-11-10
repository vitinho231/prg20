#include <stdio.h>
#include <stdlib.h>
#include "libprg2.h"

int main() {
    Pilha minhaPilha;
    cria_pilha(&minhaPilha, 5);

    empilhar(&minhaPilha, 10.5);
    empilhar(&minhaPilha, 20.3);
    empilhar(&minhaPilha, 5.7);

    printf("Pilha inicial:\n");
    imprime_pilha(&minhaPilha);

    printf("\nDesempilhando um item: %.2f\n", desempilhar(&minhaPilha));

    printf("\nPilha após desempilhar:\n");
    imprime_pilha(&minhaPilha);

    printf("\nTamanho da pilha: ");
    tamanho(&minhaPilha);

    printf("\nVerificando se a pilha está vazia:\n");
    vazia(&minhaPilha);

    free(minhaPilha.elementos);  // Libera a memória alocada para os itens da pilha

    return 0;
}
