#include <bits/stdc++.h>

using namespace std;


int vis[10010] = {0};


vector <int> bfsOfGraph (int v , vector<vector<int>> adj[]){
    vis[0] = 1;

    queue<int> q;
    q.push(0);
    vector <int> bfs;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]){
            if (!vis[it]){
                vis[it] = 1;

                q.push(vis[it]);

            } 


        }




        return bfs;

    }












}




int main(){







}