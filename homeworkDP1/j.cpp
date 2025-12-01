#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>;

vll fib_mem;

ll fib(int i){
    if(fib_mem[i] != -1){
        return fib_mem[i];
    }
    if(i == 1){
        return fib_mem[i] = 1;
    }
    if(i == 2) return fib_mem[i] = 2;

    return fib_mem[i] = (fib(i-1) + fib(i-2)) % 1000000007;
}

ll valor(ll resp, ll inc){
   return (resp * inc) % 1000000007;
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 

    fib_mem = vll(200000, -1);

    string pal; cin >> pal;
    vi sec; sec.reserve(pal.size());

    int cont = 1;
    ll resp = 1;
    
    for(int i = 1; i < pal.size(); i++){
        if(pal[i] == 'w' || pal[i] == 'm'){
            cout << 0 nl; 
            return 0;
        }

        if(pal[i] == pal[i-1] && pal[i] == 'u'){
            cont++;
        } else if(pal[i] == pal[i-1] && pal[i] == 'n'){
            cont++;
        } else{
            if(cont > 1){
                resp = valor(resp, fib(cont));
                cont = 1;
            }
        }
    }

    
    resp = valor(resp, fib(cont));

    cout << resp nl;
    return 0; 
}