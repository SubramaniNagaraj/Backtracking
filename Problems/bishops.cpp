#include <bits/stdc++.h>
#define MAXN 1000

/*
    Bishops = bispo de xadrez
    Given two numbers N and K, determine the number of ways one can put K bishops
    on an NxN chessboard so that no two of them are in attacking positions.
*/

/* 2*n-1 = all possible squares we can visit on diagonal. */

int n, m, num;

void construct_candidates(int a[], int k, int c[], int *ncandidates) {
	*ncandidates = 0;

	int ans = k, i, bns = 0, t, flag;

    /* if k > n, the max answer will be 2*n-1.*/
	if(k > n) ans = 2*n-k;

	for(i = 0; i <= ans; i++) {
        flag = 1;

		for(int j = 1; j < k && i != 0; j++) {
            /* k % 2 != j % 2 means that the positions of row/column are in diagonal. */
			if(k % 2 != j % 2) continue;

			/* if a[j] = 0, we know that the bishop will be in diagonal
               (next or previous position). */
			if(a[j] == 0) continue;

			/* j > n means that we passed all squares in diagonal.
			   So, we need to atribute the maximum position. */
			if(j > n) bns = 2*n-j;
			else bns = j;
            
			if(k > n && j > n) {
				t = (abs(j-k)/2);

				if(t+i == a[j]) flag = 0;
			} else if(k > n && j <= n) {
				t = (abs(2*n-k-j)/2);

				if(2*n-k < j) {
					if(i+t == a[j])
					flag = 0;
				} else if(i == t+a[j])
                    flag = 0;
			} else if(k <= n && j <= n) {
					t = (abs(k-j)/2);
					if(t + a[j] == i) flag = 0;
			}
		}

		if(flag) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates+1;
		}
	}
}

bool is_a_solution(int k, int count) {
    /* If we used all bishops, is because we found one solution. */
	if(count == m) {
		num++;
	    return true;
	}

    /* 2*n-1 = all possible squares we can visit on diagonal. */
	if(k == 2*n-1) return true;
	return false;
}

void backtrack(int a[], int k, int count) {
	int c[MAXN], flag;
	int ncandidates;

	if(is_a_solution(k, count) == false) {
		k++;
		construct_candidates(a, k, c, &ncandidates);
        flag = 1;

		for(int i = 0; i < ncandidates; i++) {
			a[k] = c[i];

			if(c[i] != 0 && flag) {
				count++;
				flag = 0;
			}

			if(count + 2*n-1-k >= m)
                backtrack(a,k,count);
		}
	}
}

void generate_board() {
    int a[MAXN]; /* NxN chessboard */
    num = 0;     /* number of ways */

    backtrack(a, 0, 0);
    printf("%d\n", num);
}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
        generate_board();
	}

	return 0;
}
