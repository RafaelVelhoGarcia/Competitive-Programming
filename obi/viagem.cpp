#include <bits/stdc++.h>
const int MAX = 10010;
const int INF = 1e9; 
using namespace std;

typedef pair<int,int> pii;



int v,n,m;

priority_queue <pii,vector<pii>,greater<pii>> fila;

vector<vector<pii>> grafo(MAX);
int vis[MAX] = {0};
int dis[MAX] = {INF};

void dijkstra(int o, int d, int limite){
    fill(dis, dis + MAX, INF);
    dis[o] = 0;
    vis[o] = 1;
    fila.push({0,o});

    while (!fila.empty()){
        auto [d,u] = fila.top();
        vis[u] = 1;
        if (d > dis[u] or d >= limite) continue;


        for (auto [v,c] : grafo[u]){
            if (dis[u] > dis[v] + c and dis[v] + c <= limite){
                dis[u] = dis[v] + c;
                fila.push({dis[v],v});
            }
             vis[v] = 1;

        }



    }




}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> v,n,m; 
    for (int i = 1; i<= n;i++){
        int u,v,te,p;

        cin>> u >> v >> te>>p;

        grafo[u].push_back({v,te});
        grafo[v].push_back({u,te});
    }
    int ori , des;

    cin >> ori>> des;

    dijkstra(ori,des,v);

    cout << dis[des] << endl;
    
}

