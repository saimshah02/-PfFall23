#include <stdio.h>

int main() {
    int N, t ,i ,j;

    // Input the size of the array and the target integer
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    if (N <= 1) {
        printf("Array size should be greater than 1.\n");
        return 1;
    }

    int array[N];

    printf("Enter the elements of the array:\n");
    for ( i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the target integer: ");
    scanf("%d", &t);

    int found = 0;

    // Loop through the array to find pairs with the sum equal to t
    printf("Pairs: ");
    for ( i = 0; i < N; i++) {
        for ( j = i + 1; j < N; j++) {
            if (array[i] + array[j] == t) {
                printf("(%d, %d) ", array[i], array[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pairs found with the sum equal to %d.\n", t);
    } else {
        printf("\n");
    }

    return 0;
}

