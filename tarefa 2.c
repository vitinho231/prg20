#include <stdio.h>
#include <string.h>


struct User {
    char username[50];
    char password[50];
    char fullName[100];
};

int main() {
   
    FILE *file = fopen("database.dat", "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

   
    struct User users[500];
    for (int i = 0; i < 500; i++) {
        fscanf(file, "%s %s %[^\n]", users[i].username, users[i].password, users[i].fullName);
    }

    
    fclose(file);

    
    char inputUsername[50];
    char inputPassword[50];
    printf("Login: ");
    scanf("%s", inputUsername);
    printf("Senha: ");
    scanf("%s", inputPassword);

    for (int i = 0; i < 500; i++) {
        if (strcmp(inputUsername, users[i].username) == 0 && strcmp(inputPassword, users[i].password) == 0) {
            printf("Bem-vindo, %s!\n", users[i].fullName);
            return 0;
        }
    }

    printf("Credenciais inválidas.\n");
    return 0;
}
