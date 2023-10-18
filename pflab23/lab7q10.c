#include <stdio.h>

int main() {
    int n ,i ,j ,x ,y;

    // Input the size of the grid
    printf("Enter the size of the n x n grid: ");
    scanf("%d", &n);

    if (n <= 2) {
        printf("The grid size should be at least 3x3.\n");
        return 1;
    }

    // Declare and initialize the grid
    int grid[n][n];

    // Input the elements of the grid
    printf("Enter the elements of the %d x %d grid:\n", n, n);
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Declare and initialize the maxLocal matrix
    int maxLocal[n - 2][n - 2];

    // Calculate the maxLocal matrix
    for ( i = 1; i < n - 1; i++) {
        for ( j = 1; j < n - 1; j++) {
            int maxVal = grid[i - 1][j - 1];
            for ( x = -1; x <= 1; x++) {
                for ( y = -1; y <= 1; y++) {
                    if (grid[i + x][j + y] > maxVal) {
                        maxVal = grid[i + x][j + y];
                    }
                }
            }
            maxLocal[i - 1][j - 1] = maxVal;
        }
    }

    // Print the maxLocal matrix
    printf("maxLocal matrix:\n");
    for ( i = 0; i < n - 2; i++) {
        for ( j = 0; j < n - 2; j++) {
            printf("%d ", maxLocal[i][j]);
        }
        printf("\n");
    }

    return 0;
}

