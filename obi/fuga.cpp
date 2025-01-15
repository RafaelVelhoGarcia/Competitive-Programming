#include <bits/stdc++.h>

using namespace std;

int L, C, li, lf, ci, cf;
int G[15][15];
int custo;
int resp;

int dl[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

bool limite(int l, int c) {
    return l >= 1 && c >= 1 && l <= L && c <= C && G[l][c] == 0;
}

int dfs(int l, int c) {
    G[l][c] = 1;
    custo++;

    if (l == lf && c == cf) {
        resp = max(resp, custo);
    } else {
        for (int i = 0; i < 4; i++) {
            int ll = l + dl[i];
            int cc = c + dc[i];

            if (limite(ll, cc)) dfs(ll, cc);
        }
    }
    custo--;
    G[l][c] = 0;
}

int main() {
    cin >> L >> C >> li >> lf >> ci >> cf;

    for (int i = 2; i < L; i += 2)
        for (int j = 2; j < C; j += 2)
            G[i][j] = 1;

    resp = 0;
    custo = 0;
    dfs(li, ci);

    cout << resp << endl;

    return 0;
}
