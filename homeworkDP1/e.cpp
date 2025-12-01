#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<ll>;
using vs = vector<string>;
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int q; cin >> q;
    ll v = -1;
    int cont = 0;
    ll inp;

    while(q--){
        cin >> inp;
        if(v >= inp){
            cont++;
            inp = v+1;
        }

        v = inp;
    }

    cout << cont nl;
    
    return 0; 
}