#include <bits/stdc++.h>

using namespace std;

int memo[6][7555];

int dp(int type,int valor) {
    if (valor == 0) return 1;
    if ((type == 4) || (valor < 0)) return 0;
    int &ans = memo[type][valor];
    if (ans != -1) return ans;
    return ans = dp(type+1,valor) + dp(type,valor-tipos[type]);
}
int tipos[5] = {1,5,10,25,50};
int sum;
int main() {
    while (cin >> sum) {
        memset(memo,-1,sizeof(memo));
        int result = dp(0,sum);
        cout << result << endl;
    }

    return 0;
}