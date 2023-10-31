#include <stdio.h>

// Function to fill the first array inwards with spiral incremental numbers
void fillInwardsSpiral(int n, int arr[][n]) {
    int num = 1 ,i;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for ( i = right; i >= left; i--) {
            arr[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            arr[i][left] = num++;
        }
        left++;

        for (int i = left; i <= right; i++) {
            arr[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            arr[i][right] = num++;
        }
        right--;
    }
}

// Function to fill the second array outwards with spiral incremental numbers
void fillOutwardsSpiral(int n, int arr[][n]) {
    int num = n * n ,i;
    int left = 0, right = n - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom) {
        for ( i = top; i <= bottom; i++) {
            arr[i][left] = num--;
        }
        left++;

        for ( i = left; i <= right; i++) {
            arr[top][i] = num--;
        }
        top++;

        for ( i = top; i <= bottom; i++) {
            arr[i][right] = num--;
        }
        right--;

        for ( i = right; i >= left; i--) {
            arr[bottom][i] = num--;
        }
        bottom--;
    }
}

// Function to print a 2D array
void printArray(int n, int arr[][n]) {
	int i,j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1);

    int inwardsSpiral[N][N];
    int outwardsSpiral[N][N];

    fillInwardsSpiral(N, inwardsSpiral);
    fillOutwardsSpiral(N, outwardsSpiral);

    printf("Inwards Spiral:\n");
    printArray(N, inwardsSpiral);

    printf("\nOutwards Spiral:\n");
    printArray(N, outwardsSpiral);

    return 0;
}

