#include <bits/stdc++.h>

using namespace std;
const int INF = 10000000;

int n,m;
vector<vector<pair<int,int>>> grafo;
int dist[110];
priority_queue< pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> q;

void djikstra(int s){
    dist[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        auto [d,u] = q.top();
        //cout << d << u << endl;
        q.pop();
        if (d > dist[u]) continue;

        for (auto [v,c] : grafo[u]){
            if (dist[v] > dist[u] + c)
            {
                dist[v] = dist[u] + c;
                q.push({dist[v],v});
            
            }



        }


    }
}
int main(){
    for (int i = 1; i < 110; i++){
        dist[i] = INF;
    }
    cin >> n>>m;
    //cout << n << m << endl;
    grafo.assign(n+1, vector<pair<int,int>>() );
    for (int i =0 ; i < m; i++){
        int u,v,c;
        cin >> u >> v >> c;
        grafo[u].push_back({v,c});
        grafo[v].push_back({u,c});
        //cout << "OOOOO" << endl;
    }

    djikstra(1);

    cout << dist[n] << endl;
}