#include <bits/stdc++.h>

using namespace std;
int a[1000002];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int t;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
        a[t+1000]--;
    }
    int soma = 0;
    int res = 0;
    for (int i = 0; i < 1000002; i++){
        soma+= a[i];
        res = max(res,(soma + k - 1)/k);
    }
    cout << res << endl;
    return 0;
}