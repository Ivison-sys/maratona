#include <bits/stdc++.h> 
#define nl << '\n' 
#define ll long long 
using namespace std; 
using vi = vector<int>; using vll = vector<vector<long long>>;
using vs = vector<string>; using vii = vector<vector<int>>;
 
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int d = 8;
    int cont = 1;
    int rep = 0;
    for(int i = 1; i < d; i++){
        for(int z = 1; z < d; z++){
            for(int w = 1; w < d; w++){
                if(i+z+w == d){
                    cout << cont << ": " << i << " + " << z << " + " << w << " = " << d nl;
                    cont++; 
                }
            }
        }
    }
    
    return 0; 
}