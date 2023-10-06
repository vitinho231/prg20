// libprg.h

#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct {
    int* elementos;
    int tamanho;
} Lista;

void inicializaLista(struct Lista* lista, int tamanhoMax);
int insereElemento(struct Lista* lista, int valor);
int removeElemento(struct Lista* lista, int valor);
void exibeLista(struct Lista* lista);
int buscaLinear(struct Lista* lista, int valor);
int buscaBinariaIterativa(struct Lista* lista, int valor);
int buscaBinariaRecursiva(struct Lista* lista, int valor, int inicio, int fim);

typedef struct {
    int *valores;
    int inicio;
    int fim;
    int capacidade;
}Fila;

void cria_fila(Fila *fila, int capacidade);
void imprime_fila(Fila *fila);
int enfileirar(Fila *fila); //retorna código de erro.
int desenfileirar(Fila *fila); //retorna código de erro.


typedef struct {
    int *valores;
    int topo;
    int capacidade;
}Pilha;

void cria_pilha(Pilha *pilha, int capacidade);
void imprime_pilha(Pilha *pilha);
void empilhar(Pilha *pilha);
void desempilhar(Pilha *pilha);
void tamanho(Pilha *pilha);
void vazia(Pilha *pilha);

#endif

