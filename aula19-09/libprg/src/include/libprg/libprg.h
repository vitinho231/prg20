// libprg.h

#ifndef LIBPRG_H
#define LIBPRG_H

struct Lista {
    int* elementos;
    int tamanho;
};

void inicializaLista(struct Lista* lista, int tamanhoMax);
int insereElemento(struct Lista* lista, int valor);
int removeElemento(struct Lista* lista, int valor);
void exibeLista(struct Lista* lista);
int buscaLinear(struct Lista* lista, int valor);
int buscaBinariaIterativa(struct Lista* lista, int valor);
int buscaBinariaRecursiva(struct Lista* lista, int valor, int inicio, int fim);

#endif

