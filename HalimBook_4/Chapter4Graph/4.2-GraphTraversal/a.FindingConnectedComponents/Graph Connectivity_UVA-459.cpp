#include <bits/stdc++.h>

using namespace std;

vector<int>vis(26,0);
vector<vector<int>> grafo(26,vector<int>());

void dfs(int s) {
    if (vis[s] == 0) {
        vis[s]++;
        for (auto v : grafo[s]) {
            if (vis[v] == 0){
                dfs(v);
            }
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int aux = t;
    char last;
    char u,v;
    int uu,vv;
    string line;
    while(t--) {
        cin >> last;
        cin.ignore();
        int len = last - 'A' + 1;
        grafo.assign(26,vector<int>());
        vis.assign(26,0);
        while(getline(cin,line) && !line.empty()) {
        u = line[0];
        v = line[1];
        uu = u - 'A';
        vv = v - 'A';
        grafo[uu].push_back(vv);
        grafo[vv].push_back(uu);
    }
    dfs(0);
    int sum = 1;
    for (int i = 0; i < len; i++) {
        if (vis[i] == 0) {
            dfs(i);
            sum ++;
        }
    }
    if (t < aux-1) cout << endl;
    cout << sum<< endl;
}
    return 0;
}