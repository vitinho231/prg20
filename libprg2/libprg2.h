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

// Protótipos das funções
void inicializaLista(Lista *lista, int tamanhoMax);
int insereElemento(Lista *lista, int valor);
int removeElemento(Lista *lista, int valor);
void exibeLista(const Lista *lista);
int buscaLinear(const Lista *lista, int valor);
int buscaBinariaIterativa(const Lista *lista, int valor);
int buscaBinariaRecursiva(const Lista *lista, int valor, int inicio, int fim);

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} ListaCircular;

void inicializaListaCircular(ListaCircular *lista);
void insereElementoCircular(ListaCircular *lista, int valor);
void removeElementoCircular(ListaCircular *lista, int valor);
void exibeListaCircular(ListaCircular *lista);

typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

typedef struct {
    DNode *head;
} ListaDuplaCircular;

void inicializaListaDuplaCircular(ListaDuplaCircular *lista);
void insereElementoDuplaCircular(ListaDuplaCircular *lista, int valor);
void removeElementoDuplaCircular(ListaDuplaCircular *lista, int valor);
void exibeListaDuplaCircular(ListaDuplaCircular *lista);

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} FilaLista;

void criaFilaLista(FilaLista *fila);
void enfileirarLista(FilaLista *fila, int valor);
int desenfileirarLista(FilaLista *fila);
void imprimeFilaLista(const FilaLista *fila);

typedef struct SNode {
    int data;
    struct SNode *next;
} SNode;

typedef struct {
    SNode *top;
} PilhaLista;

void criaPilhaLista(PilhaLista *pilha);
void empilharLista(PilhaLista *pilha, int valor);
int desempilharLista(PilhaLista *pilha);
void imprimePilhaLista(const PilhaLista *pilha);

#endif // PRG029003_LIBPRG2_H
