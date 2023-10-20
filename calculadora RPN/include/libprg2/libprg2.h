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




#endif //PRG029003_LIBPRG2_H
