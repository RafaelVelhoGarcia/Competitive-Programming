#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int num;
    while (true) {
        cin >> n;
        if (n == 0) break;
        int maxsum = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> num;
            sum += num;
            maxsum = max(maxsum,sum);
            if (sum < 0) sum = 0;   
        }
        if (maxsum <= 0) {
            cout << "Losing streak." << endl;
        }
        else {
            cout << "The maximum winning streak is " << maxsum << "." << endl;
        }
    }

    return 0;
}