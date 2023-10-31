#include <stdio.h>

// Function to process an array and calculate sum, maximum, and minimum values
void processArray(int arr[], int size, int *sum, int *max, int *min) {
    *sum = 0;
    *max = arr[0];
    *min = arr[0];
    int i;

    for ( i = 0; i < size; i++) {
        *sum += arr[i];

        if (arr[i] > *max) {
            *max = arr[i];
        }

        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter the array elements:\n");
    for ( i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum, max, min;

    // Call the processArray function to calculate sum, maximum, and minimum
    processArray(arr, size, &sum, &max, &min);

    
    printf("Sum: %d\n", sum);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

