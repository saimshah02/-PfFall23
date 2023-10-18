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
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble sort to sort the array in ascending order
    for ( i = 0; i < N - 1; i++) {
        for ( j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for ( i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

