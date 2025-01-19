#include <bits/stdc++.h>

using namespace std;
int a[1000101];
int main() {
    int n,num,ant;
    vector<int> resposta;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > ant){
            resposta.push_back(num);
            ant = num;
        }
    }           
    cout << resposta.size() << endl;
    for (int i =0; i< resposta.size();i++) {
        cout << resposta[i] <<" ";
    }
    cout << endl;
    return 0;
}