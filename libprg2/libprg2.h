#ifndef PRG029003_LIBPRG2_H
#define PRG029003_LIBPRG2_H

#define TAMANHO_MAX 100 // Ou o valor desejado
typedef struct {
    int *elementos;
    int capacidade;
    int inicio;
    int tamanho;
} Fila;

void cria_fila(Fila *fila, int capacidade);
void imprime_fila(const Fila *fila);
int enfileira(Fila *fila, int elemento);
int desenfileirar(Fila *fila);


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
    int *elementos;
    int tamanho;
} Lista;

void inicializaLista(Lista *lista, int tamanhoMax);
int insereElemento(Lista *lista, int valor);
int removeElemento(Lista *lista, int valor);
void exibeLista(const Lista *lista);
int buscaLinear(const Lista *lista, int valor);
int buscaBinariaIterativa(const Lista *lista, int valor);
int buscaBinariaRecursiva(const Lista *lista, int valor, int inicio, int fim);


ttypedef struct No {
    int dado;
    struct No* proximo;
} No;

No* criarNo(int valor);
void inserirNoInicio(No** cabeca, int valor);
void exibirLista(No* cabeca);
void liberarLista(No* cabeca);

struct Node {
    char username[50];
    char password[50];
    char fullName[100];
    struct Node *next;
};


#endif // PRG029003_LIBPRG2_H
