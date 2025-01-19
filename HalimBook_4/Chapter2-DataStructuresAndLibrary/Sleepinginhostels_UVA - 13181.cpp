#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    while (getline(cin, s)) {
        vector<int> gap;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') { 
                gap.push_back(i); 
            }
        }
        int maior = 0;
        for (int i = 1; i < gap.size(); i++) {
            int dif = gap[i] - gap[i-1] - 1;
            maior = max(maior, (dif - 1)/2);
        }
        maior = max(maior,gap[0] - 1); 
        maior = max(maior, n - gap[gap.size() - 1] - 2); 

        cout << maior << endl; 
    }

    return 0;
}
