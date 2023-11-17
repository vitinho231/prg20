#include <stdio.h>
#include <stdlib.h>
#include "libprg2.h"
#include <ctype.h>

int main() {
    Pilha pilha;
    cria_pilha(&pilha, 4);

    char entrada[10];
    float numero;

    printf("Calculadora RPN (Digite 'Q' para sair)\n");

    while (1) {
        imprime_pilha(&pilha);

        printf("Digite um número, operador (+, -, *, /), ou comando (t, v): ");
        scanf("%s", entrada);

        if (entrada[0] == 'Q' || entrada[0] == 'q') {
            break;
        }

        switch (entrada[0]) {
            case 't':
                tamanho(&pilha);
                break;

            case 'v':
                vazia(&pilha);
                break;

            default:
                if (isdigit(entrada[0]) || (entrada[0] == '-' && isdigit(entrada[1]))) {
                    numero = atof(entrada);
                    empilhar(&pilha, numero);
                } else {
                    float resultado, operand2, operand1;

                    switch (entrada[0]) {
                        case '+':
                            operand2 = desempilhar(&pilha);
                            operand1 = desempilhar(&pilha);
                            resultado = operand1 + operand2;
                            empilhar(&pilha, resultado);
                            break;

                        case '-':
                            operand2 = desempilhar(&pilha);
                            operand1 = desempilhar(&pilha);
                            resultado = operand1 - operand2;
                            empilhar(&pilha, resultado);
                            break;

                        case '*':
                            operand2 = desempilhar(&pilha);
                            operand1 = desempilhar(&pilha);
                            resultado = operand1 * operand2;
                            empilhar(&pilha, resultado);
                            break;

                        case '/':
                            operand2 = desempilhar(&pilha);
                            operand1 = desempilhar(&pilha);

                            if (operand2 != 0) {
                                resultado = operand1 / operand2;
                                empilhar(&pilha, resultado);
                            } else {
                                printf("Erro: Divisão por zero.\n");
                            }
                            break;

                        default:
                            printf("Comando ou operador inválido.\n");
                            break;
                    }
                }
                break;
        }
    }

    free(pilha.elementos);

    return 0;
}

