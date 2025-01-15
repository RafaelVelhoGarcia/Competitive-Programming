#include <bits/stdc++.h>
/*
Cada time é constituído de um ou mais alunos, e cada aluno tem que pertencer a exatamente um time. Além disso, os times 
não podem ser formados de qualquer maneira: se um aluno é amigo de outro, esses alunos devem estar no mesmo time.
7 6
1 6
6 4                  1 - 6           time 1 : 1 6(7(2(5) 3)4)
5 2                  2 - 5 3 7
3 7                    3 - 2 7
2 3                     4 - 6
7 2                     5 - 2
                        6 - 7 1 4
                        7 - 2 3 6


*/




using namespace std;

int N,M;
vector<vector<int>> adj;
int vis[1010] = {0};
vector<int> ls;

void dfs(int S){
    vis[S] = 1;
    ls.push_back(S);
    for (auto it : adj[S]){
        if (!vis[it]){
            ls.push_back(it);
            dfs(it);
        }
    }


}

int main(){

    cin>>N>>M;
    adj.assign(N, vector<int>());

    for (int i = 0 ; i < M ; i++){
        int u,v;
        u--; v--;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    dfs(0);
    for (int












}