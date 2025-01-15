#include <bits/stdc++.h>

using namespace std;

//somente 2,10 e 4se repetem sendo descartado o 4 pq ele se repete em sequencia
// 1 - acha numeros que aparecem mais de uma vez
// 2 - pega o que mais aparece e marca todas as posicoes dele
// 3 - faca com que ele nao apareca em sequencia com (segundo -> ultimo da lista) maior até dar certo

int main()
{
    
    int n;
    scanf("%d" , &n);
    int quantAparece[510];
    int posdeultaparicao[510];
    int lista[510];
    int listaEntrada[510];
    



    vector <int> repetidos;
    
    for (int i = 1 ; i < 510 ; i++){
        quantAparece[i] = 0; 
         posdeultaparicao[i] = 0;
        lista[i] = 0;
        listaEntrada[i] = 0;
    }
    

    for (int i = 1 ; i <= n ; i++){
        int entrada;
        cin >> entrada;

        listaEntrada[i] = entrada;
        ++quantAparece[entrada];
        int quantqapareceu = quantAparece[entrada];
        cout << quantqapareceu << endl;
         if (quantqapareceu == 1){
              
            }
        
        
        if (quantAparece[entrada] > 1){
            
            //cout << quantAparece[10] << endl;
            //cout<< "atumalaca" << endl;
            cout << "numero referdio : "<< entrada << endl;
            cout << "ultima no " << i << endl;
            
            repetidos.push_back(entrada);

            lista[i] = entrada;
            posdeultaparicao[i]++;
        } 
    }
    
       for (int i = 1 ; i <= n ; i++){
        
        cout << lista[i] << " "; 
            
            
        }
     
        cout << "dps" << endl; 
    

        
         for (int i = 1 ; i <= n ; i++){
        
        cout << repetidos[i] << " "; 
            
            
        }
    
        cout << endl;
        cout << "acabou" << endl;
    
    
    for (int i = 1 ; i <= n ; i++){
        
        
        for (int j = 0 ; j < repetidos.size() ; j++){
        cout << listaEntrada[i] << " e " << repetidos[j]  << endl;
            
        if (listaEntrada[i] == repetidos[j] ){
            cout << "atumalaca" << endl;
            lista[i] = repetidos[i];
        }
        }
            
        }
     

      for (int i = 1 ; i <= n ; i++){
        
        cout << lista[i] << " "; 
            
            
        }
     
        } 


 

    
    
    
    
    
    
    

    
    

