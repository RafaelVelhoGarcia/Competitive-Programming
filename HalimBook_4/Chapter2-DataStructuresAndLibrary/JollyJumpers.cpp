#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int a[3010];
        int b[3010];
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            b[i] = 0;
        }


        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        // calcula diff
        for (int i = 0; i < n-1; i++) {
            int diff = abs(a[i] - a[i+1]);
            b[diff] = 1;
        }

        int cont = 0;
        for (int i = 1; i < n; i++) {
            if (b[i] == 0) {
                cont++;
                break;
            }
        }

        if (cont == 0) {
            cout << "Jolly" << endl;
        }
        else {
            cout << "Not jolly" << endl;
        }
    }

    return 0;
}