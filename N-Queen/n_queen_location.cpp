#include <bits/stdc++.h>
#define MAXN 1000000
#define MAXM 3000
#define INF 0x7FFFFFFF

/*
    Some queens have been set on particular locations on the board.
    Given values representing the column number of the queen in each row.
    Print values changed, representing the column number of the queen in each rows.
*/

int L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int H[MAXM], S[MAXM], C[MAXN], X[MAXN], Y[MAXN], Q[MAXM], ans[MAXM], pos[MAXM];
int n, size;
bool vis[MAXM];

void Init(int m) {
    int i;
    for (i = 0; i <= m; i++) {
        R[i] = i + 1;
        L[i + 1] = i;
        U[i] = D[i] = i;
        S[i] = 0;
    }
    R[m] = 0;
    size = m + 1;
}
inline void Link(int r, int c, int row) {
    D[size] = D[c];
    U[size] = c;
    U[D[c]] = size;
    D[c] = size;
    if (H[r] < 0)
        H[r] = L[size] = R[size] = size;
    else {
        L[size] = H[r];
        R[size] = R[H[r]];
        L[R[H[r]]] = size;
        R[H[r]] = size;
    }
    S[c]++;
    X[size] = r;
    Y[size] = row;
    C[size++] = c;
}
void Remove(int c) {
    int i, j;
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (i = D[c]; i != c; i = D[i]) {
        for (j = R[i]; j != i; j = R[j]) {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            S[C[j]]--;
        }
    }
}
void Resume(int c) {
    int i, j;
    R[L[c]] = L[R[c]] = c;
    for (i = D[c]; i != c; i = D[i]) {
        for (j = R[i]; j != i; j = R[j]) {
            U[D[j]] = D[U[j]] = j;
            S[C[j]]++;
        }
    }
}
bool Dance(int now) {
    int i, j, temp, c;
    if (now >= n) {
        for (i = 0; i < n; i++)
            ans[Y[pos[i]]] = Q[X[pos[i]]];
        printf("%d", ans[1]);
        for (i = 2; i <= n; i++)
            printf(" %d", ans[i]);
        putchar('\n');
        return true;
    }
    if (R[0] == 0)
        return false;
    for (temp = INF,i = R[0]; i; i = R[i]) {
        if (i > n)
            break;
        if (temp > S[i]) {
            temp = S[i];
            c = i;
        }
    }
    Remove(c);
    for (i = D[c]; i != c; i = D[i]) {
        pos[now] = i;
        for (j = R[i]; j != i; j = R[j])
            Remove(C[j]);
        if (Dance(now + 1))
            return true;
        for (j = L[i]; j != i; j = L[j])
            Resume(C[j]);
        vis[X[i]] = false;
    }
    Resume(c);
    return false;
}
void Build(int r, int c, int &k, bool flag) {
    int p1, p2, p3, p4;
    p1 = r;
    p2 = n + c;
    p3 = n + n + r + c - 1;
    p4 = 4 * n - 1 + r - c + n;
    if (flag)
        vis[p1] = vis[p2] = vis[p3] = vis[p4] = true;
    if (flag || (!vis[p1] && !vis[p2] && !vis[p3] && !vis[p4])) {
        H[++k] = -1;
        Link(k, p1, r);
        Link(k, p2, r);
        Link(k, p3, r);
        Link(k, p4, r);
        Q[k] = c;
    }
}

int main() {
    int i, j, k;
    while (scanf("%d", &n) != EOF) {
        Init(6 * n - 2);
        memset(vis, false, sizeof(vis));
        for (k = 0, i = 1; i <= n; i++) {
            scanf("%d", &j);
            if (j)
                Build(i, j, k, true);
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                Build(i, j, k, false);
        }
        Dance(0);
    }
    return 0;
}
