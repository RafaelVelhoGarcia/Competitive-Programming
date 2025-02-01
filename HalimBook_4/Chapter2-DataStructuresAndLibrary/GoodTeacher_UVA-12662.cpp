#include <bits/stdc++.h>

using namespace std;
char s[110][5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++) {
        cin >> s[i];
    }

    int m,a,r,l;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        r = a; l = a;
        if (s[a][0] != '?') {
            cout << s[a] << endl;
            continue;
        }
        else {
            while(1) {
                if (r > 1) r--;
                if (l < n) l++;
                if (s[l][0] != '?' && s[r][0] != '?') {
                    cout << "middle of "<< s[r] << " and "<<s[l] << endl;
                    break;
                }
                else if (s[l][0] != '?' && s[r][0] == '?') {
                    for (int j = 0; j < l - a;j++)
                        cout << "left of ";
                    cout << s[l] << endl;
                    break;
                }
                else if (s[l][0] == '?' && s[r][0] != '?'){
                    for (int j = 0; j < a - r;j++)
                        cout << "right of ";
                    cout << s[r] << endl;
                    break;
                }
            }
        }
    }
        
    return 0;
}