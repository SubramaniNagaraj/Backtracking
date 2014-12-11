#include <bits/stdc++.h>
#define NMAX 100

/*
    We can construct the 2^n subsets of n items by iterating through
    all possible 2^n length-n vectors of true or false, letting the ith element denote whether
    item i is or is not in the subset.
*/

bool is_a_solution(int a[], int k, int n) {
    return k == n;
}

void process_solution(int a[], int k) {
    for(int i = 1; i <= k; i++)
        if (a[i] == true) printf("%d ", i);
    printf("\n");
}

void construct_candidates(int c[], int& ncandidates) {
    c[0] = true;
    c[1] = false;
    ncandidates = 2;
}

void backtrack(int a[], int k, int n) {
    int c[NMAX];   /* candidates for next position */
    int ncandidates;        /* next position candidate count */

    if (is_a_solution(a,k,n))
        process_solution(a,k);
    else {
        k = k+1;
        construct_candidates(c,ncandidates);

        for(int i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a,k,n); /* terminate early */
        }
    }
}

void generate_subsets(int n) {
    int a[NMAX];    /* solution vector */
    backtrack(a, 0, n);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("Subsets:\n");
    generate_subsets(n);

    return 0;
}
