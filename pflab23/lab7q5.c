#include <stdio.h>

int main() {
    int N ,i ,j;

    // Input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("The number of elements should be a positive integer.\n");
        return 1;
    }

    // Declare an array to store the elements
    int arr[N];

    // Input the elements
    printf("Enter the elements of the array:\n");
    for ( i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize an array to store the frequency of each element
    int frequency[N];

    for ( i = 0; i < N; i++) {
        frequency[i] = -1; // Initialize frequency array with -1
    }

    // Count the frequency of each element
    for ( i = 0; i < N; i++) {
        int count = 1;

        for ( j = i + 1; j < N; j++) {
            if (arr[i] == arr[j]) {
                count++;
                frequency[j] = 0; // Mark the element as counted
            }
        }

        if (frequency[i] != 0) {
            frequency[i] = count;
        }
    }

    // Output the frequency of each element
    printf("Frequency of elements in the array:\n");
    for ( i = 0; i < N; i++) {
        if (frequency[i] != 0) {
            printf("%d occurs %d time(s)\n", arr[i], frequency[i]);
        }
    }

    return 0;
}

