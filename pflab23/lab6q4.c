#include <stdio.h>
int main() {
    int a, b,i;
    
    printf("Enter the starting integer (a): ");
    scanf("%d", &a);
    
    printf("Enter the ending integer (b): ");
    scanf("%d", &b);

    if (a <= b) {

        for ( i = a; i <= b; i++) {
            if (i <= 9) {
                switch (i) {
                    case 0:
                        printf("Zero\n");
                        break;
                    case 1:
                        printf("One\n");
                        break;
                    case 2:
                        printf("Two\n");
                        break;
                    case 3:
                        printf("Three\n");
                        break;
                    case 4:
                        printf("Four\n");
                        break;
                    case 5:
                        printf("Five\n");
                        break;
                    case 6:
                        printf("Six\n");
                        break;
                    case 7:
                        printf("Seven\n");
                        break;
                    case 8:
                        printf("Eight\n");
                        break;
                    case 9:
                        printf("Nine\n");
                        break;
                }
            } else {
                if (i % 2 == 0) {
                    printf("%d is even\n", i);
                } else {
                    printf("%d is odd\n", i);
                }
            }
        }
    } else {
        printf("Starting integer (a) should be less than or equal to the ending integer (b).\n");
    }

    return 0;
}

