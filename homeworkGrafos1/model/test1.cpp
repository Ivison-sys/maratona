#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    for(int i = 200; i <= 400; i++){
        if(i%5 == 4 && i%7 == 6 && i%11 == 0){
            cout << i nl;
        }
    }
    
    return 0; 
}