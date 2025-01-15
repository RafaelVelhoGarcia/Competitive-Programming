#include <bits/stdc++.h>
#include<cstring>
#include <set>
using namespace std;

// 2 5 8 11 14
// 2 + I*3
//0 3 6

set<int> C;
set<int> E;
set<int> U;
set<int> P;


int main()
{
    
    int num = 0;
    char entrada[160];
    pair <int,char> adj;
    cin>> entrada;
    
    for (int i = 0; i < 160; i += 3 ){
        int var = 2 + i*3; 
        
        char a = entrada[i];
        char b = entrada[i+1];
        char c = entrada[var];
        
        string xou = string(1,a) + string(1,b);
        
        for (char c : xou){
        num = num * 10 + (c - '0'); 
        }
        
        switch (c){
            
            case 'C' :
            case 'E' :
            case 'U' :
            case 'P' :
            
            
            
            
        }
        
        
        
        
        
    }
    
    
    
    
    return 0;
}

