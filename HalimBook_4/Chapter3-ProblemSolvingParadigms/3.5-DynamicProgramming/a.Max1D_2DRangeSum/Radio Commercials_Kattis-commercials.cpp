#include<bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , p;
    int a[100100];
    cin >> n >> p;
    int num;
    for (int i = 0; i < n;i++) {
        cin >> num;
        a[i] = num - p;
    }
    int sum = 0;
    int ans = 0;
    for (int i =0 ; i < n; i++) {
        sum += a[i];
        if (sum < 0) sum = 0;
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}