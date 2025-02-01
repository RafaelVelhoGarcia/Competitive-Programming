#include <bits/stdc++.h>

using namespace std;
int a[100010];
int l[100010];
int r[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    l[0] = -1e9;
    for (int i = 1; i < n; i++) {
        l[i] = max(a[i-1],l[i-1]);
    }

    r[n-1] = 1e9;
    for (int i = n-2; i >= 0; i--) {
        r[i] = min(a[i+1],r[i+1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] <= a[i] && a[i] <= r[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}