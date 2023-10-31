#include <stdio.h>
#include <math.h>

#define MAX_N 1000

// Function to find all Ramanujan-Hardy numbers less than n^3
void findRamanujanHardy(int n) {
	int a,d,b;
    for ( a = 1; a < n; a++) {
        int a_cube = a * a * a;

        for ( b = a; b < n; b++) {
            int b_cube = b * b * b;
            int sum = a_cube + b_cube;

            // Check if the sum is less than n^3
            if (sum < n * n * n) {
                int c = a + 1;
                while (c < n) {
                    int c_cube = c * c * c;

                    for ( d = c; d < n; d++) {
                        int d_cube = d * d * d;
                        int second_sum = c_cube + d_cube;

                        if (sum == second_sum) {
                            printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n", sum, a, b, c, d);
                        } else if (second_sum > sum) {
                            break;  // No need to continue checking larger values of c and d
                        }
                    }

                    c++;
                }
            } else {
                break;  // No need to continue checking larger values of a and b
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("n should be greater than or equal to 2.\n");
    } else {
        findRamanujanHardy(n);
    }

    return 0;
}

