#include <bits/stdc++.h>

using namespace std;

int t,r,c,m,n,w;
int grid[110][110];
int vis[110][110];
int k = 0;
vector<vector<int>> grafo;

bool valido(int x, int y) {
    return x < r && y < c && x >= 0 && y>= 0;
}
void dfs(int cc , int ll) {
    cout << " A " << endl;
    if (vis[cc][ll] == 0 && grid[cc][ll] != -1) {
        if (k % 2 == 0){
            vis[cc][ll] = 2;
        }
        else{
            vis[cc][ll] = 1;
        }
        k++;
        cout << "k " <<k << endl;
        if (valido(cc,ll)){
        dfs(cc+m,ll+n);
        dfs(cc+n,ll+m);
        }
    }
}
int main() {
    int x,y;
    cin >> t;
    for (int caso = 1; caso<= t;caso++) {
        k = 0;
        memset(grid,0,sizeof(grid));
        memset(vis,0,sizeof(vis));
        cin >> r >> c >> m >> n;
        cin >> w;
        for (int i = 0; i < w;i++) {
            cin >> x>> y;
            grid[x][y] = -1;
        }
        int odd = 0;
        int even = 0;
        dfs(0,0);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c;j++) {
                if (vis[i][j] == 1){
                    odd++;
                }
                if (vis[i][j] == 2){
                    even++;
                }
            }
        }
        cout << "Case " << caso << ": " << even <<" " << odd <<endl; 
    }
    return 0;
}