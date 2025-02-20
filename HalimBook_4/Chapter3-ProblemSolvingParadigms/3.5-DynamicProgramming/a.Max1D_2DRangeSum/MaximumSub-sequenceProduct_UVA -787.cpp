#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    int sum = 1;
    int ans = 1;
    int i = 0;
    int j = 1;
    int a[110];
    while (cin >> num) {
        if ( num == -999999) {
            cout << a[i-1] << endl;
            sum = 1;
            ans = 1;
            i = 0;
            j = 1;
            for (int i = 0; i < 110;i++) {
                a[i] = 0;
            }
            continue;
        }

        if (i == 0) {
            a[0] = num;
            i++;
            continue;
        }
        cout << "A*ANT ou NUM" << endl;
        cout << a[i-1]*num<< " " << num << endl;
        cout << "i " << i << endl;
        a[i] = max((a[i-1]*num),a[i-1]);
        i++;
    }

    return 0;
}