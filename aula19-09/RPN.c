#include <stdio.h>
#include <libprg.h>
#include "libprg.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <equacao em RPN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *equacao_rpn = argv[1];

    // Inicializa a calculadora RPN
    struct rpn_calculator calc;
    rpn_init(&calc);

    // Avalia a equação RPN
    double resultado = rpn_eval(&calc, equacao_rpn);

    // Libera os recursos da calculadora RPN
    rpn_cleanup(&calc);

    // Exibe o resultado
    printf("Resultado: %lf\n", resultado);

    const int EXIT_SUCCESS;
    return EXIT_SUCCESS;
}
