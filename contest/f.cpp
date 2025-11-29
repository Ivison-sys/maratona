#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
using vd = vector<double>; using vdd = vector<vector<double>>;
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    map<char, bool> isT;
    string s, t; cin >> s >> t;
    
    for(auto &x: t) isT[x] = true;
    
    for(int i = 1; i < s.size(); i++){
        int x = (int) s[i];
        if(x >= 65 && x <= 90){
            if(!isT[s[i-1]]){
                cout << "No" nl;
                return 0;
            }
        }
    }

    cout << "Yes" nl;

    return 0; 
}