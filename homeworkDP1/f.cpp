#include <bits/stdc++.h>
#define nl << '\n'
#define ll long long
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
 
void solve(){
    int n; cin >> n;
    vi dp(n+1, 0);
    vi a(n);

    for(auto &x: a) cin >> x;
    
    for(int i = n-1; i >=0; i--){
        if(i + a[i] < n){
            dp[i] = max(dp[i+1], 1+a[i] + dp[i + a[i] + 1]);
        } else{
            dp[i] = dp[i+1];
        }
    }

    cout << n - dp[0] nl;
}
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
 
    int tc; cin >> tc; while(tc--){
        solve();
    }
 
    return 0; 
}