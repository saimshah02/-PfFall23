#include <stdio.h>
#include <string.h>
int main() {
    char password[100];  
    char storedPassword[] = "Secure123";

    printf("Enter your password: ");
    scanf("%s", password);

    if (strlen(password) < 8) {
        printf("Password is too short. It must be at least 8 characters long.\n");
    } else {

        if (strcmp(password, storedPassword) == 0) {
            printf("Login successful. Welcome!\n");
        } else {
            printf("Login failed. Incorrect password.\n");
        }
    }

    return 0;
}

