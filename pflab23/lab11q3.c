#include <stdio.h>

// Define a structure to store date information
struct Date {
    int day;
    int month;
    int year;
};

// Function to compare two dates
int compareDates(struct Date date1, struct Date date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
        return 0; // Dates are equal
    } else {
        return 1; // Dates are not equal
    }
}

int main() {
    struct Date date1, date2;

    // Input for the first date
    printf("Enter the first date (day month year): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    // Input for the second date
    printf("Enter the second date (day month year): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    // Compare the dates
    if (compareDates(date1, date2) == 0) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }

    return 0;
}

