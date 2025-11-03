#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int qPares, qConsultas; cin >> qPares >> qConsultas;
    vector<pair<int, int>> ordens (qPares);
    int sz = qPares+qPares;
    vi v; v.reserve(sz);
    vi contador(sz, 0), psum(sz + 1, 0);

    for(auto &x: ordens){
        cin >> x.first >> x.second;
        x.second++;
        v.push_back(x.first); v.push_back(x.second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(auto [l, r]: ordens){
        int pos1 = lower_bound(v.begin(), v.end(), l) - v.begin();
        int pos2 = lower_bound(v.begin(), v.end(), r) - v.begin();
        contador[pos1]++; contador[pos2]--;
    }

    for(int i = 0; i < sz; i++){
        psum[i+1] = contador[i] + psum[i]; 
    }
    
    while(qConsultas--){
        ll pos;
        cin >> pos;
        cout << psum[(upper_bound(v.begin(), v.end(), pos) - v.begin())] nl;
    }

    return 0; 
}