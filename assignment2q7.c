#include <stdio.h>

// Function to calculate the persistence of a number
int calculatePersistence(int n) {
    int persistence = 0;

    while (n >= 10) {
        int product = 1;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            n /= 10;
        }
        n = product;
        persistence++;
    }

    return persistence;
}

int main() {
    int number;

    printf("Enter a positive integer (Ctrl-D or Ctrl-Z to exit): ");
    
    while (scanf("%d", &number) != EOF) {
        if (number <= 0) {
            printf("Please enter a positive integer.\n");
        } else {
            int persistence = calculatePersistence(number);
            printf("Persistence of %d is %d\n", number, persistence);
        }

        // Clear the input buffer
        while (getchar() != '\n');
        
        printf("Enter another positive integer (Ctrl-D or Ctrl-Z to exit): ");
    }

    printf("Goodbye!\n");

    return 0;
}

