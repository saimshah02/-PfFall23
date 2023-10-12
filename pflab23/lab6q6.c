#include <stdio.h>
int main() {
    int totalMatches = 21;
    int userPick, computerPick;

    printf("Welcome to the Matchstick Game!\n");

    while (totalMatches > 1) {
        printf("Remaining matchsticks: %d\n", totalMatches);
        printf("Pick 1, 2, 3, or 4 matchsticks: ");
        scanf("%d", &userPick);

        if (userPick < 1 || userPick > 4 || userPick > totalMatches) {
            printf("Invalid input. Please pick 1, 2, 3, or 4 matchsticks.\n");
            continue;
        }

        totalMatches -= userPick;
        if (totalMatches == 1) {
            printf("You picked the last matchstick. You lose!\n");
            break;
        }

        computerPick = 5 - userPick;
        printf("Computer picks %d matchsticks.\n", computerPick);
        totalMatches -= computerPick;
    }

    if (totalMatches == 1) {
        printf("The computer picked the last matchstick. You win!\n");
    }

    return 0;
}

