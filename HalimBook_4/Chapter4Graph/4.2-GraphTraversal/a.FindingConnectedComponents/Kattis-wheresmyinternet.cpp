#include <bits/stdc++.h>

using namespace std;

vector<int>vis(200001,0);

vector<vector<int>> grafo(200001,vector<int>());

void dfs(int s){
    if (vis[s] == 0) {
        vis[s]++;
        for (auto u : grafo[s]) {
            if (vis[u] == 0) dfs(u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int u,v;
    set<int> houses;
    for (int i = 0; i < m;i++) {
        cin >> u >> v;
        houses.insert(u);
        houses.insert(v);
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    dfs(1);
    int sum = accumulate(vis.begin(),vis.end(),0);
    if (sum == n) {
        cout << "Connected" << endl;
        return 0;
    }
    for (int i = 2; i <= n;i++) {
        if (vis[i] == 0) {
            cout << i << endl;
        }
    }
    return 0;
}