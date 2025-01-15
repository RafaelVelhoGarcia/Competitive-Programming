#include <bits/stdc++.h>

using namespace std;

int main(){
    int cont = 0;
    int n;

    int md[32];
    int me[32];

    scanf("%d" , &n);

    for (int i = 0 ; i <= 32 ; i++){
        me[i] = 0;
        md[i] = 0;
    }

    for (int i = 1 ; i <= n ; i++){

        int m ;
        char l;

        scanf("%d %c" , &m , &l);
        //cout << l << endl;

        if ( l == 'E'){
            me[m-30]++;

        }

        else {
            md[m-30]++;
        }
        
    }
    
    for (int i = 0 ; i <= 32 ; i++){
        if (me[i] >= 1 && md[i] >= 1){
            if (me[i] > md[i]){
                cont += md[i];
            }
            else {
                cont += me[i];
                
        }
    }

        
    }


    cout << cont << endl;




}