#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    int a[100] = {1};
    for (int x = 1; x <= t; x++) {
        cin >> s;

        for (int i = 0; i < s.size();i++) a[i] = 1;


        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'D' || s[i] == 'B') {
                a[i] = 0;
                if (s[i] == 'B') {
                    a[i-1] = 0;
                    a[i-2] = 0;
                }
            }
            if (s[i] == 'S') {
                a[i] = 0;
                a[i+1] = 0;
                a[i-1] = 0;
            }
        }
        int ans = 0;
        for (int i = 0 ; i < s.size();i++) {
            ans += a[i];
        }
        cout <<"Case "<< x <<": "<<ans << endl;
    }

    return 0;
}