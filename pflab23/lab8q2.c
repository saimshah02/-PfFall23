#include <stdio.h>

double calculate(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                printf("Division by zero is not allowed.\n");
                return 0.0; 
            }
        default:
            printf("Invalid operation.\n");
            return 0.0; 
    }
}

int main() {
    double num1, num2, result;
    char operation;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);  

    result = calculate(num1, num2, operation);

    printf("Result: %.2lf\n", result);

    return 0;
}

