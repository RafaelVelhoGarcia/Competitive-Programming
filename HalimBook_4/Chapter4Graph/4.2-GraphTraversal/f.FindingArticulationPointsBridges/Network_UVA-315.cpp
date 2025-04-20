#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> dfs_num, dfs_low, parent;
vector<bool> articulation;
int timer, rootChildren, root;

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = ++timer;
    for (int v : graph[u]) {
        if (dfs_num[v] == 0) { // Se v não foi visitado
            parent[v] = u;
            if (u == root) rootChildren++;

            dfs(v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);

            // Verifica se u é um ponto de articulação
            if (u != root && dfs_low[v] >= dfs_num[u]) {
                articulation[u] = true;
            }
        } else if (v != parent[u]) { // Aresta de retorno
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int findCriticalPlaces(int N) {
    timer = 0;
    dfs_num.assign(N + 1, 0);
    dfs_low.assign(N + 1, 0);
    parent.assign(N + 1, -1);
    articulation.assign(N + 1, false);

    int criticalPoints = 0;
    for (int i = 1; i <= N; i++) {
        if (dfs_num[i] == 0) {
            root = i;
            rootChildren = 0;
            dfs(i);
            if (rootChildren > 1) articulation[i] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (articulation[i]) criticalPoints++;
    }

    return criticalPoints;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        graph.assign(N + 1, vector<int>());
        cin.ignore();

        string line;
        while (getline(cin, line) && line != "0") {
            stringstream ss(line);
            int u, v;
            ss >> u;
            while (ss >> v) {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        cout << findCriticalPlaces(N) << endl;
    }
    return 0;
}
