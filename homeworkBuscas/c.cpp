#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; 
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int n, m, k; cin >> n >> m >> k;
    vi cl(n), ap(m);
    
    for(auto &x: cl) cin >> x;
    for(auto &x: ap) cin >> x;

    sort(cl.begin(), cl.end());
    sort(ap.begin(), ap.end());

    int l = 0, r = 0, qC = 0, diff;

    while(l < n && r < m){
        diff = cl[l] - ap[r];
        if(abs(diff) <= k){
            qC++; l++; r++;
        }
        else if(cl[l] < ap[r]) l++;
        else r++;
    }
    
    cout << qC nl;

    return 0; 
}