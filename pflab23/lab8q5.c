#include <stdio.h>

int decideCarUsage(int carNumber, int dayOfWeek) {
    // Check if the car is even-numbered and the day is even, or if the car is odd-numbered and the day is odd.
    if ((carNumber % 2 == 0 && dayOfWeek % 2 == 0) || (carNumber % 2 != 0 && dayOfWeek % 2 != 0)) {
        return 1; // Car should be used
    } else {
        return 0; // Car should not be used
    }
}

int main() {
    int carNumber, dayOfWeek;

    // Input car number and day of the week
    printf("Enter the numeric part of your car's number: ");
    scanf("%d", &carNumber);

    printf("Enter the day of the week (1 to 7): ");
    scanf("%d", &dayOfWeek);

    // Call the decideCarUsage function and display the result
    if (decideCarUsage(carNumber, dayOfWeek)) {
        printf("You should use your car today.\n");
    } else {
        printf("You should not use your car today.\n");
    }

    return 0;
}

