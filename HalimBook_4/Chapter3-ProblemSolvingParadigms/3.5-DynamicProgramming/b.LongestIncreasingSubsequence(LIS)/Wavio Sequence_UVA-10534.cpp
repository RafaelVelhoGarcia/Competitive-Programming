#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while( cin >> n) {
        vector<int>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int>lis(n);
        vector<int>vis(n,0);
        int k = 0,lis_end = -1;
        for (int i = 0; i < n;++i) {
            int pos = lower_bound(lis.begin(),lis.begin() + k,a[i]) - lis.begin();
                lis[pos] = a[i];
                cout << "e" << endl;
                cout << "a[i] " << a[i] << "a[pos] " << lis[pos] << endl;
               if (pos == k) {
                    k = pos+1;
                    lis_end = k;
                }
        }
        int perf = -1;
        while (perf != lis_end){
            vector<int>L(n);
            vector<int>visb(n,0);
            int z = 0;
            for (int i = lis_end; i < n; i++) {
                int pos = upper_bound(L.begin(),L.begin() + z, a[i]) - L.begin();
                if (visb[a[i]] == 0){
                    cout << "b" << endl;
                    cout << "a[i] " << a[i] << "a[pos] " << L[pos] << endl;
                    L[pos] = a[i];
                    visb[a[i]]++;
                    if (pos == z) {
                        z = pos+1;
                    }
                }
            }
            cout << "Z: " << z << " K: " << k << endl;
            perf = z;
            if (perf < lis_end){
                lis_end--;
            }
        }
        cout << perf*2 +1 << endl;
    }

    return 0;
}