#include<bits/stdc++.h>
#define MAX 10010
using namespace std;
int n,l,h;
int seq[MAX];
int marcados[MAX];
int memo[MAX][MAX];

int f(int index, int val){
    cout << index << val << endl;
    cout << "soma até " << memo[index][val] << endl;
    if (memo[index][val] == 0){
        memo[index][val] += f(index-1,val);
    }
    return memo[index][val];
}


int main(){

    for (int i = 1; i <= n; i++){
        for (int j =1 ; j <= n; j++){
            memo[i][j] = -1;
        }
    }


    scanf("%d %d %d" , &n , &l, &h);
    printf("%d %d %d\n" , n , l, h);

    for (int i = 1; i<=n; i++){
        scanf("%d" , &seq[i]);
        printf("%d " , seq[i]);
    }

    printf("\n");
    for (int i = 1; i<=n; i++){
        scanf("%d" , &marcados[i]);
        printf("%d " , marcados[i]);
    }
    printf("\n");

    int last = 0;

    for(int i = 1; i<=n; i++){
        if (marcados[i] == 1){
            last = i;
        }
    }


    cout << last << endl;

    memo[1][seq[1]] = seq[1];

    f(last,-1);


}