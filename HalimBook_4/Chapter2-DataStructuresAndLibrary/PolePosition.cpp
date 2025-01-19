#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    
    while (1) {
        int finale[1010] = {0};
        int vis[1010] = {0};
        
        cin >> n;
        if (n == 0) {
            break;
        }

        int flag = false; 
        for (int i = 0; i < n; i++) {
            int num,p;
            cin >> num >> p;
            int dif = i + p;
            //cout << "dif antes" << dif << endl;

            if (dif < 0) {
                dif = 0;
                flag = true;
            }
            if (dif >= n) {
                dif = n-1;
                flag = true;
            }

            //cout << "dif depois " << dif << endl;



            finale[dif] = num;
            vis[dif]++;
        }
        // verifica se é valido
        for (int i = 0; i< n; i++){
            if (vis[i] >= 2) {
                flag = true;
            }
        }

        if (flag) {
            cout << -1 << endl;
        }
        else {
            for (int i = 0; i < n-1; i++) {
                cout << finale[i] << " ";
            }
            cout << finale[n-1] << endl;
        }
    }
    return 0;
}