#include <bits/stdc++.h>

using namespace std;
int n;
int vis[110][110];
int matriz[110][110];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool limite(int x,int y){
    return y >= 0 && x >=0 && x <= n and y <= n;
}

void dfs(int x,int y){
    if (!vis[x][y]){
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (!vis[xx][yy] && limite(xx,yy) && matriz[x][y] <= matriz[xx][yy]){
                //cout << "vou para :" << xx << yy << endl;
                dfs(xx,yy);
            }


        }
        for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (limite(xx,yy) && matriz[x][y] <= matriz[xx][yy]){
                dfs(xx,yy);
            }


        }
    }
    for (int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (limite(xx,yy) && matriz[x][y] <= matriz[xx][yy] && !vis[xx][yy]){
                dfs(xx,yy);
            }
        }





}


int main(){

    cin >> n;
 
    int xi, yi;

    cin >> xi >> yi;


    for (int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cin >> matriz[i][j];
        }

    }
      
        //cout << endl;
    
    xi--;yi--;
    
    dfs(xi,yi);
    int cont = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if (vis[i][j]){
                cont++;
            }
        }
    }
    cout << cont << endl;












}