#include <bits/stdc++.h>
#define NMAX 100

/* Function to swap values at two pointers */
void swap (char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

bool is_a_solution(int k, int n) {
    return k == n;
}
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void backtrack(char *a, int k, int n) {
    if (is_a_solution(k, n)) {
        printf("%s\n", a);
        return;
    }

    for(int i = k; i <= n; i++) {
        swap((a+k), (a+i));
        backtrack(a, k+1, n);
        swap((a+k), (a+i));
    }
}

void generate_permutations(char a[], int n) {
    backtrack(a, 0, n);
}

int main() {
    //char str[] = "123";
    char a[NMAX];

    //for(int i = 0; i < 3; i++) scanf("%s", &str[i]);
    scanf("%s", a);

    printf("Permutations:\n");
    generate_permutations(a, strlen(a) - 1);

    return 0;
}
