#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    int tamanho = strlen(string) - 1; // Desconsiderar o caractere de nova linha
    char inversa[tamanho + 1];

    char *ptr = string + tamanho - 1;
    char *ptr_inversa = inversa;
    while (ptr >= string) {
        *ptr_inversa = *ptr;
        ptr--;
        ptr_inversa++;
    }
    *ptr_inversa = '\0';

    printf("A string invertida é: %s\n", inversa);

    return 0;
}
