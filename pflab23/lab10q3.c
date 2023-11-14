#include <stdio.h>

// Function to swap the values of two variables using pointers
void swap(void *a, void *b, size_t size) {
    unsigned char *byteA = (unsigned char *)a;
    unsigned char *byteB = (unsigned char *)b;

    while (size--) {
        *byteA ^= *byteB;
        *byteB ^= *byteA;
        *byteA ^= *byteB;

        byteA++;
        byteB++;
    }
}

int main() {
    int intVar1 = 5, intVar2 = 10;
    float floatVar1 = 3.14, floatVar2 = 6.28;

    // Swap integers
    printf("Before swapping integers: %d, %d\n", intVar1, intVar2);
    swap(&intVar1, &intVar2, sizeof(int));
    printf("After swapping integers: %d, %d\n", intVar1, intVar2);

    // Swap floats
    printf("Before swapping floats: %.2f, %.2f\n", floatVar1, floatVar2);
    swap(&floatVar1, &floatVar2, sizeof(float));
    printf("After swapping floats: %.2f, %.2f\n", floatVar1, floatVar2);

    return 0;
}

