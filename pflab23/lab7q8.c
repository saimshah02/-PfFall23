#include <stdio.h>

int main() {
    int X, Y ,i ,j;

    // Input the number of branches (X) and mobile phones per branch (Y)
    printf("Enter the number of company branches (X): ");
    scanf("%d", &X);
    printf("Enter the number of mobile phones in each branch (Y): ");
    scanf("%d", &Y);

    if (X <= 0 || Y <= 0) {
        printf("X and Y should be positive integers.\n");
        return 1;
    }

    // Declare a 2D array to store bill amounts for each mobile phone in each branch
    double bills[X][Y];

    // Input bill amounts for all mobile phones in all branches
    for ( i = 0; i < X; i++) {
        for ( j = 0; j < Y; j++) {
            printf("Enter bill amount for Branch %d, Mobile Phone %d: ", i + 1, j + 1);
            scanf("%lf", &bills[i][j]);
        }
    }

    // Initialize variables to track total bills
    double totalBill = 0.0;
    double maxBranchBill = 0.0;
    int maxBranchID = 0;
    double maxPhoneBill = 0.0;
    int maxBranchPhoneID = 0;
    int maxPhoneID = 0;

    // Calculate and print total bill for all branches
    printf("Total bill for all branches: ");
    for ( i = 0; i < X; i++) {
        double branchBill = 0.0;
        for ( j = 0; j < Y; j++) {
            branchBill += bills[i][j];
            totalBill += bills[i][j];

            // Track maximum bill for mobile phones
            if (bills[i][j] > maxPhoneBill) {
                maxPhoneBill = bills[i][j];
                maxBranchPhoneID = i;
                maxPhoneID = j;
            }
        }

        // Track branch with the maximum bill
        if (branchBill > maxBranchBill) {
            maxBranchBill = branchBill;
            maxBranchID = i;
        }

        printf("Branch %d: $%.2lf  ", i + 1, branchBill);
    }

    // Print total bill for all branches
    printf("\nTotal bill for all branches: $%.2lf\n", totalBill);

    // Print branch with maximum bill
    printf("Branch with the maximum bill (Branch %d): $%.2lf\n", maxBranchID + 1, maxBranchBill);

    // Print branch and mobile phone IDs where bill is the highest
    printf("Branch and Mobile Phone IDs with the highest bill (Branch %d, Mobile Phone %d): $%.2lf\n",
           maxBranchPhoneID + 1, maxPhoneID + 1, maxPhoneBill);

    return 0;
}

