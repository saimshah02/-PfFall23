#include <stdio.h>

// Function to calculate the discount based on purchase amount and visit count
float calculateDiscount(float purchaseAmount, int visitCount) {
    float discount = 0.0;

    if (visitCount > 10 && purchaseAmount >= 50.0) {
        discount = 0.15 * purchaseAmount; // 15% discount
    } else if (visitCount > 5 && purchaseAmount >= 30.0) {
        discount = 0.10 * purchaseAmount; // 10% discount
    }

    return discount;
}

int main() {
    float totalPurchaseAmount;
    int visitCount;

    // Input the customer's total purchase amount and visit count
    printf("Enter the total purchase amount: $");
    scanf("%f", &totalPurchaseAmount);

    printf("Enter the number of times you have visited the shop in the past month: ");
    scanf("%d", &visitCount);

    // Calculate the discount using the calculateDiscount function
    float discount = calculateDiscount(totalPurchaseAmount, visitCount);

    if (discount > 0.0) {
        printf("You have a discount of $%.2f.\n", discount);
    } else {
        printf("No discount is applied.\n");
    }

    return 0;
}

