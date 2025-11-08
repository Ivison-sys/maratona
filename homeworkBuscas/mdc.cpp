#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    ll a, b; cin >> a >> b;
    ll v1 = a, v2 = b;
    ll aux;

    while(a>0 && b != 0){
        if(a > b){
            aux = a;
            a = b;
            b = aux;
        }
        b = b % a;
    }
    cout << "MDC(" << v1 << ", " << v2 << ") = " << a nl;
    
    return 0; 
}