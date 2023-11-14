#include <stdio.h>

// Function to print an array of any type
void printArray(void *arr, size_t size, char type) {
    size_t i;

    switch (type) {
        case 'i': // int
            for (i = 0; i < size; i++) {
                printf("%d ", *((int*)arr + i));
            }
            break;

        case 'f': // float
            for (i = 0; i < size; i++) {
                printf("%.2f ", *((float*)arr + i));
            }
            break;

        case 'd': // double
            for (i = 0; i < size; i++) {
                printf("%.2lf ", *((double*)arr + i));
            }
            break;

        // Add more cases for other data types as needed

        default:
            printf("Unsupported data type\n");
    }

    printf("\n");
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double doubleArray[] = {1.11, 2.22, 3.33, 4.44, 5.55};

    // Printing intArray
    printf("Printing intArray: ");
    printArray(intArray, sizeof(intArray) / sizeof(int), 'i');

    // Printing floatArray
    printf("Printing floatArray: ");
    printArray(floatArray, sizeof(floatArray) / sizeof(float), 'f');

    // Printing doubleArray
    printf("Printing doubleArray: ");
    printArray(doubleArray, sizeof(doubleArray) / sizeof(double), 'd');

    return 0;
}

