#include <bits/stdc++.h>
#define MAX 1004

using namespace std;

int l,c;
int matriz[MAX][MAX];


int cond (int atual,int i , int j){
    if (matriz[1][1] + atual <= matriz[1][j] + matriz[i][1])
        return 1;
    return 0;
}

int main(){
    vector<pair<int,int>> comb;
    int soma = 0;
    cin >> l >> c;

    for (int i = 1; i <= l ; i++){
        for (int j = 1; j <= c; j++){
            cin >> matriz[i][j];
            comb.push_back({i,j});
        }
    }

    for (int i = 1; i <= l ; i++){
        for (int j = 1; j <= c; j++){
            int atual = matriz[i][j];
            soma += cond(atual,i,j); 
        }
    }

    if (soma == l*c){
        int res = 0;
        soma = 0;
        // individuais:
        for (int i = 1; i <= 2 ; i++){
            for (int j = 1; j <= 2; j++){
                int atual = matriz[i][j];
                soma += cond(atual,i,j); 
            }
        if (soma == 4){
            res++;
        }

        for (int i = 0; i < l*c; i++){
            auto [u, v] = comb[i];
            for (int k = i; k < u; k++){
                for (int k = i; k < u; k++){
                int atual = matriz[i][j];
                soma += cond(atual,u,v);

            }

          }


        }


    }
    cout << "essa é a resp = " << res << endl;
    }

    else{
        cout << 0 << endl;
    }
    return 0;

}

