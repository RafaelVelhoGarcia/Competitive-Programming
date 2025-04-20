#include <bits/stdc++.h>

using namespace std;
vector<int>vis(502,0);
vector<vector<pair<int,int>>> grafo(502,vector<pair<int,int>>());
queue<int> fila;

int bfs(int s) {
    int sum = 1;
    fila.push(s);
    vis[s]++;
    while (!fila.empty()) {
        int u = fila.front(); fila.pop();
        for (auto par : grafo[u]) {
            int v = par.second;
            int c = par.first;
            if (vis[v] == 0) {
                fila.push(v);
                sum++;
                vis[v]++;
            }
        }
    }
    return sum;
}

int main() {
    int n,m;
    int u,v,w;
    while(cin >> n >> m) {
        if (n == 0 && m==0) break;
        grafo.assign(n+2,vector<pair<int,int>>());
        vis.assign(n+2,0);
        int max_w = INT_MIN;
        for (int i = 0; i < m;i++) {
            cin >> u >> v >> w;
            if (max_w <= w){
                if (max_w < w){
                    max_w = w;
                    grafo.assign(n+2,vector<pair<int,int>>());
                    vis.assign(n+2,0);
                }
                grafo[u].push_back({w,v});
                grafo[v].push_back({w,u});
            }
        }
        int ans = 0;
        for (int i = 1; i < n;i++) {
            ans = max(ans,bfs(i));
        }
        cout << ans << endl;
    }
    return 0;
}