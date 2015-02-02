#include <bits/stdc++.h>
#define MAXM 10
#define MAXN 10

using namespace std;
/*  A Maze is given as N*N binary matrix of blocks where source block is the upper left most block i.e.,
    maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1].
    A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
    In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path
    from source to destination.*/

int m, n;
int maze[MAXM][MAXN], sol[MAXM][MAXN], gone[MAXM][MAXN];

/* A utility function to check if x,y is valid index for N*N maze */
bool isSafe(int x, int y) {
    /* if (x,y outside maze) return false */
    if(x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && gone[x][y] == 0) return true;
    return false;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int x, int y) {
    /* if (x,y is goal) return true */

    if(x == n-1 && y == m-1) {
        sol[x][y] = 1;
        return true;
    }

    /* Check if maze[x][y] is valid */
    if(isSafe(x, y) == true) {
        /* mark x,y as part of solution path */
        sol[x][y] = 1;
        gone[x][y] = 1;

         /* Move forward in x direction */
        if (solveMazeUtil(x+1, y) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(x, y+1) == true)
            return true;

        /* In case of diagonal movements, replace by:

        if (solveMazeUtil(x+1, y+1) == true)
            return true;

        if (solveMazeUtil(x+1, y) == true)
            return true;

        if (solveMazeUtil(x, y+1) == true)
            return true;

        if (solveMazeUtil(x-1, y) == true)
            return true;

        if (solveMazeUtil(x+1, y-1) == true)
            return true;

        if (solveMazeUtil(x-1, y+1) == true)
            return true;

        if (solveMazeUtil(x-1, y-1) == true)
            return true;

        if (solveMazeUtil(x, y-1) == true)
            return true;
        */

        /*  For all movements except diagonal, replace by:

        if (solveMazeUtil(x+1, y) == true)
            return true;

        if (solveMazeUtil(x, y+1) == true)
            return true;

        if (solveMazeUtil(x, y-1) == true)
            return true;

        if (solveMazeUtil(x-1, y) == true)
            return true;
        */

        /*  If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution() {
    printf("\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

void solveMaze() {
    memset(sol, 0, sizeof(sol));
    memset(gone, 0, sizeof(gone));

    if(solveMazeUtil(0, 0) == false) {
        printf("No solution\n");
        return;
    }

    printSolution();
}

int main() {
/*
     int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    */
    while(scanf("%d %d", &m, &n) != EOF) {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) scanf("%d", &maze[i][j]);

        solveMaze();
    }

    return 0;
}
