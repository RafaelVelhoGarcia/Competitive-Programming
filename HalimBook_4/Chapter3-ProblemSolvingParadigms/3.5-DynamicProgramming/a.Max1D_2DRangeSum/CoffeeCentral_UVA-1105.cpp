#include<bits/stdc++.h>

using namespace std;

int vis[2010][2010];
int dp[2010][2010], dx,dy;

void init() {
    for (int i = 1; i <= 2000;i++)
        for (int j = 1; j <= 2000;j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + vis[i][j];
}

int main() {
    int n,q,x,y,m,cas = 1;
    while(cin >> dx >> dy >> n >>q){
        
        if (dx == 0 && dy == 0 && n == 0 && q == 0) {
            break;
        }
        memset(vis,0,sizeof(vis));
        for (int i =1; i <=n;i++){
            cin >> x >> y;
            int nx = x + y;
            int ny = x - y + 1000;
            vis[nx][ny]++;
        }
        init();
        cout << "Case "<<cas++ <<":" << endl;
        for (int i = 1; i <= q; i++) {
            cin >> m;
            int ans = -1;
            int ansx = 0, ansy = 0;
            for (int y =1; y <=dy;y++) {
                for (int x =1; x <=dx;x++) {

                    int ni = x + y;
                    int nj = x - y + 1000;
                    int rx = min(ni+m,2000);
                    int ry = min(nj+m,2000);
                    int lx = max(ni -m-1,0);
                    int ly = max (nj-m-1,0);
                    int res = dp[rx][ry] - dp[lx][ry]- dp[rx][ly] + dp[lx][ly];
                   if (res > ans) {
                        ans = res;
                        ansx = x;
                        ansy = y;
                    }
                }
            }
            cout << ans <<" " <<"(" << ansx <<","<< ansy <<")" << endl;
        }
    }    

    return 0;
}