#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; 
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int a[10100] = {0}; 
        vector<int> va, vb, vc; 
        vector<int> vs(3); 
    
        for (int i = 0; i < 3; i++) {
            cin >> vs[i]; 
            for (int j = 0; j < vs[i]; j++) {
                int num;
                cin >> num;
                a[num]++; 
                if (i == 0) va.push_back(num);
                if (i == 1) vb.push_back(num);
                if (i == 2) vc.push_back(num);
            }
        }
        vector<vector<int>> matriz = {va, vb, vc};
        vector<int> contadores(3, 0);
        int maior = 0;
        for (int i = 0; i < 3; i++) {
            for (int num : matriz[i]) {
                if (a[num] == 1) { 
                    contadores[i]++;
                }
            }
            maior = max(maior, contadores[i]); 
        }
        for (int i =0; i < 3; i++){
        sort(matriz[i].begin(),matriz[i].end());
        }
        cout << "Case #" << c << ":" << endl;
        for (int i = 0; i < 3; i++) {
            if (contadores[i] == maior) { 
                cout << i+1 <<" ";
                cout << contadores[i];
                for (int num : matriz[i]) {
                    if (a[num] == 1) { 
                        cout << " " << num;
                }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
