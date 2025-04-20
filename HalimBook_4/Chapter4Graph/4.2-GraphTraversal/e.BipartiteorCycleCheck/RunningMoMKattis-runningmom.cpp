#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> vis;
unordered_map<string,int> inpath;
unordered_map<string,vector<string>> graph;

bool dfs(string c) {
    vis[c] = 1;
    inpath[c] = 1;
    for (auto v : graph[c]) {
        if (vis[v] == 0) {
            if (dfs(v) == true)
                return true;
            
        }
        else if (inpath[v] == 1) {
            return true;
        }
    }
    inpath[c] = 0;
    return false;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    string a,b;
    set<string> con;
    for (int i= 0; i < n; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        con.insert(a);
        con.insert(b);
    }
    string c;
    while (cin >> c) {
        for (auto chave : con) {
            vis[chave] = 0;
            inpath[chave] = 0;
        }
        if (dfs(c) == true) {
            cout << c << " safe" << endl;
        }
        else {
            cout << c << " trapped" << endl;
        }
    }
    return 0;
}