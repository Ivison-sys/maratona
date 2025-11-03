#include <bits/stdc++.h>
#define nl << '\n'
#define ll long long
using namespace std; 
using vi = vector<int>;
 
void solve(){
    int n, q; cin >> n >> q;
    vi candies(n);
    vector<ll> psum(n+1);
    for(auto &x: candies){
        cin >> x;
    }

    sort(candies.rbegin(), candies.rend());

    for(int i = 0; i < n; i++){
        psum[i+1] = psum[i] + candies[i];
    }

    ll c;
    while(q--){
        cin >> c;
        if(c > psum[n]){
            cout << -1 nl;
            continue;
        }
        else{
            cout << lower_bound(psum.begin(), psum.end(), c) - psum.begin() nl;
        }

    }
    

}
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
 
    int tc; cin >> tc; while(tc--){
        solve();
    }
 
    return 0; 
}