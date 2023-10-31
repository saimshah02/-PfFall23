#include <stdio.h>
#include <stdlib.h>

// Structure to represent shirt details (age and price)
struct Shirt {
    int age;
    int price;
};

// Comparison function for sorting based on age in ascending order
int compareAgeAscending(const void *a, const void *b) {
    return ((struct Shirt *)a)->age - ((struct Shirt *)b)->age;
}

// Comparison function for sorting based on price in descending order
int comparePriceDescending(const void *a, const void *b) {
    return ((struct Shirt *)b)->price - ((struct Shirt *)a)->price;
}

int main() {
    // Create an array of shirt details (age and price)
    int i,j;
    struct Shirt shirts[] = {
        {25, 15},
        {30, 20},
        {25, 18},
        {20, 22},
        {30, 25},
        {35, 30},
        {25, 21}
    };

    int numShirts = sizeof(shirts) / sizeof(shirts[0]);

    // Sort the shirts based on age in ascending order
    qsort(shirts, numShirts, sizeof(struct Shirt), compareAgeAscending);

    // Display the sorted list based on age in ascending order
    printf("Sorted list in ascending order with respect to Age:\n");
    for ( i = 0; i < numShirts; i++) {
        printf("Age: %d, Price: %d\n", shirts[i].age, shirts[i].price);
    }

    // Sort the shirts based on price in descending order
    qsort(shirts, numShirts, sizeof(struct Shirt), comparePriceDescending);

    // Display the sorted list based on price in descending order
    printf("\nSorted list in descending order with respect to Price:\n");
    for ( i = 0; i < numShirts; i++) {
        printf("Age: %d, Price: %d\n", shirts[i].age, shirts[i].price);
    }

    return 0;
}

