#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 

vector<ll> fib_mem;
const ll MOD = 1000000007;

ll fib(int i){
    if(fib_mem[i] != -1) return fib_mem[i];

    if(i == 1) return fib_mem[i] = 1;
    if(i == 2) return fib_mem[i] = 2;

    return fib_mem[i] = (fib(i-1) + fib(i-2)) % MOD;
}

ll valor(ll resp, ll inc){
    return (resp * inc) % MOD;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 

    fib_mem = vector<ll>(200000, -1);

    string pal; 
    cin >> pal;

    for(char c : pal){
        if(c == 'm' || c == 'w'){
            cout << 0 nl; 
            return 0;
        }
    }

    int cont = 1;
    ll resp = 1;

    for(int i = 1; i < pal.size(); i++){
        if(pal[i] == pal[i-1] && (pal[i] == 'u' || pal[i] == 'n')){
            cont++;
        } else {
            resp = valor(resp, fib(cont));
            cont = 1;
        }
    }

    resp = valor(resp, fib(cont));

    cout << resp nl;
    return 0; 
}
