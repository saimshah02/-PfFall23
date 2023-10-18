#include <stdio.h>

// Function to reverse the elements of an array from index 'start' to 'end'
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Function to left rotate an array by 'd' positions
void leftRotate(int arr[], int n, int d) {
    d = d % n;  // Ensure d is within the range of array length
    if (d < 0) {
        d += n;  // Handle negative rotation values
    }

    // Reverse the first 'd' elements
    reverse(arr, 0, d - 1);
    // Reverse the remaining elements
    reverse(arr, d, n - 1);
    // Reverse the entire array to get the final result
    reverse(arr, 0, n - 1);
}

int main() {
    int n, ,i d;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to left rotate: ");
    scanf("%d", &d);

    leftRotate(arr, n, d);

    printf("Array after left rotation by %d positions:\n", d);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

