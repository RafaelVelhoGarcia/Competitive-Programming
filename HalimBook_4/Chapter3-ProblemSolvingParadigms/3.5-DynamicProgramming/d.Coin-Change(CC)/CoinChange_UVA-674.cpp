#include <bits/stdc++.h>

using namespace std;

int tipos[5] = {1,5,10,25,50};
int memo[6][7489];
int sum;

int dp(int type,int valor) {
    if (valor == 0) return 1;
    if ((type == 5) || (valor < 0)) return 0;
    int &ans = memo[type][valor];
    if (ans != -1) return ans;
    return ans = dp(type+1,valor) + dp(type,valor-tipos[type]);
}
int main() {
    memset(memo,-1,sizeof(memo));
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (cin >> sum) {
        int result = dp(0,sum);
        cout << memo[0][sum] << endl;
    }

    return 0;
}