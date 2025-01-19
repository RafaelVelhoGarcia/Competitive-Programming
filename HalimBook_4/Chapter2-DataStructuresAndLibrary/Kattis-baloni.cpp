#include <bits/stdc++.h>

using namespace std;
int a[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    
    int num;
    int cont = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (a[num + 1] > 0) {
            a[num+1]--;
        } else {
            cont++;
        }
        a[num]++;
    }
    cout << cont << endl;
    return 0;
}