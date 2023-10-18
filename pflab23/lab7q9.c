#include <stdio.h>

int main() {
    int N, S ,i;

    // Input the size of the array and the target sum S
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("The size of the array should be a positive integer.\n");
        return 1;
    }

    printf("Enter the target sum S: ");
    scanf("%d", &S);

    // Declare an array to store the elements
    int arr[N];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int left = 0; // Left pointer
    int right = 0; // Right pointer
    int currentSum = 0; // Current sum of the subarray
    int found = 0; // Flag to indicate if a subarray is found

    // Loop to find the subarray
    while (right <= N) {
        if (currentSum == S) {
            found = 1;
            break;
        }
        if (currentSum < S) {
            if (right < N) {
                currentSum += arr[right];
                right++;
            } else {
                break;
            }
        } else {
            currentSum -= arr[left];
            left++;
        }
    }

    // Print the result
    if (found) {
        printf("Subarray found with sum %d: ", S);
        for ( i = left; i < right; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No subarray found with sum %d.\n", S);
    }

    return 0;
}

