#include <bits/stdc++.h>

using namespace std;

int memo[45][16010];
vector<int>a(50,0);
vector<int>vis(50,0);
int n , f;

int dp(int id, int rem) {
    if ((id == n) || (rem == 0)) return 0;
    int &ans = memo[id][rem];
    if (ans != -1) return ans;
    if (a[id] > rem) return ans = dp(id+1, rem);
    int way = a[id] + dp(id+1,rem - a[id]);
    int next = dp(id+1,rem);
    if (way > next){
        vis[id]++;
    }
    return ans = max(way,next);
    
}

int main() {
    while(cin >> n >> f) {
        if (n == 0 && f == 0) break;
        fill(vis.begin(),vis.end(),0);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }
        memset(memo,-1,sizeof(memo));
        int result = dp(0,f);
        cout << result << endl;
        for (int i = 0; i < n;i++) {
            if (vis[i] == 1) cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}