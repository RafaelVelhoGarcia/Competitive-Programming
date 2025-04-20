#include<bits/stdc++.h>

using namespace std;

int grid[110][110];
int vis[111][111];
int n,m;

bool valid(int i , int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int dx[ ] = {1,1,0,-1,-1,-1,0,1};
int dy[ ] = {0,1,1,1,0,-1,-1,-1};


void dfs(int i ,int j) {
    if (vis[i][j] == 0) {
        vis[i][j]++;
        for (int x = 0; x < 8; x++) {
            int  u = i + dx[x]; int v = j + dy[x];
            if (valid(u,v)) {
                if (vis[u][v] == 0 && grid[u][v] == 1) {
                    dfs(u,v);
                }
            }
        }

    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    while (cin >> n >> m) {
        //cout << n << m << endl;
        if (n == 0 && m == 0) break;
        char let;
        int s = 0,r = 0;
        memset(grid,0,sizeof(grid));
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m;j++) {
                cin >> let;           
                if (let == '@') {
                    grid[i][j] = 1;
                    s = i;
                    r = j;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < m;j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}