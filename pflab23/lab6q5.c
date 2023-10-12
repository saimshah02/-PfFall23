#include <stdio.h>
int main() {
    int n = 6; 
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j < n - i; j++) {
            printf("   ");
        }
        for (j = 0; j < i * 2; j++) {
            printf("%d ", i);
        }
        printf("\n");
        if (i < n) {
            for (j = 0; j < n - i - 1; j++) {
                printf("   ");
            }
            printf("%d %d\n", i, i);
        }
    }

    return 0;
}

