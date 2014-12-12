#include <bits/stdc++.h>
#define NMAX 100

/* Permutations in lexicographic order. */

bool is_a_solution(int k, int n) {
    return k == n;
}

void insert_swap(char a[], int k, int n) {
    char temp[10] = {0};

    if(is_a_solution(k, n)) return;

    memcpy(temp, &a[k], n-k);
    a[k] = a[n];
    memcpy(&a[k+1], temp, n-k);
}

void undo_swap(char a[], int k, int n) {
    char temp;

    if(is_a_solution(k, n)) return;

    temp = a[k];
    memcpy(&a[k], &a[k+1], n-k);
    a[n] = temp;
}

void backtrack(char a[], int k, int n) {
    if (is_a_solution(k, n)) {
        printf("%s\n", a);
        return;
    }

    for(int i = k; i <= n; i++) {
        insert_swap(a, k, i);
        backtrack(a, k+1, n);
        undo_swap(a, k, i);
    }
}

void generate_permutations(char a[], int n) {
    backtrack(a, 0, n);
}


int main() {
    //char str[] = "123";
    char str[NMAX];

    //for(int i = 0; i < 3; i++) scanf("%s", &str[i]);
    scanf("%s", str);

    printf("Permutations:\n");
    generate_permutations(str, strlen(str) - 1);

    return 0;
}
