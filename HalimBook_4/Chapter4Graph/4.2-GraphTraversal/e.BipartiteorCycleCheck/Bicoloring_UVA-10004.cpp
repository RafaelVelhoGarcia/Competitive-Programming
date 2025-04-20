#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
vector<vector<int>> graph(210,vector<int>());
vector<int>vis(210,INF);

bool bfs(int s) {
    queue<int>q;
    bool bi = true;
    vis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();q.pop();
        for (auto v : graph[u]) {
            if (vis[v] == INF){
                vis[v] = 1 - vis[u] ;
                q.push(v);
            }
            else if (vis[v] == vis[u]) {
                bi = false;
                return bi;
                break;
            }
        }
    }
    return bi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l;
    int u,v;
    while (cin >> n && n != 0) {
        vis.assign(n+1,INF);
        graph.assign(n+1,vector<int>());
        cin >> l;
        for(int i = 0; i < l;i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (bfs(0) == true) {
            cout << "BICOLORABLE." << endl;
        }
        else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }
    return 0;
}