#include <bits/stdc++.h>
#define MAXCANDIDATES 100

bool finished = false;      /* found all solutions yet? */

/*  Tests whether the first k elements of vector a are a complete solution for the given problem.
    The last argument, input, allows us to pass general information into the routine.
    We will use it to specify n, the size of a target solution. This makes sense when constructing
    permutations of size n or subsets of n elements, but may not be relevant when
    constructing variable-sized objects such as sequences of moves in a game. In such
    applications, this last argument can be ignored.
*/
bool is_a_solution(int a[], int k, int input) {}

/*
    This routine prints, counts, or somehow processes a complete solution once it
    is constructed. Note that the auxiliary input is unnecessary here, since k denotes
    the number of elements in the solution.
*/
void process_solution(int a[], int k, int input) {}

/*
    Fills an array c with the complete set of possible candidates for the kth position of a,
    given the contents of the first k-1 positions. The number of candidates returned in this
    array is denoted by ncandidates.
*/
void construct_candidates(int a[], int k, int input, int c[], int& ncandidates) {}

void backtrack(int a[], int k, int input) {
    int c[MAXCANDIDATES];   /* candidates for next position */
    int ncandidates;        /* next position candidate count */

    if (is_a_solution(a,k,input))
        process_solution(a,k,input);
    else {
        k = k+1;
        construct_candidates(a,k,input,c,ncandidates);

        for(int i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a,k,input);
            if (finished) return;   /* terminate early */
        }
    }
}

int main() {

    return 0;
}
