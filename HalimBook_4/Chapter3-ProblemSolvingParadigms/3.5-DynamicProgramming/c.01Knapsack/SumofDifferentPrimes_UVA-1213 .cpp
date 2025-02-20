#include <bits/stdc++.h>

using namespace std;

namespace Sieve {
    const int P = 5e6 + 1;
    vector<bool> is_prime(P, true);
    int lpf[P], primes[P], cnt = 0;
    void build() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < P; i++) {
    if (is_prime[i]) {
    lpf[i] = i;
    primes[cnt++] = i;
    }
    for (int j = 0; j < cnt && i * primes[j] < P; j++) {
    is_prime[i * primes[j]] = 0;
    lpf[i * primes[j]] = primes[j];
    if (i % primes[j] == 0) break;
    }
    }
    }
    vector<int> factorize(int n) {
    vector<int> f;
    while (n > 1) {
    f.push_back(lpf[n]);
    n /= lpf[n];
    }
    return f;
    }
    }
int n,k;

int memo[200][15][1200];

int dp(int id, int rem,int sum) {
    int &ans = memo[id][rem][sum];
    if (ans != -1) return ans;
    if ((sum == 0) && (rem == 0)) return ans = 1;
    if (id >= 190 && (sum > 0 || rem > 0)) return 0;

    int ways = 0;
    if (rem > 0 && sum >= Sieve::primes[id]) {
        ways += dp( id + 1, rem - 1, sum - Sieve::primes[id]);
    }
    ways += dp(id + 1,rem,sum);
    return ans = ways;
}
int main() {
    // crivo
    Sieve::build();
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        memset(memo,-1,sizeof(memo));
        int solve = dp(0,k,n);
        cout << solve << endl;
    }

    return 0;
}