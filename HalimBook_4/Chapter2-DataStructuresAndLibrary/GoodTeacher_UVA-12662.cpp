#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    string all[110];
    vector<int>know;
    for (int i = 1; i <=n;i++) {
        cin >> all[i];
        if (all[i] != "?") {
            cout << all[i]<< endl;
            know.push_back(i);
        }
    }
    int q;
    cin>>q;
    for (int i= 0; i < q; i++) {
        int pos;
        cin >> pos;
        int ant = pos -1;
        int nexxt = pos+1;
        if (all[pos] != "?") {
            cout << all[pos] << endl;
        }
        // case close
        for (int j = 0; j< know.size(); j++ ) {
            int temp = 0;
            int ant_x,nexxt_x;
            if (know[j] == ant){
                ant_x = know[j];
                cout << "N"<<endl;
                cout << know[j]<<endl;
                temp++;
            }
            if (know[j] == nexxt) {
                cout << "N"<<endl;
                cout << know[j]<<endl;
                nexxt_x = know[j];
                temp++;
            }
            if (temp == 2) {
                cout <<"middle of"<<all[ant_x]<<" and "<< all[nexxt_x] << endl;
            }
            if (temp == 1) {
                if(all[pos-1] != "?") {
                    cout << "left of " << all[pos-1] << endl;
                    break;
                }
            }
            if (temp == 1) {
                if(all[pos+1] != "?") {
                    cout << "right of " << all[pos+1] << endl;
                    break;
                }
            }
        }
        // case far
        int dist = 0;
        string a;
        for (int j = pos; ; j++ ) {
           if (all[j] !="?") {
                dist = j;
                a = all[i];
                break;
           }
        }
        if (all[pos-dist] != "?") {
            cout << "middle of "<<all[abs(pos-dist)]<<" and "<<a<<endl;
            continue;
        }
    }    
    return 0;
}