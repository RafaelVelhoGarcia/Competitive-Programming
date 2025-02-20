#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n , x, t , k;
    int p;
    int dp[23][1001];

    while (cin >> n >> x >> t >> k,n+x+t+k) {
        if (n == 0 && x == 0 && t == 0 && k == 0) break;

        p = (++n * x) / (float)1.1 - (n*t);

        vector<pair<int,int>>pf;
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            int a,b = 0, tmp;

            cin >> a;
            for (int j = 0; j < n;j++) cin >> tmp,b +=tmp;

            pf.push_back({a,b});
            pf.push_back({a,b});
        }

        for (int k = 0; k < pf.size();++k) {
            
            auto& [price,favour] = pf[k];
            for (int i = n * 2; i > 0; --i) for (int j = p; j >=price ;--j)
                dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i - 1 ][j - price] + favour));

        }
        for (int i = 0; i <= n*2;++i) ans = max(ans,dp[i][p]);
        cout << setprecision(2) << fixed << (double) ans/n << endl;

    }
    return 0;
}