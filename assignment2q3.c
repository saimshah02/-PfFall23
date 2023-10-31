#include <stdio.h>

#define N 5

// Function to print the path
void printPath(int path[N][N]) {
	int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            printf("(%d, %d) ", i, j);
            if (path[i][j] == 0) {
                printf("-> ");
            }
        }
    }
    printf("\n");
}

// Function to check if a cell is valid to move
int isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 'O');
}

// Function to solve the maze using backtracking
int solveMaze(int maze[N][N], int x, int y, int path[N][N]) {
    if (x == N - 1 && y == N - 1) {
        path[x][y] = 0; // Mark the exit cell
        return 1; // Maze is solved
    }

    if (isSafe(maze, x, y)) {
        path[x][y] = 0; // Mark the current cell as part of the path

        // Move right
        if (solveMaze(maze, x, y + 1, path)) {
            return 1;
        }

        // Move down
        if (solveMaze(maze, x + 1, y, path)) {
            return 1;
        }

        // If neither right nor down is a valid move, backtrack
        path[x][y] = 1;
    }

    return 0; // No path found
}

int main() {
    int maze[N][N] = {
        {'S', 'W', 'O', 'O', 'O'},
        {'O', 'W', 'W', 'W', 'O'},
        {'O', 'O', 'W', 'O', 'O'},
        {'O', 'W', 'O', 'W', 'W'},
        {'O', 'O', 'O', 'O', 'E'}
    };

    int path[N][N] = {0}; // Initialize the path array

    if (solveMaze(maze, 0, 0, path)) {
        printf("Path from starting point to exit:\n");
        printPath(path);
    } else {
        printf("No path found.\n");
    }

    return 0;
}

