#include <stdio.h>

int main() {
    int numBatsmen, numInnings ,i ,j;
    
    // Input the number of batsmen and innings
    printf("Enter the number of batsmen: ");
    scanf("%d", &numBatsmen);
    printf("Enter the number of innings: ");
    scanf("%d", &numInnings);
    
    // Declare a 2D array to store batting performance
    int battingPerformance[numBatsmen][numInnings];
    
    // Input batting performance for each batsman
    for ( i = 0; i < numBatsmen; i++) {
        printf("Enter batting performance for batsman %d:\n", i + 1);
        for ( j = 0; j < numInnings; j++) {
            printf("Inning %d: ", j + 1);
            scanf("%d", &battingPerformance[i][j]);
        }
    }
    
    // Calculate and display statistics for each batsman
    for (i = 0; i < numBatsmen; i++) {
        int totalRuns = 0;
        int highestScore = 0;
        int centuries = 0;
        int halfCenturies = 0;
        
        for ( j = 0; j < numInnings; j++) {
            totalRuns += battingPerformance[i][j];
            if (battingPerformance[i][j] > highestScore) {
                highestScore = battingPerformance[i][j];
            }
            if (battingPerformance[i][j] >= 100) {
                centuries++;
            } else if (battingPerformance[i][j] >= 50) {
                halfCenturies++;
            }
        }
        
        // Calculate average runs per inning
        float averageRuns = (float)totalRuns / numInnings;
        
        // Display statistics for the current batsman
        printf("\nStatistics for batsman %d:\n", i + 1);
        printf("Total runs scored: %d\n", totalRuns);
        printf("Average runs per inning: %.2f\n", averageRuns);
        printf("Highest score in a single inning: %d\n", highestScore);
        printf("Number of centuries: %d\n", centuries);
        printf("Number of half-centuries: %d\n", halfCenturies);
    }
    
    return 0;
}

