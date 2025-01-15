#include <bits/stdc++.h>
#define MAX 1004


using namespace std;


typedef pair<int,int> pii;

int custo[MAX];

vector<bool> marca;

vector <pii> area[MAX];

priority_queue <pii,vector<pii> , greater<pii>> q;

int X1[MAX], X2[MAX], Y1[MAX], Y2[MAX];

int xi,yi,xf,yf;

void dijkstra(int S){
    q.push({0,S});
    marca[S] = false;

    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();

        if (d > custo[u]) continue;

        for (auto [v,c] : area[u])
            if ( custo[v] > custo[u] + c)
            {

                custo[v] = custo[u] + c;
                q.push({custo[v],v});
            }



    }

}



int main(){
    int N;
    cin >> xi >> yi >> xf >> yf;
    cin >> N;


    for (int i = 0 ; i < N ; i++){

        cin >> X1[i] >> Y2[i] >> X2[i] >> Y2[i];
        }
    
    marca = vector<bool> (N+2,false);
    X1[N] = X2[N] = xi;
    Y1[N] = Y2[N] = yi;
    X1[N+1] = X2[N+1] = xf;
    Y1[N+1] = Y2[N+1] = yf;

    //monta o grafo:
    for (int i = 0 ; i <= N+1 ; i++){
        for(int j = i; j <= N+2 ; j++){
            int dx = max(0,max(X1[i],X1[j]) - min(X2[j],X2[i]));
            int dy = max(0,max(Y1[i],Y1[j]) - min(Y2[i],Y2[j]));
            int c = dx + dy;

            area[i].push_back({j,c});
            area[j].push_back({i,c});
        }
    }

    q.push( {0,N} );
  while ( not q.empty() ){
    auto p = q.top(); q.pop();
    int c = p.first;
    int a = p.second;
    if ( not marca[a] ){
      custo[a] = c;
      marca[a] = true;
      for ( auto e : area[a] ){
        int b = e.first;
        int d = e.second;
        if  ( not marca[b] )
          q.push( {c+d,b} );
      }
    }
  }

    cout << custo[N+1] << endl;
    return 0;
    }



