#include <stdio.h>

int main() {
    int number, digit, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    // Ensure the number is non-negative
    if (number < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }

    while (number > 0) {
        // Get the last digit of the number
        digit = number % 10;
        // Add the digit to the sum
        sum += digit;
        // Remove the last digit from the number
        number /= 10;
    }

    printf("The sum of the digits is: %d\n", sum);

    return 0;
}

