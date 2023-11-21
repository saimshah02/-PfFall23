#include <stdio.h>

// Define a structure to store date information
struct Date {
    int day;
    int month;
    int year;
};

// Function to add days to a date
void addDays(struct Date *date, int days) {
    // Adjust the day, month, and year based on the number of days to add
    date->day += days;
    
    while (date->day > 30) {
        date->day -= 30;
        date->month += 1;
    }

    while (date->month > 12) {
        date->month -= 12;
        date->year += 1;
    }
}

int main() {
    // Get the current date (you can modify this part as needed)
    struct Date currentDate;
    printf("Enter the current date (day month year): ");
    scanf("%d %d %d", &currentDate.day, &currentDate.month, &currentDate.year);

    // Add 45 days to the current date
    addDays(&currentDate, 45);

    // Display the final date
    printf("\nThe final date after adding 45 days:\n");
    printf("Day: %d, Month: %d, Year: %d\n", currentDate.day, currentDate.month, currentDate.year);

    return 0;
}

