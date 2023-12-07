#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix from a file
void readMatrixFromFile(char *filename, int dimension, int matrix[dimension][dimension]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
      int i ,j;
    for ( i = 0; i < dimension; i++) {
        for (j = 0; j < dimension; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
}

// Function to compute the maximum values for each 2x2 submatrix
void computeMaxValues(int dimension, int inputMatrix[dimension][dimension], int outputMatrix[dimension / 2][dimension / 2]) {
	  int i,j;
    for ( i = 0; i < dimension / 2; i++) {
        for ( j = 0; j < dimension / 2; j++) {
            int maxVal = inputMatrix[i * 2][j * 2];
            maxVal = (inputMatrix[i * 2][j * 2 + 1] > maxVal) ? inputMatrix[i * 2][j * 2 + 1] : maxVal;
            maxVal = (inputMatrix[i * 2 + 1][j * 2] > maxVal) ? inputMatrix[i * 2 + 1][j * 2] : maxVal;
            maxVal = (inputMatrix[i * 2 + 1][j * 2 + 1] > maxVal) ? inputMatrix[i * 2 + 1][j * 2 + 1] : maxVal;
            outputMatrix[i][j] = maxVal;
        }
    }
}

// Function to display a matrix
void displayMatrix(int dimension, int matrix[dimension][dimension]) {
	int i,j;
    for ( i = 0; i < dimension; i++) {
        for ( j = 0; j < dimension; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Define matrix dimensions
    int dimension;
    printf("Enter matrix dimension (2, 4, or 8): ");
    scanf("%d", &dimension);

    if (dimension != 2 && dimension != 4 && dimension != 8) {
        printf("Invalid matrix dimension. Please enter 2, 4, or 8.\n");
        return 1;
    }

    // Allocate memory for the input and output matrices
    int inputMatrix[dimension][dimension];
    int outputMatrix[dimension / 2][dimension / 2];

    // Read matrix from file
    readMatrixFromFile(filename, dimension, inputMatrix);

    // Compute maximum values for each 2x2 submatrix
    computeMaxValues(dimension, inputMatrix, outputMatrix);

    // Display original and resultant matrices
    printf("\nOriginal Matrix:\n");
    displayMatrix(dimension, inputMatrix);

    printf("\nResultant Matrix:\n");
    displayMatrix(dimension / 2, outputMatrix);

    return 0;
}

