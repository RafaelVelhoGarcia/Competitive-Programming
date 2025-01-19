#include <bits/stdc++.h>

using namespace std;

int main(){
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int ls[1000100];
        int rs[1000100];
        int s,b,l,r;
        cin >> s >> b;
        if (s == 0 && b == 0){
            break;
        }
        for (int i = 0; i <= s; i++) {
            ls[i] = i - 1;
            rs[i] = i + 1;
        }
        for (int i =0 ; i < b;i++) {
            cin >> l >> r;
            if (ls[l] < 1) {
                cout << "* ";
            }
            else {
                cout << ls[l] << " ";
            }
            if (rs[r] > s) {
                cout << "*"<< endl;
            }
            else {
                cout << rs[r] << endl;
            }

            ls[rs[r]] = ls[l];
            rs[ls[l]] = rs[r];
            
        }

        cout << "-" << endl;
    }
    return 0;
}