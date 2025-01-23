#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (1){
        cin >> n;
        if(n == 0) {
            break;
        }
        string resposta[60];
        queue<int> fila;
        for (int i = 0; i < n; i++) {
            fila.push(i);
        }
        for (int i = 0; i < n; i++) {
            string s1,s2;
            cin >> s1 >> s2;
            int len = s2.size() -1;
            for (int j = 0; j < len; j++) {
                fila.push(fila.front());
                fila.pop();
            }
            resposta[fila.front()] = s1;
            fila.pop();
        }
        cout << resposta[0];
        for (int i = 1; i < n; i++) {
            cout << " " << resposta[i];
        }
        cout << endl;
    }
    return 0;
}