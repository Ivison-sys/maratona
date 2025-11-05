#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int n, x; cin >> n >> x;
    vi pesos; pesos.reserve(n);
    int g = 0, p;

    for(int i = 0; i < n; i++){
        cin >> p;
        if(p >= x) g++;
        else pesos.push_back(p);
    }

    sort(pesos.begin(), pesos.end());
    int l = 0, r = pesos.size() - 1;

    while(r >= l){
        if(r == l){
            g++; r--;
        } else if(pesos[l] + pesos[r] <= x){
            g++; l++; r--;
        } else{
            g++; r--;
        }
    }

    cout << g nl;
    
    return 0; 
}