#include<bits/stdc++.h>

using namespace std;
vector<int>p;
vector<int> a;   

void print(int i) {
    if (p[i] == -1) {
        cout << a[i] << endl;
        return;
    }
    print(p[i]);
    cout << a[i] << endl;
}

int main() {
    int num;
    while (cin >> num) {
        a.push_back(num);   
    }
    int n = a.size();
    int k =0, lis_end = 0;
    vector<int> L(n,0), L_id(n,0);
    p.assign(n,-1);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(L.begin(),L.begin() + k, a[i]) - L.begin();
        L[pos] = a[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos-1] : -1;
        if (pos == k) {
            k = pos+1;
            lis_end = i;
        }
    }
    cout << L.size() << endl;
    cout <<"-" << endl;
    print(lis_end);
    return 0;
}