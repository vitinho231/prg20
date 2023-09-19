#include <stdlib.h>
#include <stdio.h>
#include <libprg/libprg.h>

void cria_lista(Lista *lista, int tam_max) {
     lista->valores = malloc(sizeof (int) * tam_max);
     if (lista->valores == NULL) {
         printf("Falha na alocação de memoria\n");
         exit(1);
     }
     lista->tam_max = tam_max
}