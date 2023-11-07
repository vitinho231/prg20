//
// Created by aluno on 20/10/23.
//

#ifndef PRG029003_LIBPRG2_H
#define PRG029003_LIBPRG2_H

typedef struct {
    float *elementos;
    int tamanho;
    int capacidade;
} Pilha;


void cria_pilha(Pilha *pilha, int capacidade);
void imprime_pilha(const Pilha *pilha);
void empilhar(Pilha *pilha, float valor);
float desempilhar(Pilha *pilha);
void tamanho(const Pilha *pilha);
void vazia(const Pilha *pilha);

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




#endif //PRG029003_LIBPRG2_H
