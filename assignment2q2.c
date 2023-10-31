#include <stdio.h>

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int main() {
    int rows, cols ,i ,j;

    // Input the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    // Input the binary matrix
    printf("Enter the elements of the binary matrix (0s and 1s):\n");
    for (i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSide = 0;  // The side length of the largest square submatrix
    int maxRow = 0;   // The row of the top-left corner of the largest square submatrix
    int maxCol = 0;   // The column of the top-left corner of the largest square submatrix

    // Create a 2D array to store the size of the largest square submatrix ending at each position
    int maxSize[rows][cols];

    for (i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            if (i == 0 || j == 0) {
                maxSize[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                maxSize[i][j] = 1 + min(maxSize[i - 1][j], maxSize[i][j - 1], maxSize[i - 1][j - 1]);
            } else {
                maxSize[i][j] = 0;
            }

            // Update the maximum side length and position if a larger square submatrix is found
            if (maxSize[i][j] > maxSide) {
                maxSide = maxSize[i][j];
                maxRow = i - maxSide + 1;
                maxCol = j - maxSide + 1;
            }
        }
    }

    // Display the largest square submatrix
    printf("The largest square submatrix of 1s is:\n");
    for (i = maxRow; i < maxRow + maxSide; i++) {
        for ( j = maxCol; j < maxCol + maxSide; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Display the dimensions of the largest square submatrix
    printf("Dimensions: %d rows x %d columns\n", maxSide, maxSide);

    return 0;
}

