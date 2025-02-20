#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<pair<int,int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(),a.end());
        vector<int>dp(n,1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j].first <= a[i].first && a[j].second <= a[i].second){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }

        cout << *max_element(dp.begin(),dp.end())<< endl;
    }
    cout << "*" << endl;
    return 0;
}