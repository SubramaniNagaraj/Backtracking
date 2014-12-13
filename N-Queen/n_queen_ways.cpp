#include <bits/stdc++.h>

/* How many distinct ways there are to place n mutually non-attacking queens on an NxN chessboard. */

int ways;

typedef struct {
    int row;
    int col;
} place;

bool is_a_solution(int k, int n) {
    return k == n;
}

void process_solution(place *p, int n) {
    ways++;
    printf("Solution: ");
    for(int i = 0; i < n; i++) printf("(%d, %d) ", p[i].row, p[i].col);
    printf("\n");
}

bool conflict(place *p, int x, int y) {
    /* Studying p and tell whether there is a conflict between the xth and the yth queen or not */

    /* Verify if queens are in the same row */
    if(p[x].row == p[y].row) return true;

    /* Verify if queens are in a diagonal*/
    if((p[x].row - p[y].row) == (p[x].col - p[y].col)) return true;

    /* Verify if queens are in another diagonal*/
    if((p[x].row - p[y].row) == (-p[x].col + p[y].col)) return true;

    return false;
}

/* k = current queen */
void backtrack(place *p, int k, int n) {
    //that means we have been successful in forming a clash free array till the end.
    if(is_a_solution(k, n)) {
        process_solution(p, n);
        return;
    }

    //it it sure that the 0th queen will be placed in the 0th column, however its row number may vary
    //i here indicates the row number
    for(int i = 0; i < n; i++) {
        bool is_conflict = false;

        p[k].row = i;
        p[k].col = k;

        for(int j = 0; j < k; j++)
            if(conflict(p, k, j) == true) {
                is_conflict = true;
                break;
            }
        if(is_conflict == true) continue;
        else backtrack(p, k+1, n);
    }
}

void generate_board(int n) {
    ways = 0;
    place *p = (place*) malloc(n * sizeof(place));
    backtrack(p, 0, n);
    printf("Ways: %d\n", ways);
}

int main() {
    int n;
    scanf("%d", &n);

    generate_board(n);
    return 0;
}
