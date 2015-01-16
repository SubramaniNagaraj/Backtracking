#include <bits/stdc++.h>
#define NMAX 100

/*  The N Queen is the problem of placing N chess queens on an NxN chessboard
    so that no two queens attack each other.

    For example, n = 4:

    { 0,  1,  0,  0}
    { 0,  0,  0,  1}
    { 1,  0,  0,  0}
    { 0,  0,  1,  0}*/

int n, qtd_solution;
int a[NMAX][NMAX];

bool is_a_solution(int k, int n) {
    return k == n;
}
/*  A utility function to print solution */
void process_solution(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) printf("%d ", a[i][j]);
        printf("\n");
    }

    printf("\n");
    qtd_solution++;
}

/*  A utility function to check if a queen can be placed on board[row][col]
    Note that this function is called when "col" queens are already placed
    in columns from 0 to col -1. So we need to check only left side for attacking queens. */
bool conflict(int row, int col, int n) {
    /* Check this row on left side */
    for(int i = 0; i < col; i++)
        if (a[row][i]) return false;

    /* Check upper diagonal on left side */
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (a[i][j]) return false;

    /* Check lower diagonal on left side */
    for(int i = row, j = col; j >= 0 && i < n; i++, j--)
        if(a[i][j]) return false;

    /*
    for(int i = row, j = col; i >= 0 && j < n; i--, j++)
        if(a[i][j]) return false;

    for(int i = row, j = col; j >= 0; i++, j--)
        if(a[i][j]) return false;
    */

    return true;
}

/*  A recursive utility function to solve N Queen problem, where k is column. */
bool backtrack(int k, int n) {
    if (is_a_solution(k, n)) process_solution(n);

    /*  For just 1 solution, replace by:
        if (is_a_solution(k, n)) return true;
    */


    /* Consider this column and try placing this queen in all rows
       one by one */
    for(int i = 0; i < n; i++) {
        /* Check if queen can be placed on board[i][col] */
        if(conflict(i, k, n)) {
            /* Place this queen in board[i][col] */
            a[i][k] = 1;

            /* recur to place rest of the queens */
            if(backtrack(k+1, n) == true) return true;

            /* If placing queen in board[i][col] doesn't lead to a solution
               then remove queen from board[i][col] */
            a[i][k] = 0;
        }
    }

     /* If queen can not be place in any row in this colum col
        then return false */
    return false;
}

/*  This function solves the N Queen problem using Backtracking.It returns false if queens
    cannot be placed, otherwise return true and prints placement of queens in the form of 1s.
    There may be more than one solutions, this function prints one of the feasible solutions.*/
void generate_table(int n) {
    qtd_solution = 0;
    memset(a, 0, sizeof(a[0][0])*n*n);

    backtrack(0, n);
    printf("Ways: %d\n", qtd_solution);

     /*
    For just 1 solution, replace by:
    if(backtrack(0, n) == false)
        printf("Impossible solution.\n");
    else process_solution(n);
    */
}

int main() {
    scanf("%d", &n);
    generate_table(n);
    return 0;
}
