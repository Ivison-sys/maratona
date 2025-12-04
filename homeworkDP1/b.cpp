#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<long long>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
const ll INFPeso = 1e15; 

struct Item {
    int valor; 
    ll peso; 
};

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qI; 
    ll peso; 
    cin >> qI >> peso;
    
    vector<Item> itens(qI);
    int maxValorPossivel = 0;
    for(int i = 0; i < qI; ++i) {
        cin >> itens[i].peso >> itens[i].valor; 
        maxValorPossivel += itens[i].valor;
    }
    
    vll dp(maxValorPossivel + 1, INFPeso);
    dp[0] = 0;
    
    for(int i = 0; i < qI; i++){
        int valorItem = itens[i].valor; 
        ll pesoItem = itens[i].peso;         
        for(int v = maxValorPossivel; v >= valorItem; v--){
            if(dp[v - valorItem] != INFPeso) {
                dp[v] = min(dp[v], dp[v - valorItem] + pesoItem);
            }
        }
    }
    
    ll resultado = 0;
    for(int v = maxValorPossivel; v >= 0; v--){
        if(dp[v] <= peso){
            resultado = v;
            break; 
        }
    }

    cout << resultado nl;
    
    return 0; 
}