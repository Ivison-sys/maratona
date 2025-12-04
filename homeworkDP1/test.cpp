#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
const int INF = 1e9;
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    vi p = {4};

    cout << lower_bound(p.begin(), p.end(), 3) - p.begin() - 1 nl;
    
    return 0; 
}