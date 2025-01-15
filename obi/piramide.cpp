#include <bits/stdc++.h>
#define MAX 104
using namespace std;

int main(){
    int n;
    int matriz[MAX][MAX];
    cin >> n;

    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j<= n ; j++){
            matriz[i][j] = 1;
        }
    }

    //printar matriz
     /*for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j<= n ; j++){
            int a = matriz[i][j];
            cout << a ;
        }
        cout << endl;
    }
*/

      int i = 2;
        int j = 2;
        int fi = n;
        int fj = n;
     int cont = 1;
    while ( cont <= n/2 +1){
        cont += 1;
        fi--;
        fj--;
        for (int l = i; l <= fi; l++){
            for(int c = j; c <= fj; c++){
                //cout << "cont é " << cont << endl;
                matriz[l][c] = cont;
            }

        }
        i++;
        j++;
    }

    //cout << "nova matriz vem ai:" << endl;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j<= n ; j++){
            int a = matriz[i][j];
            cout << a <<" ";
        }
        cout << endl;
    }



}
