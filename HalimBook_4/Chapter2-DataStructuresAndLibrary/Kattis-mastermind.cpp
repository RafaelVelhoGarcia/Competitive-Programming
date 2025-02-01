#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string a,b;
    cin >> a;
    cin >> b;
    int vis[210] = {0};
    int saldo[1000] = {0};
    // find r:
    int r = 0;
    for (int i = 0; i < n; i++){
        int num = (int) a[i];
        saldo[num]++;
        if (a[i] == b[i]) {
            vis[i] = 1;
            r++;
            saldo[num]--;
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++ ) {
        if (vis[i]) continue;
        
        int num = (int) b[i];
        if (saldo[num] > 0){
            saldo[num]--;
            s++;
        } 
    }
    
    cout << r << " " << s << endl;
    return 0;
}