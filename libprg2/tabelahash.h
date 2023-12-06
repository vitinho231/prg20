
#ifndef TABELAHASH_H
#define TABELAHASH_H

#include "listaencadeada.h"

struct TabelaHash {
    struct Nodo** elementos;
    int tamanho;
};

struct TabelaHash* criarTabelaHash(int tamanho);
void inserirNaTabela(struct TabelaHash* tabela, const char* login, const char* senha);
int buscarNaTabela(const struct TabelaHash* tabela, const char* login, const char* senha);
void liberarTabelaHash(struct TabelaHash* tabela);

#endif // TABELAHASH_H
