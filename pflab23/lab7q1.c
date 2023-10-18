#include <stdio.h>

int main() {
    double num1, num2;
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    if (num2 == 0) {
        printf("Division by zero is not allowed.\n");
    } else {
        double result = 0;

        // Check if num1 and num2 have different signs
        int isNegative = 0;
        if ((num1 < 0 && num2 > 0) || (num1 > 0 && num2 < 0)) {
            isNegative = 1;
        }

        num1 = (num1 < 0) ? -num1 : num1;
        num2 = (num2 < 0) ? -num2 : num2;

        // Subtract num2 from num1 repeatedly until num1 is smaller than num2
        while (num1 >= num2) {
            num1 -= num2;
            result++;
        }

        // If the numbers had different signs, result should be negative
        if (isNegative) {
            result = -result;
        }

        printf("Division result: %.2lf\n", result);
    }

    return 0;
}

