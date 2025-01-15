#include <bits/stdc++.h>

using namespace std;

int C,R;
map <string,int> mapa;
vector<vector<int>> adj;
int dis[50010] = {0};
int vis[50010] = {0};


void dfs (int node){
    vis[node] = 1;
    for (auto it: adj[node]){
        if (!vis[it]){
            dis[it] = dis[node] + 1;
        }
    }

}


int main (){

    while (true){

        cin >> C >> R;
        if (C==0 and R == 0){
            break;

        }


        for (int i = 0 ; i < C ; i++){
            string bixo;
            cin>> bixo;

            mapa[bixo] = i;
        }

        for (int i =0 ; i < R ; i++){
            string a, b;
            int x,y;
            cin >> a >> b;
            x = mapa[a];
            y = mapa[b];

            adj[y].push_back(x);
        }

        for (int i = 0 ; i < C ; i++){
            int node = i;
            for (auto it : adj[node]){
                if (!vis[it]){
                    dfs(it);
                }

            }
        }

        int maiorDis = 0;
        for (int i = 0 ; i < C; i++){
            int atual = dis[i];

            if (atual > maiorDis)
                maiorDis = atual;
        }

        cout << maiorDis << endl;
    }

}