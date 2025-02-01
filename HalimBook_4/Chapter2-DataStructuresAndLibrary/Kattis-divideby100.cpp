#include<bits/stdc++.h>

using namespace std;

string a,b;
int main () {
    cin >> a; 
    cin >>b;
    int n = a.size(), m =b.size();
    while(n && m > 1 && a[n-1] == '0') {
        --n;
        --m;
    }
    int x = n - m;
    if (x < 0) {
        cout << "0.";
        for (int i = x+1; i < 0; ++i) cout << "0";
    }
    for (int i =0; i <n;++i){
        cout << a[i];
        if (i + 1 != n && i ==x)cout << ".";
    }
    return 0;
}