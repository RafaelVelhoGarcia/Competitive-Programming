#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    bool flag = false;
    while (cin >> t){
        while (t--) {
            int  a,b,c;
            cin >> a >> b >>c;
            int prod = a*b*c;
            int num;
            int sum = 0;
            int ans = 0;
            for (int i = 0; i < prod;i++) {
                cin >> num;
                sum += num;
                if (sum < 0) sum = 0;
                ans = max(ans,sum);
            }
        if (flag == false) {
            flag = true;
            cout << ans << endl;
            continue;
        }
        else {
            cout << endl;
            cout << ans << endl;
        }
        }

    }
}