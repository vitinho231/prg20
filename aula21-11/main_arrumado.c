#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa != NULL) {
        free(pessoa->cpf);
        free(pessoa->nome);
        free(pessoa->email);
        free(pessoa);
    }
}

void destruir_lista_encadeada(no_t *lista) {
    while (lista != NULL) {
        no_t *prox = lista->prox;
        destruir_pessoa(lista->valor);
        free(lista->chave);
        free(lista);
        lista = prox;
    }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            destruir_lista_encadeada(d->vetor[i]);
        }
        free(d->vetor);
        free(d);
    }
}

int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

bool inserir(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *novo_no = malloc(sizeof(no_t));
    if (novo_no == NULL) {
        return false;
    }

    novo_no->chave = strdup(chave);
    if (novo_no->chave == NULL) {
        free(novo_no);
        return false;
    }

    novo_no->valor = valor;
    novo_no->prox = d->vetor[indice];
    d->vetor[indice] = novo_no;

    return true;
}

bool remover(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    no_t *atual = d->vetor[indice];
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior != NULL) {
                anterior->prox = atual->prox;
            } else {
                d->vetor[indice] = atual->prox;
            }
            destruir_no(atual);
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }

    return false;
}

void exibir_dicionario(dicionario_t *d) {
    for (int i = 0; i < d->tamanho; ++i) {
        printf("%d: [", i);
        no_t *lista = d->vetor[i];
        while (lista != NULL) {
            printf("(%s, %s, %s)", lista->chave, lista->valor->nome, lista->valor->email);
            if (lista->prox != NULL) {
                printf(", ");
            }
            lista = lista->prox;
        }
        printf("]\n");
    }
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar(d, chave);
    if (p != NULL) {
        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf, p->nome, p->email);
    } else {
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}

int main(int argc, char **argv) {
    dicionario_t *dicionario = criar_dicionario(5);
    if (dicionario == NULL) {
        printf("Não foi possível reservar memória\n");
        exit(EXIT_FAILURE);
    }

    pessoa_t *p1 = malloc(sizeof(pessoa_t));
    p1->cpf = strdup("123");
    p1->nome = strdup("Juca");
    p1->email = strdup("juca@example.ogr");
    inserir(dicionario, p1->cpf, p1);

    pessoa_t *p2 = malloc(sizeof(pessoa_t));
    p2->cpf = strdup("456");
    p2->nome = strdup("Ana");
    p2->email = strdup("ana@example.org");
    inserir(dicionario, p2->cpf, p2);

    pessoa_t *p3 = malloc(sizeof(pessoa_t));
    p3->cpf = strdup("789");
    p3->nome = strdup("Pedro");
    p3->email = strdup("pedro@example.org");
    inserir(dicionario, p3->cpf, p3);

    // Exibir informações armazenadas no dicionário
    exibir_dicionario(dicionario);

    // Remover elemento do dicionário
    remover(dicionario, "456");

    // Exibir informações atualizadas do dicionário
    exibir_dicionario(dicionario);

    destruir_dicionario(dicionario);

    return 0;
}

char *copia_string(char *s) {
    char *copia = malloc(sizeof(char) * (strlen(s) + 1));
    if (copia == NULL) {
        return NULL;
    }
    strcpy(copia, s);
    return copia;
}
