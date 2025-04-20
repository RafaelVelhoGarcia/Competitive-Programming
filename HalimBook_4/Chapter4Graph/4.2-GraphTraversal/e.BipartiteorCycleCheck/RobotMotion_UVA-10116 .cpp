#include<bits/stdc++.h>

using namespace std;

char grid[11][11] = {0};
int vis[11][11] = {0};
int visx[11][11] = {0};

int l,c,s;

bool valid(int i , int j) {
    return i >= 0 && i < l && j >= 0 && j < c;
}

int step;
int loopstep;

pair<int,int> contador (int i, int j) {
    visx[i][j]++;
    step++;
    if (vis[i][j] == 2) return {i,j};
    if(valid(i,j)){
        if (grid[i][j] == 'W'){
            contador(i,j+1);
        }else if(grid[i][j] == 'S') {
            contador(i+1,j);
        }else if (grid[i][j] == 'N') {
            contador(i+1,j);
        } else {
            contador(i,j-1);
        }
    }
    return {i,j};
}

bool dfs(int i, int j) {
    vis[i][j] = 1;
    cout << "i  " << i << "  " << j << endl;
    cout << "Ii" << endl;
    //cout << "  : " << grid[i][j] << endl;
    if (valid(i,j) == false) return true;
    cout << "ZZ" << endl;
    if (grid[i][j] == 'W'){
        cout << "BB" << endl;
        if (!valid(i,j-1)) return true;
        cout << "UU" << endl;
        if (vis[i][j-1]) {
            vis[i][j-1]++;
            return false;
        }
        dfs(i,j-1);
    }else if(grid[i][j] == 'S') {
        if (valid(i+1,j) == false) return true;
        if (vis[i+1][j]) {
            vis[i+1][j]++;
            return false;
        }
        dfs(i+1,j);
    }else if (grid[i][j] == 'N') {
        if (valid(i-1,j) == false) return true;
        if (vis[i-1][j]) {
            vis[i-1][j]++;
            return false;
        }
        dfs(i-1,j);
    } else {
        if (valid(i,j+1) == false) return true;
        if (vis[i][j+1]) {
            vis[i][j+1]++;
            return false;
        }
        dfs(i,j+1);
    }
    return true;
}
int main() {
    while (cin >> l >> c >> s) {
        s--;
        if (l == 0 && c == 0 && s == 0) break;
        for (int i = 0;i < l; i++){
            for (int j = 0; j < c;j++){
                cin >> grid[i][j];
            }
        }
        step = 0;
        loopstep= 0;
        memset(visx,0,sizeof(visx));
        memset(vis,0,sizeof(vis));
        bool res = dfs(0,s);
        if (res) {
            auto  par = contador(0,s);
            cout << step << endl;
        } else {
            auto  par = contador(0,s);
            cout << step;
            step = 0;
            contador(par.first,par.second);
            cout <<"  " << step << endl;
        }
    }
    return 0;
}