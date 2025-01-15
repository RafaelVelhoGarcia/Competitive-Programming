#include <bits/stdc++.h>

using namespace std;
int n,m;
int dist[1010];
vector<vector<pair<int,int>>> grafo;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

void djikstra(int s){
    dist[s] = 0;
    q.push({0,s});
    //cout << "apaguei" << endl;
    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();
        //cout << d << " " << u << endl;
        //cout << dist[u] << endl;
        if (dist[u] < d) continue;

        for (auto [v,c] : grafo[u]){
            if (dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                q.push({dist[v],v});
                //cout << "adicionei " << dist[v] << " e  " << v << endl;
            }
            
        }
    }
}

int main(){
    for (int i = 0; i <= 1010; i++){
        dist[i] = 10000000;
    }
    cin >> n >> m;
    //cout << n << m;
    //cout << endl;
    grafo.assign(n+1, vector<pair<int,int>>());
    for (int i = 1; i <=m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        //cout << u << v << c << endl;
        grafo[u].push_back({v,c});
        grafo[v].push_back({u,c});
    }

    int s;
    cin >> s;
    //cout << s << endl;
    djikstra(s);
    int menor = -1;
    int maior = -1000000000;

    for (int i = 1; i <= n; i++){
        if (i == s) continue;
        if (menor == -1){
            menor = dist[i];
        }
        if (menor > dist[i] && dist[i] > 0){
            menor = dist[i];
        }
        if (dist[i] > maior){
            maior = dist[i];
        }
    }
    cout << maior - menor << endl;
}
