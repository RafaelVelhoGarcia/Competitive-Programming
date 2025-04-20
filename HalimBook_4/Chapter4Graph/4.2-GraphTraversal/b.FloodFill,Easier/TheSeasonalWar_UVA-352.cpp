#include<bits/stdc++.h>

using namespace std;
int n;

int matriz[30][30];
int vis[30][30];

bool valid (int i ,int j) {
    return i >= 0 && i < n && j >= 0 && j < n;
}
int dx[ ] = {1,1,0,-1,-1,-1,0,1};
int dy[ ] = {0,1,1,1,0,-1,-1,-1};

void dfs (int l ,int c) {
    if (vis[l][c] == 0 && matriz[l][c] == 1) {
        vis[l][c]++;
        for (int i =0 ; i < 8;i++) {
            int u = l + dx[i];
            int v = c + dy[i];
            if (valid(u,v)) {
                    dfs(u,v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int caso = 0;
    while (cin >> n)
    {
        memset(matriz,0,sizeof(matriz));
        string line;
        caso++;
        for (int i = 0; i < n; i++) {
            cin>> line;
            for (int j = 0; j < n;j++){
                if (line[j] == '1') {
                    matriz[i][j] = 1;
                }
            }
        }   
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n ;j++) {
                if (vis[i][j] == 0 && matriz[i][j] == 1) {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        cout <<"Image number "<<caso<<" contains "<<ans<<" war eagles."<<endl;
    }
    return 0;
}