#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10000;
vector<int> adj[MAXN];
bool visited[MAXN];
int tin[MAXN], low[MAXN], timer;
int pigeon_value[MAXN];

void dfs(int v, int parent, int &num_components) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == parent) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v, num_components);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && parent != -1) {
                pigeon_value[v]++;
            }
            children++;
        }
    }
    if (parent == -1 && children > 1) {
        pigeon_value[v] = children - 1;
    }
    if (parent == -1) num_components++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) adj[i].clear();
        memset(visited, false, sizeof(visited));
        memset(pigeon_value, 0, sizeof(pigeon_value));
        timer = 0;

        int x, y;
        while (cin >> x >> y, x != -1 && y != -1) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int num_components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, num_components);
            }
        }

        vector<pair<int, int>> result;
        for (int i = 0; i < n; i++) {
            result.emplace_back(i, pigeon_value[i] + 1);
        }

        sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        for (int i = 0; i < m; i++) {
            cout << result[i].first << " " << result[i].second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
