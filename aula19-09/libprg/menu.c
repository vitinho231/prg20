#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libprg.h"

// Função para medir o tempo de execução
double medirTempo(void (*funcao)(), const char *nomeFuncao) {
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    funcao();
    fim = clock();

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s levou %.6f segundos.\n", nomeFuncao, tempo);

    return tempo;
}

int main() {
    struct Lista minhaLista;
    int tamanhoMax = 100; // Tamanho máximo da lista

    inicializaLista(&minhaLista, tamanhoMax);

    int opcao;
    int valor;
    int ordenada = 0; // 0 para não ordenada, 1 para ordenada

    do {
        printf("\nMENU:\n");
        printf("1. Criar uma lista povoada\n");
        printf("2. Inserir um novo número\n");
        printf("3. Remover um número\n");
        printf("4. Buscar por um número usando busca linear\n");
        printf("5. Buscar por um número usando busca binária iterativa\n");
        printf("6. Buscar por um número usando busca binária recursiva\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tamanho da lista: ");
                scanf("%d", &tamanhoMax);
                printf("A lista será ordenada? (0 - Não, 1 - Sim): ");
                scanf("%d", &ordenada);
                inicializaLista(&minhaLista, tamanhoMax);
                if (ordenada) {
                    // Implemente a lógica para criar uma lista ordenada aqui
                } else {
                    // Implemente a lógica para criar uma lista não ordenada aqui
                }
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                // Implemente a lógica para inserir um novo número aqui
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                // Implemente a lógica para remover um número aqui
                break;
            case 4:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                medirTempo(
                    // Implemente a função de busca linear aqui
                    ,
                    "Busca Linear"
                );
                break;
            case 5:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                medirTempo(
                    // Implemente a função de busca binária iterativa aqui
                    ,
                    "Busca Binária Iterativa"
                );
                break;
            case 6:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                medirTempo(
                    // Implemente a função de busca binária recursiva aqui
                    ,
                    "Busca Binária Recursiva"
                );
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Liberando a memória alocada
    free(minhaLista.elementos);

    return 0;
}

