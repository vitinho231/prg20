#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no
    *esquerda;
    struct no
    *direita;
} no_t;
no_t
*criar_no(int valor){
    no_t
    *no = (no_t
    *) malloc(sizeof(no_t));
    no
    ->valor = valor;
    no
    ->esquerda = no
    ->direita = NULL;
    return no;
}
void destruir_no(no_t
*no) {
if (no != NULL) {
destruir_no(no
->esquerda);
destruir_no(no
->direita);
free(no);
}
}
// todo nó é raiz de uma subárvore
no_t *inserir_valor(no_t *raiz, int valor){
if (raiz == NULL) {
return criar_no(valor);
} else if (valor < raiz->valor) {
raiz->esquerda = inserir_valor(raiz->esquerda, valor);
} else if (valor > raiz->valor) {
raiz->direita = inserir_valor(raiz->direita, valor);
}
return raiz;
}
bool busca(no_t *raiz, int valor){
if (raiz == NULL) return false;
if (valor == raiz->valor) return true;
if (valor < raiz->valor) return busca(raiz->esquerda, valor);
return busca(raiz->direita, valor);
}
