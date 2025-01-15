#include <bits/stdc++.h>

using namespace std;

int main (){

    // n - até q n vai
    // c - quantiodade de cartaz prime
    // m -total de cartas carinbadas

    int album[110];
    int carimbada[110];

    int n,c,m;
    int x,y;
    int resposta;
    cin >> n >> c >> m;

    for (int i = 1; i <= n; i++){
     carimbada[i] = album[i] = 0;

    }

    for (int i = 1; i <= c; i++){
        cin >> x;
        carimbada[x] = 1;

    }

    for (int i = 1; i <= m; i++){

        cin >> y;
        album[y] = 1;

     resposta = 0;
    
    for (int i = 1; i <= n; i++){
        if( album[i] == 0 and carimbada[i] == 1){
            resposta++;
        }


    }
    }


        cout << resposta << endl;
}
